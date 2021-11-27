# Makefile for DrawDiagonals
#****************************************************************

PROGRAMS = \
    DrawDiagonals

ROOTPATH = ../..
CPPOPTIONS = -I$(ROOTPATH)/include -fvisibility-inlines-hidden
LDOPTIONS = -L$(ROOTPATH)/lib -static-libstdc++
LIB = -lStanfordCPPLib

# ***************************************************************
# Entry to bring the package up to date
#    The "make all" entry should be the first real entry

all: $(PROGRAMS) spl.jar

spl.jar:
	@ln -s $(ROOTPATH)/java/spl.jar

DrawDiagonals: DrawDiagonals.o
	g++ $(LDOPTIONS) -o DrawDiagonals DrawDiagonals.o $(LIB)

DrawDiagonals.o: DrawDiagonals.cpp
	g++ $(CPPOPTIONS) -c DrawDiagonals.cpp


# ***************************************************************
# Standard entries to remove files from the directories
#    tidy  -- eliminate unwanted files
#    clean -- delete derived files in preparation for rebuild

tidy:
	rm -f ,* .,* *~ core a.out *.err

clean scratch: tidy
	rm -f *.o *.a $(PROGRAMS) $(OBJECTS) spl.jar
