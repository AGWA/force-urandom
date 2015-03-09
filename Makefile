CFLAGS ?= -Wall -O2
PREFIX = /usr
LIBDIR = $(PREFIX)/lib
BINDIR = $(PREFIX)/bin

all: libforceurandom.so

libforceurandom.so: libforceurandom.c
	$(CC) $(CFLAGS) -fPIC -rdynamic -shared -ldl -o $@ $<

clean:
	rm -f libforceurandom.so

install:
	install -d $(DESTDIR)$(LIBDIR) $(DESTDIR)$(BINDIR)
	install -m 644 libforceurandom.so $(DESTDIR)$(LIBDIR)/
	install -m 755 force-urandom $(DESTDIR)$(BINDIR)/

.PHONY: all clean install
