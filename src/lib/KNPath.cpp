/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libkeynote project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <cassert>
#include <sstream>
#include <utility>

#include <boost/bind.hpp>
#include <boost/ref.hpp>
#include <boost/spirit/include/classic_core.hpp>

#include "libkeynote_utils.h"
#include "KNPath.h"
#include "KNTypes.h"

using std::ostringstream;
using std::string;

namespace libkeynote
{

/** An element of path.
  */
class KNPath::Element
{
public:
  virtual ~Element() = 0;

  virtual Element *clone() const = 0;

  /** Test whether this element is equal to other.
    *
    * @note Because all implementations of this interface are directly
    * derived from it (i.e., thay have no subclasses), it is enough to
    * check if @c other has a compatible type, not that @c this and @c
    * other have the @em same type (which would require double
    * dispatch).
    *
    * @return true if @c this and @c other are equal.
    */
  virtual bool equalsTo(const Element *other) const = 0;

  /** Create SVG representation of this path.
   */
  virtual void toSvg(ostringstream &out) const = 0;
};

namespace
{

class MoveTo : public KNPath::Element
{
public:
  MoveTo(double x, double y);

  virtual MoveTo *clone() const;

  virtual bool equalsTo(const Element *other) const;

  virtual void toSvg(ostringstream &out) const;

private:
  const double m_x;
  const double m_y;
};

MoveTo::MoveTo(double x, double y)
  : m_x(x)
  , m_y(y)
{
}

MoveTo *MoveTo::clone() const
{
  return new MoveTo(*this);
}

bool MoveTo::equalsTo(const Element *other) const
{
  const MoveTo *const that = dynamic_cast<const MoveTo *>(other);

  if (that)
    return m_x == that->m_x && m_y == that->m_y;

  return false;
}

void MoveTo::toSvg(ostringstream &out) const
{
  out << 'M' << ' ' << m_x << ' ' << m_y;
}

}

namespace
{

class LineTo : public KNPath::Element
{
public:
  LineTo(double x, double y);

  virtual LineTo *clone() const;

  virtual bool equalsTo(const Element *other) const;

  virtual void toSvg(ostringstream &out) const;

private:
  const double m_x;
  const double m_y;
};

LineTo::LineTo(const double x, const double y)
  : m_x(x)
  , m_y(y)
{
}

LineTo *LineTo::clone() const
{
  return new LineTo(*this);
}

bool LineTo::equalsTo(const Element *other) const
{
  const LineTo *const that = dynamic_cast<const LineTo *>(other);

  if (that)
    return m_x == that->m_x && m_y == that->m_y;

  return false;
}

void LineTo::toSvg(ostringstream &out) const
{
  out << 'L' << ' ' << m_x << ' ' << m_y;
}

}

namespace
{

class CurveTo : public KNPath::Element
{
public:
  CurveTo(double x1, double y1, double x2, double y2, double x, double y);

  virtual CurveTo *clone() const;

  virtual bool equalsTo(const Element *other) const;

  virtual void toSvg(ostringstream &out) const;

private:
  const double m_x1;
  const double m_y1;
  const double m_x2;
  const double m_y2;
  const double m_x;
  const double m_y;
};

CurveTo::CurveTo(const double x1, const double y1, const double x2, const double y2, const double x, const double y)
  : m_x1(x1)
  , m_y1(y1)
  , m_x2(x2)
  , m_y2(y2)
  , m_x(x)
  , m_y(y)
{
}

CurveTo *CurveTo::clone() const
{
  return new CurveTo(*this);
}

bool CurveTo::equalsTo(const Element *other) const
{
  const CurveTo *const that = dynamic_cast<const CurveTo *>(other);

  if (that)
    return m_x1 == that->m_x1 && m_y1 == that->m_y1
           && m_x2 == that->m_x2 && m_y2 == that->m_y2
           && m_x == that->m_x && m_y == that->m_y
           ;

  return false;
}

void CurveTo::toSvg(ostringstream &out) const
{
  out << 'C'
      << ' ' << m_x1 << ' ' << m_y1
      << ' ' << m_x2 << ' ' << m_y2
      << ' ' << m_x << ' ' << m_y
      ;
}

}

namespace
{

class Close : public KNPath::Element
{
public:
  Close();

  virtual Close *clone() const;

  virtual bool equalsTo(const Element *other) const;

  virtual void toSvg(ostringstream &out) const;
};

Close::Close()
{
}

Close *Close::clone() const
{
  return new Close();
}

bool Close::equalsTo(const Element *other) const
{
  return dynamic_cast<const Close *>(other);
}

void Close::toSvg(ostringstream &out) const
{
  out << 'Z';
}

}

KNPath::Element::~Element()
{
}

KNPath::KNPath()
  : m_elements()
{
}

KNPath::KNPath(const std::string &path)
  : m_elements()
{
  using boost::bind;
  using boost::cref;
  using namespace boost::spirit::classic;

  double x = 0;
  double y = 0;
  double x1 = 0;
  double y1 = 0;
  double x2 = 0;
  double y2 = 0;

  const rule<> r =
    +(
      ('C' >> real_p[assign_a(x)] >> real_p[assign_a(y)] >> real_p[assign_a(x1)] >> real_p[assign_a(y1)] >> real_p[assign_a(x2)] >> real_p[assign_a(y2)])
      [bind(&KNPath::appendCurveTo, this, cref(x), cref(y), cref(x1), cref(y1), cref(x2), cref(y2))]
      | ('L' >> real_p[assign_a(x)] >> real_p[assign_a(y)])[bind(&KNPath::appendLineTo, this, cref(x), cref(y))]
      | ('M' >> real_p[assign_a(x)] >> real_p[assign_a(y)])[bind(&KNPath::appendMoveTo, this, cref(x), cref(y))]
      | ch_p('Z')[bind(&KNPath::appendClose, this)]
    )
    ;

  if (!parse(path.c_str(), r, space_p).full)
  {
    KN_DEBUG_MSG(("parsing of path '%s' failed\n", path.c_str()));
    throw GenericException();
  }
}

KNPath::KNPath(const KNPath &other)
  : m_elements()
{
  try
  {
    for (std::deque<Element *>::const_iterator it = other.m_elements.begin(); it != other.m_elements.end(); ++it)
      m_elements.push_back((*it)->clone());
  }
  catch (...)
  {
    clear();
    throw;
  }
}

KNPath::~KNPath()
{
  clear();
}

KNPath &KNPath::operator=(const KNPath &other)
{
  KNPath copy(other);
  swap(copy);
  return *this;
}

void KNPath::swap(KNPath &other)
{
  using std::swap;
  swap(m_elements, other.m_elements);
}

void KNPath::clear()
{
  for (std::deque<Element *>::const_iterator it = m_elements.begin(); it != m_elements.end(); ++it)
    delete *it;
  m_elements.clear();
}

void KNPath::appendMoveTo(const double x, const double y)
{
  m_elements.push_back(new MoveTo(x, y));
}

void KNPath::appendLineTo(const double x, const double y)
{
  m_elements.push_back(new LineTo(x, y));
}

void KNPath::appendCurveTo(const double x1, const double y1, const double x2, const double y2, const double x, const double y)
{
  m_elements.push_back(new CurveTo(x1, y1, x2, y2, x, y));
}

void KNPath::appendClose()
{
  m_elements.push_back(new Close());
}

string KNPath::toSvg() const
{
  ostringstream out;

  bool first = true;
  for (std::deque<Element *>::const_iterator it = m_elements.begin(); it != m_elements.end(); ++it)
  {
    if (first)
      first = false;
    else
      out << ' ';

    (*it)->toSvg(out);
  }

  return out.str();
}

bool operator==(const KNPath &left, const KNPath &right)
{
  return left.m_elements.size() == right.m_elements.size()
         && std::equal(left.m_elements.begin(), left.m_elements.end(), right.m_elements.begin(),
                       boost::bind(&KNPath::Element::equalsTo, _1, _2))
         ;
}

bool operator!=(const KNPath &left, const KNPath &right)
{
  return !(left == right);
}

namespace
{

class PathObject : public KNObject
{
public:
  explicit PathObject(const KNPathPtr_t &path);

private:
  virtual void draw(libwpg::WPGPaintInterface *painter, const KNTransformation &tr);

private:
  const KNPathPtr_t m_path;
};

PathObject::PathObject(const KNPathPtr_t &path)
  : m_path(path)
{
}

void PathObject::draw(libwpg::WPGPaintInterface *const painter, const KNTransformation &tr)
{
  // TODO: implement me
  (void) painter;
  (void) tr;
}

}

KNObjectPtr_t makeObject(const KNPathPtr_t &path)
{
  const KNObjectPtr_t object(new PathObject(path));
  return object;
}

}

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
