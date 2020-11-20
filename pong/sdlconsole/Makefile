CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -pedantic -g

ifeq "$(origin GCC4_V)" "environment"
# ldflags for Solaris
LDFLAGS = -L/sw/gcc-${GCC4_V}/lib -static-libstdc++ -lSDL
else
# ldflags for Linux
LDFLAGS = -lSDL
endif

# to build 'hello_world' we need 'hello_world.o', 'console.o' and 'color.o'
hello_world: hello_world.o console.o color.o
	$(CXX) $^ $(LDFLAGS) ${X} -o $@


# se make manual for complete information
# http://www.gnu.org/software/make/manual/make.html
#
# this is an example explanatory make rule:
the_file_we_try_to_build: file_we_need_1.o file_we_need_2.o
	command to create $@ from $^ (or from $<)
#
# $@ denotes "the file we try to build"
# $^ denotes "all files we need, listed after the ':' "
# $< denotes "the first of the files we need"


# type 'make all' or 'gmake all' to build everything
all: hello_world hello_colors pong test


hello_colors: hello_colors.o console.o color.o
	$(CXX) $^ $(LDFLAGS) -o $@

pong: pong.o console.o color.o
	$(CXX) $^ $(LDFLAGS) -o $@

test: test.o console.o color.o
	$(CXX) $^ $(LDFLAGS) -o $@

# to build an *.o file we need corresponding *.cc file
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

# to clean up compiler-generated files
clean:
	\rm -f *.o *.stackdump a.out hello_world hello_colors pong test

# to clean up real good
zap: clean
	\rm -f *~
