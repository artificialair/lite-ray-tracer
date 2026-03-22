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

CFLAGS = -c -g -nostdlib -O3 -I lib/ -Wno-builtin-declaration-mismatch 


%.o: %.asm 
	$(ASM) $< -o $@

%.o: %.c $(DEPS)
	gcc $(CFLAGS) $< -o $@

.PHONY: tracer
$(BIN_DIR)/$(TARGET_EXEC): $(C_OBJ) $(ASM_OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) $(ASM_OBJ) $(C_OBJ) -o $@

.PHONY: clean
clean:
	rm -f src/*.o
	rm -f ./bin/$(TARGET_EXEC)

# .SILENT:
.PHONY: run
run:
	make $(BIN_DIR)/$(TARGET_EXEC)
	@echo "------ OUTPUT ------"
	./$(BIN_DIR)/$(TARGET_EXEC)
	@echo "------ OUTPUT ------"

.PHONY: run_tests
run_tests:	
	make $(BIN_DIR)/$(TARGET_EXEC)
	@echo "\e[0;34m------ RUNNING TESTS ------\e[0m"
	./$(BIN_DIR)/$(TARGET_EXEC) arg
	@echo "\e[0;34m------ TESTS COMPLETED ------\e[0m"
