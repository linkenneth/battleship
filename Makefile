# === VARIOUS VARIABLE ===
CFLAGS = -std=c99 -g
SOURCES = $(wildcard src/*.c)
HEADERS = $(wildcard src/*.h)
OBJECTS = $(patsubst src/%, build/%, $(SOURCES:.c=.o))

# === MACHO MACROS ===
.PHONY: default clean compile git run

default: compile

compile: $(OBJECTS)
	cc $(CFLAGS) -o build/battleInTheC $(OBJECTS) -lm

clean:
	rm -f build/*

build/%.o: src/%.c
	cc $(CFLAGS) -c -o $@ $<

git:
	git add -A
	git commit -m "auto-commit via MAKE"

run:
	build/battleInTheC
