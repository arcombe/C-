# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = $(CXX)

DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wold-style-cast 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g -L.
LDLIB = -l
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS = spell setup

all: $(PROGS)

# Targets rely on implicit rules for compiling and linking
setup: setup.o 
spell: spell.o dictionary.o word.o

# Phony targets
.PHONY: all clean

# Standard clean
clean:
	rm -f *.o $(PROGS)

# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
