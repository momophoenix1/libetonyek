/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libetonyek project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <cassert>

#include <boost/make_shared.hpp>
#include <boost/optional.hpp>

#include <librevenge/librevenge.h>

#include "IWORKPath.h"
#include "IWORKStyles.h"
#include "IWORKTransformation.h"
#include "IWORKTypes.h"
#include "KEYText.h"
#include "KEYTypes.h"

using boost::optional;

using std::string;

namespace libetonyek
{

struct KEYText::Paragraph
{
  IWORKStyleContext m_styleContext;
  IWORKStylePtr_t style;
  IWORKObjectList_t objects;

  explicit Paragraph(const IWORKStyleContext &styleContext);
};

namespace
{

librevenge::RVNGString makeColor(const IWORKColor &color)
{
  // TODO: alpha

  const unsigned r = color.red * 256 - 0.5;
  const unsigned g = color.green * 256 - 0.5;
  const unsigned b = color.blue * 256 - 0.5;

  librevenge::RVNGString str;
  str.sprintf("#%.2x%.2x%.2x", r, g, b);

  return str;
}

void fillCharPropList(librevenge::RVNGPropertyList &props, const IWORKCharacterStyle &style)
{
  if (style.getItalic())
    props.insert("fo:font-style", "italic");
  if (style.getBold())
    props.insert("fo:font-weight", "bold");
  if (style.getUnderline())
    props.insert("style:text-underline-type", "single");
  if (style.getStrikethru())
    props.insert("style:text-line-through-type", "single");
  if (style.getOutline())
    props.insert("style:text-outline", true);

  const optional<IWORKCapitalization> capitalization = style.getCapitalization();
  if (capitalization)
  {
    if (IWORK_CAPITALIZATION_SMALL_CAPS == get(capitalization))
      props.insert("fo:font-variant", "small-caps");
  }

  const optional<string> fontName = style.getFontName();
  if (fontName)
    props.insert("style:font-name", librevenge::RVNGString(get(fontName).c_str()));

  const optional<double> fontSize = style.getFontSize();
  if (fontSize)
    props.insert("fo:font-size", pt2in(get(fontSize)));

  const optional<IWORKColor> fontColor = style.getFontColor();
  if (fontColor)
    props.insert("fo:color", makeColor(get(fontColor)));
}

IWORKStylePtr_t makeEmptyStyle()
{
  optional<string> dummy;
  return boost::make_shared<IWORKStyle>(IWORKPropertyMap(), dummy, dummy);
}

librevenge::RVNGPropertyList makeCharPropList(const IWORKStylePtr_t &style, const IWORKStyleContext &context)
{
  librevenge::RVNGPropertyList props;

  // Even if there is no character style for the span, there might still
  // be attributes inherited from the paragraph style through context.
  // We use an empty style so these can be picked up.
  fillCharPropList(props, IWORKCharacterStyle(bool(style) ? style : makeEmptyStyle(), context));

  return props;
}

librevenge::RVNGPropertyList makeParaPropList(const IWORKStylePtr_t &style, const IWORKStyleContext &context)
{
  librevenge::RVNGPropertyList props;

  if (bool(style))
  {
    const IWORKParagraphStyle paraStyle(style, context);

    const optional<IWORKAlignment> alignment(paraStyle.getAlignment());
    if (bool(alignment))
    {
      switch (get(alignment))
      {
      case IWORK_ALIGNMENT_LEFT :
        props.insert("fo:text-align", "left");
        break;
      case IWORK_ALIGNMENT_RIGHT :
        props.insert("fo:text-align", "right");
        break;
      case IWORK_ALIGNMENT_CENTER :
        props.insert("fo:text-align", "center");
        break;
      case IWORK_ALIGNMENT_JUSTIFY :
        props.insert("fo:text-align", "justify");
        break;
      }
    }

    const optional<IWORKTabStops_t> &tabStops = paraStyle.getTabs();
    if (bool(tabStops))
    {
      for (IWORKTabStops_t::const_iterator it = get(tabStops).begin(); get(tabStops).end() != it; ++it)
      {
        librevenge::RVNGPropertyList tab;
        tab.insert("style:position", pt2in(it->pos));
        tab.insert("style:type", "left");
      }
    }
  }

  return props;
}

}

namespace
{

class TextSpanObject : public IWORKObject
{
public:
  TextSpanObject(const IWORKStylePtr_t &style, const IWORKStyleContext &styleContext, const string &text);

private:
  virtual void draw(librevenge::RVNGPresentationInterface *painter);

private:
  const IWORKStylePtr_t m_style;
  const IWORKStyleContext m_styleContext;
  const string m_text;
};

TextSpanObject::TextSpanObject(const IWORKStylePtr_t &style, const IWORKStyleContext &styleContext, const string &text)
  : m_style(style)
  , m_styleContext(styleContext)
  , m_text(text)
{
}

void TextSpanObject::draw(librevenge::RVNGPresentationInterface *const painter)
{
  const librevenge::RVNGPropertyList props(makeCharPropList(m_style, m_styleContext));
  painter->openSpan(props);
  painter->insertText(librevenge::RVNGString(m_text.c_str()));
  painter->closeSpan();
}

}

namespace
{

class TabObject : public IWORKObject
{
private:
  virtual void draw(librevenge::RVNGPresentationInterface *painter);
};

void TabObject::draw(librevenge::RVNGPresentationInterface *const painter)
{
  painter->openSpan(librevenge::RVNGPropertyList());
  painter->insertTab();
  painter->closeSpan();
}

}

namespace
{

class LineBreakObject : public IWORKObject
{
public:
  explicit LineBreakObject(const IWORKStyleContext &styleContext);

private:
  virtual void draw(librevenge::RVNGPresentationInterface *painter);

private:
  const IWORKStyleContext m_styleContext;
};

LineBreakObject::LineBreakObject(const IWORKStyleContext &styleContext)
  : m_styleContext(styleContext)
{
}

void LineBreakObject::draw(librevenge::RVNGPresentationInterface *const painter)
{
  painter->closeParagraph();
  const librevenge::RVNGPropertyList props(makeParaPropList(IWORKStylePtr_t(), m_styleContext));
  painter->openParagraph(props);
}

}

namespace
{

class TextObject : public IWORKObject
{
public:
  TextObject(const IWORKGeometryPtr_t &boundingBox, const KEYText::ParagraphList_t &paragraphs, bool object, const IWORKTransformation &trafo);

private:
  virtual void draw(librevenge::RVNGPresentationInterface *painter);

private:
  const IWORKGeometryPtr_t m_boundingBox;
  const KEYText::ParagraphList_t m_paragraphs;
  const bool m_object;
  const IWORKTransformation m_trafo;
};

TextObject::TextObject(const IWORKGeometryPtr_t &boundingBox, const KEYText::ParagraphList_t &paragraphs, const bool object, const IWORKTransformation &trafo)
  : m_boundingBox(boundingBox)
  , m_paragraphs(paragraphs)
  , m_object(object)
  , m_trafo(trafo)
{
}

void TextObject::draw(librevenge::RVNGPresentationInterface *const painter)
{
  librevenge::RVNGPropertyList props;

  double x = 0;
  double y = 0;
  m_trafo(x, y);
  props.insert("svg:x", pt2in(x));
  props.insert("svg:y", pt2in(y));

  if (bool(m_boundingBox))
  {
    double w = m_boundingBox->naturalSize.width;
    double h = m_boundingBox->naturalSize.height;
    m_trafo(w, h, true);

    props.insert("svg:width", pt2in(w));
    props.insert("svg:height", pt2in(h));
  }

  IWORKPath path;
  path.appendMoveTo(0, 0);
  path.appendLineTo(0, 1);
  path.appendLineTo(1, 1);
  path.appendLineTo(1, 0);
  path.appendClose();
  path *= m_trafo;

  props.insert("svg:d", path.toWPG());

  if (m_object)
    painter->startTextObject(props);

  for (KEYText::ParagraphList_t::const_iterator it = m_paragraphs.begin(); m_paragraphs.end() != it; ++it)
  {
    const librevenge::RVNGPropertyList paraProps(makeParaPropList((*it)->style, (*it)->m_styleContext));
    painter->openParagraph(paraProps);
    drawAll((*it)->objects, painter);
    painter->closeParagraph();
  }

  if (m_object)
    painter->endTextObject();
}

}

KEYText::KEYText(const bool object)
  : m_styleContext()
  , m_layoutStyle()
  , m_paragraphs()
  , m_currentParagraph()
  , m_lineBreaks(0)
  , m_object(object)
  , m_boundingBox()
{
}

KEYText::Paragraph::Paragraph(const IWORKStyleContext &styleContext)
  : m_styleContext(styleContext)
  , style()
  , objects()
{
}

void KEYText::setLayoutStyle(const IWORKStylePtr_t &style)
{
  assert(!m_layoutStyle);

  m_layoutStyle = style;
  m_styleContext.push();
  m_styleContext.set(style);
}

const IWORKGeometryPtr_t &KEYText::getBoundingBox() const
{
  return m_boundingBox;
}

void KEYText::setBoundingBox(const IWORKGeometryPtr_t &boundingBox)
{
  m_boundingBox = boundingBox;
}

void KEYText::openParagraph(const IWORKStylePtr_t &style)
{
  assert(!m_currentParagraph);

  m_currentParagraph.reset(new Paragraph(m_styleContext));
  m_currentParagraph->style = style;
  m_styleContext.push();
  m_styleContext.set(style);
}

void KEYText::closeParagraph()
{
  assert(bool(m_currentParagraph));

  m_paragraphs.push_back(m_currentParagraph);
  m_currentParagraph.reset();
  m_styleContext.pop();
}

void KEYText::insertText(const std::string &text, const IWORKStylePtr_t &style)
{
  assert(bool(m_currentParagraph));

  const IWORKObjectPtr_t object(new TextSpanObject(style, m_styleContext, text));
  m_currentParagraph->objects.push_back(object);
}

void KEYText::insertTab()
{
  assert(bool(m_currentParagraph));

  const IWORKObjectPtr_t object(new TabObject());
  m_currentParagraph->objects.push_back(object);
}

void KEYText::insertLineBreak()
{
  assert(bool(m_currentParagraph));

  ++m_lineBreaks;
}

const IWORKStylePtr_t &KEYText::getLayoutStyle() const
{
  return m_layoutStyle;
}

const KEYText::ParagraphList_t &KEYText::getParagraphs() const
{
  return m_paragraphs;
}

bool KEYText::isObject() const
{
  return m_object;
}

void KEYText::insertDeferredLineBreaks()
{
  assert(bool(m_currentParagraph));

  if (0 < m_lineBreaks)
  {
    const IWORKObjectPtr_t object(new LineBreakObject(m_currentParagraph->m_styleContext));
    m_currentParagraph->objects.insert(m_currentParagraph->objects.end(), m_lineBreaks, object);
    m_lineBreaks = 0;
  }
}

bool KEYText::empty() const
{
  return m_paragraphs.empty();
}

IWORKObjectPtr_t makeObject(const KEYTextPtr_t &text, const IWORKTransformation &trafo)
{
  const IWORKObjectPtr_t object(new TextObject(text->getBoundingBox(), text->getParagraphs(), text->isObject(), trafo));
  return object;
}

}

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
