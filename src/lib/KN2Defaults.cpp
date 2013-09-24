/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libkeynote project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "KN2Defaults.h"

namespace libkeynote
{

namespace
{

static const KNSize PRESENTATION_SIZE = KNSize(1024, 768);
static const KNSize SHAPE_SIZE = KNSize(100, 100);

}

KN2Defaults::~KN2Defaults()
{
}

void KN2Defaults::applyPresentationSize(boost::optional<KNSize> &size) const
{
  if (!size)
    size = PRESENTATION_SIZE;
}

void KN2Defaults::applyGeometry(boost::optional<KNSize> &naturalSize, boost::optional<KNPosition> &position,
                                boost::optional<double> &angle,
                                boost::optional<double> &shearXAngle, boost::optional<double> &shearYAngle,
                                boost::optional<bool> &horizontalFlip, boost::optional<bool> &verticalFlip,
                                boost::optional<bool> &aspectRatioLocked, boost::optional<bool> &sizesLocked) const
{
  if (!naturalSize)
    naturalSize = SHAPE_SIZE;
  if (!position)
    position = KNPosition(PRESENTATION_SIZE.width - SHAPE_SIZE.width, PRESENTATION_SIZE.height - SHAPE_SIZE.width);
  if (!angle)
    angle = 0;
  if (!shearXAngle)
    shearXAngle = 0;
  if (!shearYAngle)
    shearYAngle = 0;
  if (!horizontalFlip)
    horizontalFlip = false;
  if (!verticalFlip)
    verticalFlip = false;
  if (!aspectRatioLocked)
    aspectRatioLocked = false;
  if (!sizesLocked)
    sizesLocked = false;
}

}

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
