# Makefile for cpplib
#****************************************************************

LIBRARIES = \
    lib/libStanfordCPPLib.a

OBJECTS = \
    obj/console.o \
    obj/direction.o \
    obj/error.o \
    obj/filelib.o \
    obj/gevents.o \
    obj/ginteractors.o \
    obj/gmath.o \
    obj/gobjects.o \
    obj/gtimer.o \
    obj/gtypes.o \
    obj/gwindow.o \
    obj/hashmap.o \
    obj/lexicon.o \
    obj/main.o \
    obj/platform.o \
    obj/point.o \
    obj/random.o \
    obj/simpio.o \
    obj/sound.o \
    obj/startup.o \
    obj/strlib.o \
    obj/thread.o \
    obj/tplatform.o \
    obj/tokenscanner.o

TESTS = \
    TestStanfordCPPLib

TESTOBJECTS = \
    obj/TestDirectionType.o \
    obj/TestFilelibLibrary.o \
    obj/TestForeachStatement.o \
    obj/TestGraphClass.o \
    obj/TestGridClass.o \
    obj/TestHashSetClass.o \
    obj/TestHashmapClass.o \
    obj/TestLexiconClass.o \
    obj/TestMapClass.o \
    obj/TestPriorityQueueClass.o \
    obj/TestQueueClass.o \
    obj/TestRandomLibrary.o \
    obj/TestSetClass.o \
    obj/TestSimpioLibrary.o \
    obj/TestStackClass.o \
    obj/TestStanfordCPPLib.o \
    obj/TestStrlibLibrary.o \
    obj/TestTokenScannerClass.o \
    obj/TestVectorClass.o \
    obj/unittest.o

CPPOPTIONS = -Iinclude -fvisibility-inlines-hidden
LDOPTIONS = -static-libstdc++


# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(OBJECTS) $(LIBRARIES) $(TESTS)
	@(cd java; make all)

obj/console.o: src/console.cpp include/console.h include/foreach.h \
               include/gevents.h include/gtimer.h include/gtypes.h \
               include/gwindow.h include/platform.h include/private/main.h \
               include/sound.h include/strlib.h include/vector.h
	g++ -c $(CPPOPTIONS) -o obj/console.o src/console.cpp

obj/direction.o: src/direction.cpp include/direction.h include/error.h \
                 include/foreach.h include/private/main.h \
                 include/private/tokenpatch.h include/strlib.h \
                 include/tokenscanner.h
	g++ -c $(CPPOPTIONS) -o obj/direction.o src/direction.cpp

obj/error.o: src/error.cpp include/error.h include/private/main.h
	g++ -c $(CPPOPTIONS) -o obj/error.o src/error.cpp

obj/filelib.o: src/filelib.cpp include/console.h include/filelib.h \
               include/foreach.h include/gevents.h include/gtimer.h \
               include/gtypes.h include/gwindow.h include/platform.h \
               include/private/main.h include/sound.h include/strlib.h \
               include/vector.h
	g++ -c $(CPPOPTIONS) -o obj/filelib.o src/filelib.cpp

obj/gevents.o: src/gevents.cpp include/console.h include/error.h \
               include/foreach.h include/gevents.h include/gtimer.h \
               include/gtypes.h include/gwindow.h include/map.h \
               include/platform.h include/private/main.h include/sound.h \
               include/stack.h include/strlib.h include/vector.h
	g++ -c $(CPPOPTIONS) -o obj/gevents.o src/gevents.cpp

obj/ginteractors.o: src/ginteractors.cpp include/console.h \
                    include/foreach.h include/gevents.h \
                    include/ginteractors.h include/gobjects.h \
                    include/gtimer.h include/gtypes.h include/gwindow.h \
                    include/platform.h include/private/main.h \
                    include/sound.h include/strlib.h include/vector.h
	g++ -c $(CPPOPTIONS) -o obj/ginteractors.o src/ginteractors.cpp

obj/gmath.o: src/gmath.cpp include/gmath.h include/gtypes.h
	g++ -c $(CPPOPTIONS) -o obj/gmath.o src/gmath.cpp

obj/gobjects.o: src/gobjects.cpp include/console.h include/foreach.h \
                include/gevents.h include/gmath.h include/gobjects.h \
                include/gtimer.h include/gtypes.h include/gwindow.h \
                include/platform.h include/private/main.h include/sound.h \
                include/strlib.h include/vector.h
	g++ -c $(CPPOPTIONS) -o obj/gobjects.o src/gobjects.cpp

obj/gtimer.o: src/gtimer.cpp include/console.h include/foreach.h \
              include/gevents.h include/gtimer.h include/gtypes.h \
              include/gwindow.h include/platform.h include/private/main.h \
              include/sound.h include/strlib.h include/vector.h
	g++ -c $(CPPOPTIONS) -o obj/gtimer.o src/gtimer.cpp

obj/gtypes.o: src/gtypes.cpp include/error.h include/gtypes.h \
              include/private/main.h include/strlib.h
	g++ -c $(CPPOPTIONS) -o obj/gtypes.o src/gtypes.cpp

obj/gwindow.o: src/gwindow.cpp include/console.h include/foreach.h \
               include/gevents.h include/gmath.h include/gobjects.h \
               include/gtimer.h include/gtypes.h include/gwindow.h \
               include/map.h include/platform.h include/private/main.h \
               include/sound.h include/stack.h include/strlib.h \
               include/vector.h
	g++ -c $(CPPOPTIONS) -o obj/gwindow.o src/gwindow.cpp

obj/hashmap.o: src/hashmap.cpp include/foreach.h include/hashmap.h \
               include/strlib.h include/vector.h
	g++ -c $(CPPOPTIONS) -o obj/hashmap.o src/hashmap.cpp

obj/lexicon.o: src/lexicon.cpp include/error.h include/foreach.h \
               include/lexicon.h include/map.h include/private/main.h \
               include/set.h include/stack.h include/strlib.h \
               include/vector.h
	g++ -c $(CPPOPTIONS) -o obj/lexicon.o src/lexicon.cpp

obj/main.o: src/main.cpp
	g++ -c $(CPPOPTIONS) -o obj/main.o src/main.cpp

obj/platform.o: src/platform.cpp include/console.h include/error.h \
                include/filelib.h include/foreach.h include/gevents.h \
                include/gtimer.h include/gtypes.h include/gwindow.h \
                include/hashmap.h include/platform.h include/private/main.h \
                include/private/tokenpatch.h include/queue.h \
                include/sound.h include/stack.h include/strlib.h \
                include/tokenscanner.h include/vector.h
	g++ -c $(CPPOPTIONS) -o obj/platform.o src/platform.cpp

obj/point.o: src/point.cpp include/point.h include/strlib.h
	g++ -c $(CPPOPTIONS) -o obj/point.o src/point.cpp

obj/random.o: src/random.cpp include/private/randompatch.h include/random.h
	g++ -c $(CPPOPTIONS) -o obj/random.o src/random.cpp

obj/simpio.o: src/simpio.cpp include/simpio.h
	g++ -c $(CPPOPTIONS) -o obj/simpio.o src/simpio.cpp

obj/sound.o: src/sound.cpp include/console.h include/foreach.h \
             include/gevents.h include/gtimer.h include/gtypes.h \
             include/gwindow.h include/platform.h include/private/main.h \
             include/sound.h include/strlib.h include/vector.h
	g++ -c $(CPPOPTIONS) -o obj/sound.o src/sound.cpp

obj/startup.o: src/startup.cpp include/error.h include/private/main.h
	g++ -c $(CPPOPTIONS) -o obj/startup.o src/startup.cpp

obj/strlib.o: src/strlib.cpp include/error.h include/private/main.h \
              include/strlib.h
	g++ -c $(CPPOPTIONS) -o obj/strlib.o src/strlib.cpp

obj/thread.o: src/thread.cpp include/private/tplatform.h include/thread.h
	g++ -c $(CPPOPTIONS) -o obj/thread.o src/thread.cpp

obj/tplatform.o: src/tplatform-posix.cpp include/error.h \
                 include/foreach.h include/map.h include/private/main.h \
                 include/private/tplatform.h include/stack.h \
                 include/strlib.h include/vector.h
	g++ -c $(CPPOPTIONS) -o obj/tplatform.o src/tplatform-posix.cpp

obj/tokenscanner.o: src/tokenscanner.cpp include/error.h include/foreach.h \
                    include/private/main.h include/private/tokenpatch.h \
                    include/stack.h include/strlib.h include/tokenscanner.h \
                    include/vector.h
	g++ -c $(CPPOPTIONS) -o obj/tokenscanner.o src/tokenscanner.cpp


# ***************************************************************
# Entry to reconstruct the library

lib/libStanfordCPPLib.a: $(OBJECTS)
	@if [[ "`uname`" == "Darwin" ]] ; then \
           /usr/bin/libtool -o lib/libStanfordCPPLib.a $(OBJECTS); \
         else \
           ar cr lib/libStanfordCPPLib.a $(OBJECTS) ; \
           ranlib lib/libStanfordCPPLib.a ; \
         fi
	@echo "[lib/libStanfordCPPLib.a created]"


# ***************************************************************
# Test program

TESTOPTIONS = $(CPPOPTIONS) -Isrc/tests

obj/TestDirectionType.o: src/tests/TestDirectionType.cpp \
                         src/tests/unittest.h include/direction.h \
                         include/error.h include/foreach.h \
                         include/private/main.h
	g++ $(TESTOPTIONS) -c -o obj/TestDirectionType.o \
            src/tests/TestDirectionType.cpp

obj/TestFilelibLibrary.o: src/tests/TestFilelibLibrary.cpp \
                          src/tests/unittest.h include/error.h \
                          include/filelib.h include/foreach.h \
                          include/private/main.h include/strlib.h \
                          include/vector.h
	g++ $(TESTOPTIONS) -c -o obj/TestFilelibLibrary.o \
            src/tests/TestFilelibLibrary.cpp

obj/TestForeachStatement.o: src/tests/TestForeachStatement.cpp \
                            src/tests/unittest.h include/error.h \
                            include/foreach.h include/grid.h include/map.h \
                            include/private/main.h include/set.h \
                            include/stack.h include/strlib.h \
                            include/vector.h
	g++ $(TESTOPTIONS) -c -o obj/TestForeachStatement.o \
            src/tests/TestForeachStatement.cpp

obj/TestGraphClass.o: src/tests/TestGraphClass.cpp src/tests/unittest.h \
                      include/error.h include/foreach.h include/graph.h \
                      include/map.h include/private/main.h \
                      include/private/tokenpatch.h include/set.h \
                      include/stack.h include/strlib.h \
                      include/tokenscanner.h include/vector.h
	g++ $(TESTOPTIONS) -c -o obj/TestGraphClass.o \
            src/tests/TestGraphClass.cpp

obj/TestGraphics.o: src/tests/TestGraphics.cpp include/console.h \
                    include/filelib.h include/foreach.h include/gevents.h \
                    include/gtimer.h include/gtypes.h include/gwindow.h \
                    include/private/main.h include/strlib.h \
                    include/vector.h
	g++ $(TESTOPTIONS) -c -o obj/TestGraphics.o \
            src/tests/TestGraphics.cpp

obj/TestGridClass.o: src/tests/TestGridClass.cpp src/tests/unittest.h \
                     include/error.h include/foreach.h include/grid.h \
                     include/private/main.h include/strlib.h \
                     include/vector.h
	g++ $(TESTOPTIONS) -c -o obj/TestGridClass.o \
            src/tests/TestGridClass.cpp

obj/TestHashSetClass.o: src/tests/TestHashSetClass.cpp src/tests/unittest.h \
                        include/error.h include/foreach.h include/hashmap.h \
                        include/hashset.h include/private/main.h \
                        include/random.h include/strlib.h include/vector.h
	g++ $(TESTOPTIONS) -c -o obj/TestHashSetClass.o \
            src/tests/TestHashSetClass.cpp

obj/TestHashmapClass.o: src/tests/TestHashmapClass.cpp src/tests/unittest.h \
                        include/error.h include/foreach.h include/hashmap.h \
                        include/private/main.h include/strlib.h \
                        include/vector.h
	g++ $(TESTOPTIONS) -c -o obj/TestHashmapClass.o \
            src/tests/TestHashmapClass.cpp

obj/TestLexiconClass.o: src/tests/TestLexiconClass.cpp src/tests/unittest.h \
                        include/error.h include/foreach.h include/lexicon.h \
                        include/map.h include/private/main.h include/set.h \
                        include/stack.h include/strlib.h include/vector.h
	g++ $(TESTOPTIONS) -c -o obj/TestLexiconClass.o \
            src/tests/TestLexiconClass.cpp

obj/TestMapClass.o: src/tests/TestMapClass.cpp src/tests/unittest.h \
                    include/error.h include/foreach.h include/map.h \
                    include/private/main.h include/stack.h include/strlib.h \
                    include/vector.h
	g++ $(TESTOPTIONS) -c -o obj/TestMapClass.o \
            src/tests/TestMapClass.cpp

obj/TestPriorityQueueClass.o: src/tests/TestPriorityQueueClass.cpp \
                              src/tests/unittest.h include/error.h \
                              include/foreach.h include/pqueue.h \
                              include/private/main.h include/strlib.h \
                              include/vector.h
	g++ $(TESTOPTIONS) -c -o obj/TestPriorityQueueClass.o \
            src/tests/TestPriorityQueueClass.cpp

obj/TestQueueClass.o: src/tests/TestQueueClass.cpp src/tests/unittest.h \
                      include/error.h include/foreach.h \
                      include/private/main.h include/queue.h \
                      include/strlib.h include/vector.h
	g++ $(TESTOPTIONS) -c -o obj/TestQueueClass.o \
            src/tests/TestQueueClass.cpp

obj/TestRandomLibrary.o: src/tests/TestRandomLibrary.cpp \
                         src/tests/unittest.h include/error.h \
                         include/private/main.h include/random.h
	g++ $(TESTOPTIONS) -c -o obj/TestRandomLibrary.o \
            src/tests/TestRandomLibrary.cpp

obj/TestSetClass.o: src/tests/TestSetClass.cpp src/tests/unittest.h \
                    include/direction.h include/error.h include/foreach.h \
                    include/lexicon.h include/map.h include/private/main.h \
                    include/random.h include/set.h include/stack.h \
                    include/strlib.h include/vector.h
	g++ $(TESTOPTIONS) -c -o obj/TestSetClass.o \
            src/tests/TestSetClass.cpp

obj/TestSimpioLibrary.o: src/tests/TestSimpioLibrary.cpp \
                         src/tests/unittest.h include/error.h \
                         include/private/main.h include/simpio.h
	g++ $(TESTOPTIONS) -c -o obj/TestSimpioLibrary.o \
            src/tests/TestSimpioLibrary.cpp

obj/TestStackClass.o: src/tests/TestStackClass.cpp src/tests/unittest.h \
                      include/error.h include/foreach.h \
                      include/private/main.h include/stack.h \
                      include/strlib.h include/vector.h
	g++ $(TESTOPTIONS) -c -o obj/TestStackClass.o \
            src/tests/TestStackClass.cpp

obj/TestStanfordCPPLib.o: src/tests/TestStanfordCPPLib.cpp \
                          src/tests/unittest.h include/error.h \
                          include/private/main.h include/strlib.h
	g++ $(TESTOPTIONS) -c -o obj/TestStanfordCPPLib.o \
            src/tests/TestStanfordCPPLib.cpp

obj/TestStrlibLibrary.o: src/tests/TestStrlibLibrary.cpp \
                         src/tests/unittest.h include/error.h \
                         include/private/main.h include/strlib.h
	g++ $(TESTOPTIONS) -c -o obj/TestStrlibLibrary.o \
            src/tests/TestStrlibLibrary.cpp

obj/TestTokenScannerClass.o: src/tests/TestTokenScannerClass.cpp \
                             src/tests/unittest.h include/error.h \
                             include/private/main.h \
                             include/private/tokenpatch.h \
                             include/tokenscanner.h
	g++ $(TESTOPTIONS) -c -o obj/TestTokenScannerClass.o \
            src/tests/TestTokenScannerClass.cpp

obj/TestVectorClass.o: src/tests/TestVectorClass.cpp src/tests/unittest.h \
                       include/direction.h include/error.h \
                       include/foreach.h include/private/main.h \
                       include/strlib.h include/vector.h
	g++ $(TESTOPTIONS) -c -o obj/TestVectorClass.o \
            src/tests/TestVectorClass.cpp

obj/unittest.o: src/tests/unittest.cpp src/tests/unittest.h include/error.h \
                include/private/main.h
	g++ $(TESTOPTIONS) -c -o obj/unittest.o \
            src/tests/unittest.cpp

TestStanfordCPPLib: $(TESTOBJECTS)
	g++ $(LDOPTIONS) -o TestStanfordCPPLib $(TESTOBJECTS) \
            -Llib -lStanfordCPPLib


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	@rm -f `find . -name ',*' -o -name '.,*' -o -name '*~'`
	@rm -f `find . -name '*.tmp' -o -name '*.err'`
	@rm -f `find . -name core -o -name a.out`

clean scratch: tidy
	@rm -f -r $(OBJECTS) $(LIBRARIES) $(TESTS) $(TESTOBJECTS)
