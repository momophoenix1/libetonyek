/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libetonyek project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "PAG1Parser.h"
#include "IWORKXMLContexts.h"
#include "IWORKToken.h"
#include "PAGCollector.h"
#include "PAG1Token.h"
#include "PAG1XMLContextBase.h"

using boost::optional;

namespace libetonyek
{

namespace
{

unsigned getVersion(const int token)
{
  switch (token)
  {
  case PAG1Token::VERSION_STR_4 :
    return 4;
  }

  return 0;
}

}

namespace
{

class FootersElement : public PAG1XMLElementContextBase
{
public:
  explicit FootersElement(PAG1ParserState &state);

private:
  virtual IWORKXMLContextPtr_t element(int name);
};

FootersElement::FootersElement(PAG1ParserState &state)
  : PAG1XMLElementContextBase(state)
{
}

IWORKXMLContextPtr_t FootersElement::element(int)
{
  // TODO: parse
  return IWORKXMLContextPtr_t();
}

}

namespace
{

class HeadersElement : public PAG1XMLElementContextBase
{
public:
  explicit HeadersElement(PAG1ParserState &state);

private:
  virtual IWORKXMLContextPtr_t element(int name);
};

HeadersElement::HeadersElement(PAG1ParserState &state)
  : PAG1XMLElementContextBase(state)
{
}

IWORKXMLContextPtr_t HeadersElement::element(int)
{
  // TODO: parse
  return IWORKXMLContextPtr_t();
}

}

namespace
{

class StylesheetElement : public PAG1XMLElementContextBase
{
public:
  explicit StylesheetElement(PAG1ParserState &state);

private:
  virtual IWORKXMLContextPtr_t element(int name);
};

StylesheetElement::StylesheetElement(PAG1ParserState &state)
  : PAG1XMLElementContextBase(state)
{
}

IWORKXMLContextPtr_t StylesheetElement::element(int)
{
  // TODO: parse
  return IWORKXMLContextPtr_t();
}

}

namespace
{

class SectionPrototypesElement : public PAG1XMLElementContextBase
{
public:
  explicit SectionPrototypesElement(PAG1ParserState &state);

private:
  virtual IWORKXMLContextPtr_t element(int name);
};

SectionPrototypesElement::SectionPrototypesElement(PAG1ParserState &state)
  : PAG1XMLElementContextBase(state)
{
}

IWORKXMLContextPtr_t SectionPrototypesElement::element(int)
{
  // TODO: parse
  return IWORKXMLContextPtr_t();
}

}

namespace
{

class MetadataElement : public PAG1XMLElementContextBase
{
public:
  explicit MetadataElement(PAG1ParserState &state);

private:
  virtual IWORKXMLContextPtr_t element(int name);
};

MetadataElement::MetadataElement(PAG1ParserState &state)
  : PAG1XMLElementContextBase(state)
{
}

IWORKXMLContextPtr_t MetadataElement::element(int)
{
  // TODO: parse
  return IWORKXMLContextPtr_t();
}

}

namespace
{

class DocumentElement : public PAG1XMLElementContextBase
{
public:
  explicit DocumentElement(PAG1ParserState &state);

private:
  virtual void attribute(int name, const char *value);
  virtual IWORKXMLContextPtr_t element(int name);
  virtual void endOfElement();

private:
  optional<IWORKSize> m_size;
};

DocumentElement::DocumentElement(PAG1ParserState &state)
  : PAG1XMLElementContextBase(state)
  , m_size()
{
}

void DocumentElement::attribute(const int name, const char *const value)
{
  switch (name)
  {
  case PAG1Token::NS_URI_SL | PAG1Token::version :
  {
    const unsigned version = getVersion(getToken(value));
    if (0 == version)
    {
      ETONYEK_DEBUG_MSG(("unknown version %s\n", value));
    }
  }
  break;
  }
}

IWORKXMLContextPtr_t DocumentElement::element(const int name)
{
  switch (name)
  {
  case IWORKToken::NS_URI_SF | IWORKToken::metadata :
    return makeContext<MetadataElement>(getState());
  case PAG1Token::NS_URI_SL | PAG1Token::section_prototypes :
    return makeContext<SectionPrototypesElement>(getState());
  case PAG1Token::NS_URI_SL | PAG1Token::stylesheet :
    return makeContext<StylesheetElement>(getState());
  case IWORKToken::NS_URI_SF | IWORKToken::headers :
    return makeContext<HeadersElement>(getState());
  case IWORKToken::NS_URI_SF | IWORKToken::footers :
    return makeContext<FootersElement>(getState());
  }

  return IWORKXMLContextPtr_t();
}

void DocumentElement::endOfElement()
{
}

}

namespace
{

class XMLDocument : public PAG1XMLElementContextBase
{
public:
  explicit XMLDocument(PAG1ParserState &state);

private:
  virtual IWORKXMLContextPtr_t element(int name);
};

XMLDocument::XMLDocument(PAG1ParserState &state)
  : PAG1XMLElementContextBase(state)
{
}

IWORKXMLContextPtr_t XMLDocument::element(const int name)
{
  switch (name)
  {
  case PAG1Token::NS_URI_SL | PAG1Token::document :
    return makeContext<DocumentElement>(m_state);
  }

  return IWORKXMLContextPtr_t();
}

}

PAG1Parser::PAG1Parser(const RVNGInputStreamPtr_t &input, const RVNGInputStreamPtr_t &package, PAGCollector *const collector, PAGDictionary *const dict)
  : IWORKParser(input, package)
  , m_state(*this, collector, *dict, getTokenizer())
  , m_version(0)
{
}

PAG1Parser::~PAG1Parser()
{
}

IWORKXMLContextPtr_t PAG1Parser::createDocumentContext()
{
  return makeContext<XMLDocument>(m_state);
}

TokenizerFunction_t PAG1Parser::getTokenizer() const
{
  return ChainedTokenizer(PAG1Tokenizer(), IWORKTokenizer());
}

}

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
