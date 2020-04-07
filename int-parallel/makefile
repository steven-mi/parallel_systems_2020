#
# This makefile does many thing by convention which means
# less fiddling arround with the makefile. It is assumed that
# tests end with an _test.c or _test.cpp suffix. All other source
# files are compiled to a single executable, whose main name
# is given with the TARGET macro.
#
# Written by Sebastian Bauer <mail@sebastianbauer.info> for
# lectures at the HTW.
#
# This makefile is released in public domain.
#

# The name of the main executable
TARGET=integrale

# Flags and stuff, change as required
OPTIMIZE=-O3
# Flags for all languages
CPPFLAGS=-ggdb $(OPTIMIZE) -Wall -MMD -MP
# Flags for C only
CFLAGS=-Wmissing-prototypes
# Flags for C++ only
CXXFLAGS=-std=c++11
# Flags for the linker
LDFLAGS=
# Additional linker libs
LDLIBS=-lm 

# Compilers
CC=gcc -fopenmp
CPP=g++ -fopenmp

##############################################################
# Normally there shouldn't be a need to modify the following
# lines, expect for bug fixing and new features.

# The sources that make up the main executable. These are
# all files that end with an .c but do not end with _test.c
SRCS=$(filter-out %_test.c,$(wildcard *.c))
CPPSRCS=$(filter-out %_test.cpp,$(wildcard *.cpp))

# We make up the objects by replacing the .c and .cpp suffixes
# with a .o suffix
OBJS=$(patsubst %.c,%.o,$(SRCS)) $(patsubst %.cpp,%.o,$(CPPSRCS))

# The test sources are assumed to end with _test.c 
TEST_SRCS=$(wildcard *_test.c)

# The test sources for C++ are assumed to end with _test.cpp
TEST_CPPSRCS=$(wildcard *_test.cpp)

# The test objects
TEST_OBJS=$(patsubst %.c,%.o,$(TEST_SRCS)) $(patsubst %.cpp,%.o,$(TEST_CPPSRCS))

# The test executables (without any suffix)
TESTS=$(patsubst %.c,%,$(TEST_SRCS)) $(patsubst %.cpp,%,$(TEST_CPPSRCS))

# The dependency files
DEPS=$(SRCS:.c=.d) $(CPPSRCS:.cpp=.d) $(TEST_SRCS:.c=.d) $(TEST_CPPSRCS:.cpp=.d)

# If we have any C++ sources, we link with CPP
# For this redfine the internal LINK.o macro
ifneq ($(strip $(CPPSRCS)),)
LINK.o = $(CPP) $(LDFLAGS) $(TARGET_ARCH)
endif

# The first target (all) is allways the default target
.PHONY: all
all: build test

# Our buld target depends on the real target
.PHONY: build
build: $(TARGET)

# Our target is built up from the objects
$(TARGET): $(OBJS)

# Our test target
# 
# Here we instruct make to generate a line with all test
# which are all sequentially executed using the $(foreach)
# macro. We conclude with 'true' because the && construct
# awaits an argument on both sides. The 'true' command
# simply returns a success value
.PHONY: test
test: $(TESTS)
	$(foreach T,$(TESTS), ./$(T) &&) true

# Cleanup all generated files
clean:
	rm -Rf $(TEST_OBJS) $(TESTS) $(OBJS) $(TARGET) $(DEPS)

-include $(DEPS)
