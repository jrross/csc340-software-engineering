SOURCE = Test/testLogger.cpp                           \
         Test/testMain.cpp                             \
         Test/testAnalyst.cpp                          \
         logger.cpp                                    \
         analyst.cpp                          

SOURCE_DEMO = logger.cpp                               \
              main.cpp                                 \
              analyst.cpp
              
PROCS = ./proc/*.cpp
       
PROC=MovingAverage

OBJS = $(SOURCE_DEMO:.cpp=.o)
TEST_OBJS = $(SOURCE:.cpp=.o)

#GNU C/C++ Compiler
GCC = g++

# GNU C/C++ Linker
LINK = g++

# Archive
AR = ar rs

# Compiler flags
INC = -I./include
CFLAGS = -fPIC -Wall -DDEBUG -g -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0 $(INC)
CXXFLAGS = $(CFLAGS)

# Fill in special libraries needed here
LIBS = -Bstatic -L./procLibraries -l$(PROC) -L./lib -lPlatform

.PHONY: clean lib

# Targets include all, clean, debug, tar

all : main

run: main runMain

main: $(OBJS)
	rm -rf ProgramTrader
	$(shell mkdir -p procLibraries)
	g++ -Wall -fPIC -O3 -std=c++11 -c -o procedure.o ./proc/$(PROC).cpp
	ar rs ./procLibraries/lib$(PROC).a procedure.o
	$(LINK) -o ProgramTrader $^ $(LIBS)

testMain: makeTestMain runTestMain

makeTestMain: $(TEST_OBJS)
	rm -rf testTrader
	$(LINK) -o testTrader $^ $(LIBS)
	
runTestMain: 
	LD_LIBRARY_PATH=./lib SO_AccountsDir=./ACCOUNTS_DIR SO_StockData=./data/testStockFile.txt ./testTrader
	
runMain:
	LD_LIBRARY_PATH=./lib SO_AccountsDir=./ACCOUNTS_DIR SO_StockData=./data/StockFile.txt ./ProgramTrader
	
lib: $(PROCS)
	g++ -Wall -fPIC -O3 -std=c++11 -c -o procedure.o ./proc/$(PROC).cpp
	ar rs ./procLibraries/lib$(PROC).a procedure.o

clean:
	rm -rf *.o *.d ProgramTrader testTrader Test/*.o

tar: clean
	tar zcvf testMain.tgz $(SOURCE) *.h Makefile

help:
	@echo "	make testMain  - builds the unit tests"
	@echo "	make main  - builds the main program with default procedure"
	@echo "	make all   - builds the unit tests"
	@echo "	make       - same as make all"
	@echo "	make lib   - builds a static library in ./procLibraries,"
	@echo "		syntax: make shared PROC=<nameOfProcedure>"
	@echo "	make setLib- set the library"
	@echo "		syntax: make setLib PROC=<nameOfProcedure>"
	@echo "	make clean - remove .o .d core main testMain"
	@echo "	make tar   - make a tarball of .cpp and .h files"
	@echo "	make help  - this message"

-include $(SOURCE_TEST:.cpp=.d)

%.d: %.cpp
	@set -e; /usr/bin/rm -rf $@;$(GCC) -MM $< $(CXXFLAGS) > $@

