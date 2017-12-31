SHELL = /bin/sh

CC = gcc
RANLIB = ranlib
ARFLAGS = rcs

CFLAGS = -g
ALL_CFLAGS = -Wall -O2 $(CFLAGS)

srcdir = src
BUILDDIR = build
TARGET = bin/lucas_test


SRCS = $(wildcard $(srcdir)/*.c)
OBJS = $(patsubst $(srcdir)/%.c,$(BUILDDIR)/%.o,$(SRCS))
#LDFLAGS = -Llib
#LDLIBS = -lrbmap
CPPFLAGS = -MMD -Iinclude


.PHONY: all
all: $(TARGET)


$(TARGET): $(OBJS)
	@if test ! -d bin; then mkdir bin; fi
	$(CC) $(CPPFLAGS) $(ALL_CFLAGS) $(LDFLAGS) $(OBJS) -o $@ $(LDLIBS)


$(BUILDDIR)/%.o: $(srcdir)/%.c
	@if test ! -d $(BUILDDIR); then mkdir $(BUILDDIR); fi
	$(CC) -c $(CPPFLAGS) $(ALL_CFLAGS) -o $@ $<

.PHONY: clean
clean:
	-$(RM) $(BUILDDIR)/* $(TARGET) *.tgz

.PHONY: test
test:
	@if test ! -d bin; then mkdir bin; fi
	$(CC) $(CPPFLAGS) $(ALL_CFLAGS) $(LDFLAGS) test/map_test.c $(LDLIBS) -o bin/map_test
	$(CC) $(CPPFLAGS) $(ALL_CFLAGS) $(LDFLAGS) test/queue_test.c $(LDLIBS) -o bin/queue_test


-include $(patsubst %.o,%.d,$(OBJS))
