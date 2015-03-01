/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libetonyek project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "KEYThemeCollector.h"

#include "libetonyek_utils.h"
#include "KEYDictionary.h"

using boost::optional;

namespace libetonyek
{

KEYThemeCollector::KEYThemeCollector(KEYDictionary &dict, KEYLayerMap_t &masterPages, IWORKSize &size)
  : KEYCollectorBase(dict)
  , m_masterPages(masterPages)
  , m_size(size)
{
}

KEYThemeCollector::~KEYThemeCollector()
{
}

void KEYThemeCollector::collectPresentation(const boost::optional<IWORKSize> &size)
{
  if (size)
    m_size = get(size);
}

void KEYThemeCollector::collectLayer(const boost::optional<ID_t> &id, const bool ref)
{
  if (isCollecting())
  {
    KEYCollectorBase::collectLayer(id, ref);

    if (ref)
    {
      ETONYEK_DEBUG_MSG(("cannot use master page reference %s in a master page\n", id ? get(id).c_str() : ""));
    }
    else
    {
      const KEYLayerPtr_t layer = getLayer();
      if (bool(layer) && id)
        m_masterPages.insert(KEYLayerMap_t::value_type(get(id), layer));
      else
      {
        ETONYEK_DEBUG_MSG(("master style layer is empty\n"));
      }
    }
  }
}

void KEYThemeCollector::collectPage(const boost::optional<ID_t> &id)
{
  // TODO: implement me
  (void) id;
}

void KEYThemeCollector::startSlides()
{
}

void KEYThemeCollector::endSlides()
{
}

void KEYThemeCollector::startThemes()
{
  setCollecting(true);
}

void KEYThemeCollector::endThemes()
{
  setCollecting(false);
}

void KEYThemeCollector::startPage()
{
}

void KEYThemeCollector::endPage()
{
}

void KEYThemeCollector::startLayer()
{
  KEYCollectorBase::startLayer();
}

void KEYThemeCollector::endLayer()
{
  KEYCollectorBase::endLayer();
}

}

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
