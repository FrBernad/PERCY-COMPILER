CFLAGS+=-std=c99

CFLAGS+=-D_POSIX_C_SOURCE -Wall -g -pedantic -pedantic-errors -Wextra 

CFLAGS+=-O3 

CFLAGS+=-Wno-unused-parameter -Wno-implicit-fallthrough

CFLAGS+=-lfl

YACCFLAGS += -d -v -t -Wcounterexamples