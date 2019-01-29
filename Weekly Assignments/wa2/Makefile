SOURCE = testMain.cpp \
         integerClass.cpp

OBJS = $(SOURCE:.cpp=.o)

#GNU C/C++ Compiler
GCC = g++

# GNU C/C++ Linker
LINK = g++

# Archive
AR = ar rs

# Compiler flags
INC =
CFLAGS = -fPIC -Wall -std=c++11 $(INC)
CXXFLAGS = $(CFLAGS)

# Fill in special libraries needed here
LIBS =

.PHONY: clean

# Targets include all, clean, debug, tar

all : testMain

testMain: $(OBJS)
	$(LINK) -o $@ $^ $(LIBS)

clean:
	rm -rf *.o *.d core testMain

debug: CXXFLAGS = -DDEBUG -g -std=c++11
debug: testMain

tar: clean
	tar zcvf testMain.tgz $(SOURCE) *.h Makefile

help:
	@echo "	make testMain  - same as make all"
	@echo "	make all   - builds the main target"
	@echo "	make       - same as make all"
	@echo "	make clean - remove .o .d core testMain"
	@echo "	make debug - make all with -g and -DDEBUG"
	@echo "	make tar   - make a tarball of .cpp and .h files"
	@echo "	make help  - this message"

-include $(SOURCE:.cpp=.d)

%.d: %.cpp
	@set -e; /usr/bin/rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@

