/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libetonyek project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef IWORKTABULARINFOELEMENT_H_INCLUDED
#define IWORKTABULARINFOELEMENT_H_INCLUDED

#include <boost/shared_ptr.hpp>

#include "IWORKXMLContextBase.h"

namespace libetonyek
{

class IWORKTabularInfoElement : public IWORKXMLElementContextBase
{
  struct Impl;

public:
  explicit IWORKTabularInfoElement(IWORKXMLParserState &state);

private:
  virtual void startOfElement();
  virtual IWORKXMLContextPtr_t element(int name);
  virtual void endOfElement();

private:
  boost::shared_ptr<Impl> m_impl;
};

}

#endif // IWORKTABULARINFOELEMENT_H_INCLUDED

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
