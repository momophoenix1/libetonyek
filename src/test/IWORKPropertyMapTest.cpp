/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * This file is part of the libetonyek project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "IWORKPropertyMap.h"

namespace test
{

using boost::any;
using boost::any_cast;

using libetonyek::IWORKPropertyMap;

class IWORKPropertyMapTest : public CPPUNIT_NS::TestFixture
{
public:
  virtual void setUp();
  virtual void tearDown();

private:
  CPPUNIT_TEST_SUITE(IWORKPropertyMapTest);
  CPPUNIT_TEST(testLookup);
  CPPUNIT_TEST(testLookupWithParent);
  CPPUNIT_TEST_SUITE_END();

private:
  void testLookup();
  void testLookupWithParent();
};

void IWORKPropertyMapTest::setUp()
{
}

void IWORKPropertyMapTest::tearDown()
{
}

void IWORKPropertyMapTest::testLookup()
{
  IWORKPropertyMap props;

  // empty map
  CPPUNIT_ASSERT(props.get("answer").empty());

  // known key
  props.set("answer", 42);
  CPPUNIT_ASSERT(!props.get("answer").empty());
  CPPUNIT_ASSERT_EQUAL(42, any_cast<int>(props.get("answer")));

  // unknown key
  CPPUNIT_ASSERT(props.get("antwort").empty());
}

void IWORKPropertyMapTest::testLookupWithParent()
{
  // simple recursive lookup test
  {
    IWORKPropertyMap parent;
    parent.set("answer", 42);

    IWORKPropertyMap props;
    props.setParent(&parent);

    CPPUNIT_ASSERT(!props.get("answer", true).empty());
    CPPUNIT_ASSERT_EQUAL(42, any_cast<int>(props.get("answer", true)));

    // rewrite key in props
    props.set("answer", 3);
    CPPUNIT_ASSERT(!props.get("answer", true).empty());
    CPPUNIT_ASSERT_EQUAL(3, any_cast<int>(props.get("answer", true)));

    // unknown key
    CPPUNIT_ASSERT(props.get("antwort", true).empty());

    IWORKPropertyMap grandparent;
    grandparent.set("antwort", 17);

    // recursive lookup through more parents
    parent.setParent(&grandparent);
    CPPUNIT_ASSERT(!props.get("antwort", true).empty());
    CPPUNIT_ASSERT_EQUAL(17, any_cast<int>(props.get("antwort", true)));
  }

  // switching of parents
  {
    IWORKPropertyMap parent1;
    parent1.set("answer", 42);

    IWORKPropertyMap parent2;
    parent2.set("antwort", 13);

    IWORKPropertyMap props;

    props.setParent(&parent1);
    CPPUNIT_ASSERT(!props.get("answer", true).empty());
    CPPUNIT_ASSERT_EQUAL(42, any_cast<int>(props.get("answer", true)));

    // switch parent
    props.setParent(&parent2);
    CPPUNIT_ASSERT(props.get("answer", true).empty());
    CPPUNIT_ASSERT(!props.get("antwort", true).empty());
    CPPUNIT_ASSERT_EQUAL(13, any_cast<int>(props.get("antwort", true)));

    // disable parent
    props.setParent(0);
    CPPUNIT_ASSERT(props.get("answer", true).empty());
    CPPUNIT_ASSERT(props.get("antwort", true).empty());
  }
}

CPPUNIT_TEST_SUITE_REGISTRATION(IWORKPropertyMapTest);

}

/* vim:set shiftwidth=2 softtabstop=2 expandtab: */
