SOURCE = main.cpp

LIBSRC = functions.cpp

OBJS = $(SOURCE:.cpp=.o)

LIBOBJS = $(LIBSRC:.cpp=.o)

#GNU C/C++ Compiler
GCC = g++

# GNU C/C++ Linker
LINK = g++

# Archive
AR = ar rs

# Compiler flags
CFLAGS = -Wall -fPIC -g -std=c++11
DFLAG = -DDEBUG
RFLAG = -DRELEASE
CXXFLAGS = $(CFLAGS)

# Fill in special libraries needed here
LIBS = -lMyLib -L.

.PHONY: clean

# Targets include all, clean, debug, tar

all : main

main: $(OBJS) lib
	$(LINK) -o $@ $(OBJS) $(LIBS)

lib: libMyLib.so debug/libMyLib.so release/libMyLib.so

libMyLib.so: $(LIBOBJS)
	$(GCC) -o $@ -shared $^

release.o: $(LIBOBJS)
	$(GCC) $(CXXFLAGS) $(RFLAG) -c -o $@ $(LIBSRC) 

debug.o: $(LIBOBJS)
	$(GCC) $(CXXFLAGS) $(DFLAG) -c -o $@ $(LIBSRC) 

debug/libMyLib.so: debug.o
	mkdir debug
	$(GCC) -o $@ -shared $^ 

release/libMyLib.so: release.o
	mkdir release
	$(GCC) -o $@ -shared $^


clean:
	rm -rf *.o *.d core libMyLib.* debug release main

debug: CXXFLAGS = -DDEBUG -g -std=c++11
debug: main

tar: clean
	tar zcvf main.tgz $(SOURCE) *.h Makefile

-include $(SOURCE:.cpp=.d)

-include $(LIBSRC:.cpp=.d)

%.d: %.cpp
	@set -e; /bin/rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) -Ddebug > $@
