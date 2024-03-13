CC = gcc

RM = rm -rf
MKDIR = mkdir

CFLAGS = -std=c99 -O2 -Wall -Wextra -Wpedantic

SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))

TARGET = bin/grades

ifeq ($(OS),Windows_NT)
RM = cmd /C rd /s /q
MKDIR = cmd /C mkdir
endif

all: init $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $^ -o $@

obj/%.o: src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

init:
ifeq (,$(wildcard obj))
	-$(MKDIR) obj
endif
ifeq (,$(wildcard bin))
	-$(MKDIR) bin
endif

clean:
ifneq (,$(wildcard obj))
	-$(RM) obj
endif
ifneq (,$(wildcard bin))
	-$(RM) bin
endif
