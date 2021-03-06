SHELL = /bin/bash
CC = g++
CFLAGS = -c -O2 -std=c++11 -I $(LIB_PATH)
LDFLAGS = -O2 -std=c++11 -I $(LIB_PATH)

LIB_PATH = .
LIB = 	$(LIB_PATH)/process.cc \
	$(LIB_PATH)/plantri.c
LIB_OBJ = $(LIB:.cc=.o) \
	$(LIB_PATH)/plantri.o

PARSE_PATH = .
PARSE_SRC = $(PARSE_PATH)/parse.cc
PARSE_OBJ = $(PARSE_SRC:.c=.o)

all: lib parse

lib: $(LIB_OBJ)

parse: lib $(PARSE_OBJ) 
	$(CC) $(LDFLAGS) $(LIB_PATH)/process.o $(PARSE_OBJ) -o $(PARSE_PATH)/parse

# ref: http://mrbook.org/tutorial/make
.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(PARSE_PATH)/*.o \
	$(PARSE_PATH)/parse
