#!/bin/make -f

PREFIX  ?= /usr/local
NAME    ?= AH
INSTALL ?= ${DESTDIR}${PREFIX}/bin/${NAME}

.PHONY: all clean install uninstall

all: ${NAME}

clean:
	rm ${NAME}

install: ${INSTALL}

uninstall:
	rm ${INSTALL}

${INSTALL}: ${NAME}
	cp $< $@

${NAME}: AH.c
	${CC} -o $@ $<
