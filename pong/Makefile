CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -Weffc++ -pedantic -g

ifeq "$(origin GCC4_V)" "environment"
# ldflags for Solaris
LDFLAGS = -L/sw/gcc-${GCC4_V}/lib -static-libstdc++ -lncursesw
CXXFLAGS += -D_SOLARIS_
else
# ldflags for Linux, Ubuntu 13.04 need "sudo apt-get install ncurses-dev"
LDFLAGS = -lncurses
endif

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
all: pong

pong: main.o pong.o paddle.o ball.o console.o
	$(CXX) $^ $(LDFLAGS) -o $@

# to build an *.o file we need corresponding *.cc file
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

# to clean up compiler-generated files
clean:
	\rm -f *.o *.stackdump a.out pong

# to clean up real good
zap: clean
	\rm -f *~
