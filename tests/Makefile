CC = $(shell which gcc || which clang || which cc)
CFLAGS = -Wall -Wextra -O3 
INCLUDES = -I../include
EXAMPLES = $(wildcard *.c)

UNAME_S := $(shell uname -s || echo Windows_NT)
DESTDIR := lib/

ifeq ($(UNAME_S),Linux)
    EXECUTABLES = $(EXAMPLES:.c=)
    LIBS = -L../$(DESTDIR) -lgtglfw -lGL -lglfw -lm
else ifeq ($(UNAME_S),Darwin)
    EXECUTABLES = $(EXAMPLES:.c=)
    LIBS = -L../$(DESTDIR) -lgtglfw -lglfw -framework OpenGL -lm
else
    EXECUTABLES = $(EXAMPLES:.c=.exe)
    LIBS = -L../$(DESTDIR) -lgtglfw -lglfw3 -lopengl32 -lm
endif

all: $(EXECUTABLES)

%.exe: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ $(LIBS)

%: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@ $(LIBS)

clean:
	rm -f $(EXECUTABLES)

run: $(EXECUTABLES)
	@for exe in $(EXECUTABLES); do \
		echo "Run $$exe..."; \
		./$$exe; \
	done
