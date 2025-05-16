CC = gcc
SRC = src/main.c src/handlers.c
OUT = bin/random_sort

PLATFORM ?= mac

ifeq ($(PLATFORM), mac) #default, adjust path if needed
    OPENSSL_INCLUDE = /opt/homebrew/opt/openssl/include
    OPENSSL_LIB = /opt/homebrew/opt/openssl/lib
else ifeq ($(PLATFORM), linux)
    OPENSSL_INCLUDE = /usr/include
    OPENSSL_LIB = /usr/lib
endif

CFLAGS = -Wall -Wextra -Iinclude -I$(OPENSSL_INCLUDE)
LDFLAGS = -L$(OPENSSL_LIB) -lssl -lcrypto

all:
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

clean:
	rm -rf bin