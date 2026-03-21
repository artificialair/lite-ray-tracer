CC=gcc
ASM=as
TARGET_EXEC = tracer

OBJ_DIR=obj
BIN_DIR=bin
LIB_DIR=lib
SRC_DIR=src

DEPS = $(shell find $(LIB_DIR)/ -name "*.h")

C_OBJ = $(patsubst %.c, %.o, $(shell find . -name "*.c"))
ASM_OBJ = $(patsubst %.asm, %.o, $(shell find . -name "*.asm"))

CFLAGS = -c -g -O3 -nostdlib -I lib/


%.o: %.asm 
	$(ASM) $< -o $@

%.o: %.c $(DEPS)
	gcc $(CFLAGS) $< -o $@

.PHONY: tracer
$(BIN_DIR)/$(TARGET_EXEC): $(C_OBJ) $(ASM_OBJ)
	$(CC) $(ASM_OBJ) $(C_OBJ) -o $@

.PHONY: clean
clean:
	rm -f src/*.o
	rm -f ./bin/$(TARGET_EXEC)

.SILENT:
.PHONY: run
run:
	make $(BIN_DIR)/$(TARGET_EXEC)
	@echo "------ OUTPUT ------"
	@echo $(./$(BIN_DIR)/$(TARGET_EXEC))
	@echo "------ OUTPUT ------"
	make clean
