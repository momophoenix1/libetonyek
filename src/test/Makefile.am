target_test = test

check_PROGRAMS = $(target_test)

AM_CXXFLAGS = -I$(top_srcdir)/inc -I$(top_srcdir)/src/lib $(REVENGE_CFLAGS) $(CPPUNIT_CFLAGS) $(XML_CFLAGS) $(DEBUG_CXXFLAGS)

test_LDFLAGS = -L$(top_builddir)/src/lib
test_LDADD = \
	$(top_builddir)/src/lib/libetonyek_internal.la \
	$(REVENGE_LIBS) \
	$(CPPUNIT_LIBS) \
	$(XML_LIBS)

test_SOURCES = \
	IWORKPathTest.cpp \
	IWORKPropertyMapTest.cpp \
	IWORKShapeTest.cpp \
	IWORKStyleTest.cpp \
	IWORKStyleStackTest.cpp \
	IWORKTransformationTest.cpp \
	KEY2TokenTest.cpp \
	test.cpp

TESTS = $(target_test)
