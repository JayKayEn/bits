CC := gcc-6
CFLAGS := -g -Ofast -std=c11
WFLAGS := -Wall -Werror -Wextra -Wpedantic -Wfatal-errors
FFLAGS := -floop-optimize -funroll-loops

# AR := libtool -static

OBJD := obj
TEST := test
OBJS := $(OBJD)/bits.o              \
		$(OBJD)/print.o             \
		$(OBJD)/random.o            \
		$(OBJD)/timer.o             \
		$(OBJD)/random.o            \
		$(OBJD)/serial.o            \
		$(OBJD)/test_funcs.o        \
		$(OBJD)/test_suite.o
HEAD := inc/extint.h                \
		inc/N.h

.PRECIOUS: $(OBJD)/%.o

all: $(TEST)

run: $(TEST)
	@echo ""
	./$(TEST)

# lib: $(OBJD)/bitc.o
# 	$(AR) -o libbits.a $<

$(TEST): $(OBJD)/$(TEST).o $(OBJS)
	$(CC) $(CFLAGS) $(WFLAGS) $(FFLAGS) -o $@ $^

$(OBJD)/$(TEST).o: $(TEST).c $(HEAD)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(WFLAGS) $(FFLAGS) -c -o $@ $<

$(OBJD)/%.o: %.c %.h $(HEAD)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(WFLAGS) $(FFLAGS) -c -o $@ $<

$(OBJD)/%.o: util/%.c util/%.h $(HEAD)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(WFLAGS) $(FFLAGS) -c -o $@ $<

$(OBJD)/%.o: testing/%.c testing/%.h $(HEAD)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(WFLAGS) $(FFLAGS) -c -o $@ $<

clean:
	/bin/rm -rf *~ $(OBJD) $(TEST) *.dSYM