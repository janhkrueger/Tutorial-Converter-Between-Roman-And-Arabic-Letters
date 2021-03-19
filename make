CC=g++
CFLAGS=
CWARNINGS=-Wextra -Wconversion -Wsign-conversion -Wformat-nonliteral -Wstack-protector -Wno-unused-parameter -Wformat=2 -Wformat-security -Winit-self -Wuninitialized -Wswitch-default -Wswitch-enum -Wunused-but-set-parameter -Wunused-parameter -Wunused-but-set-variable -Wfloat-equal -Wshadow -Wunreachable-code
CLIBS=

SOURCES=main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

all:
	export GLIBCXX_FORCE_NEW=true
	$(CC) $(CFLAGS) -O3 $(SOURCES) $(CLIBS) $(CINCLUDES) -o ConverterBetweenRomanAndArabicNumbers
	export GLIBCXX_FORCE_NEW=false
