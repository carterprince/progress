CFLAGS=-O3 -Wall -Wextra -lX11 -lpci
PREFIX=/usr/local

all: progress install

classchange: classchange.c
	$(CC) progress.c -o progress $(CFLAGS)
	strip progress

install: progress
	mkdir -p $(PREFIX)/bin
	install ./progress $(PREFIX)/bin/progress
