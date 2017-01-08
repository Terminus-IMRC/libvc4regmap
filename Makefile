all:

PREFIX ?= /usr/local

TARGETS := libvc4regmap.so libvc4regmap.a
SRCS := vc4regmap.c
OBJS := $(SRCS:%.c=%.c.o)
EXTRACFLAGS := -pipe -Wall -Wextra -O2 -g -Iinclude/ -I/opt/vc/include -I/opt/vc/include/interface/vcos/pthreads/ -I/opt/vc/include/interface/vmcs_host/linux/

CC := gcc
AR := ar
ARFLAGS := cr
RANLIB := ranlib
MKDIR := mkdir
INSTALL := install
RM := rm -f

COMPILE.o = $(CC) $(CFLAGS) $(EXTRACFLAGS) $(CPPFLAGS) $(EXTRACPPFLAGS) $(TARGET_ARCH) -shared
COMPILE.c = $(CC) $(CFLAGS) $(EXTRACFLAGS) $(CPPFLAGS) $(EXTRACPPFLAGS) $(TARGET_ARCH) -c

.PHONY: all
all: $(TARGETS)

libvc4regmap.so: $(OBJS)
	$(COMPILE.o) $(OUTPUT_OPTION) $^

libvc4regmap.a: $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
	$(RANLIB) $@

%.c.o: %.c
	$(COMPILE.c) $(OUTPUT_OPTION) $<

.PHONY: install
install: all
	$(MKDIR) -p "$(DESTDIR)/$(PREFIX)/lib" "$(DESTDIR)/$(PREFIX)/include/vc4regmap"
	$(INSTALL) -m 644 -t "$(DESTDIR)/$(PREFIX)/lib" libvc4regmap.so libvc4regmap.a
	$(INSTALL) -m 644 -t "$(DESTDIR)/$(PREFIX)/include" include/vc4regmap.h
	$(INSTALL) -m 644 -t "$(DESTDIR)/$(PREFIX)/include/vc4regmap" include/vc4regmap/v3d.h

.PHONY: clean
clean:
	$(RM) $(TARGETS)
	$(RM) $(OBJS)
