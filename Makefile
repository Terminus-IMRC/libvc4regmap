all:

PREFIX ?= /usr/local

MKDIR := mkdir
INSTALL := install

.PHONY: all
all:

.PHONY: install
install:
	$(MKDIR) -p "$(DESTDIR)/$(PREFIX)/include/vc4regmap"
	$(INSTALL) -m 644 -t "$(DESTDIR)/$(PREFIX)/include" include/vc4regmap.h
	$(INSTALL) -m 644 -t "$(DESTDIR)/$(PREFIX)/include/vc4regmap" include/vc4regmap/v3d.h
