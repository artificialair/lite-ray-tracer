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

CFLAGS = -O3 -c -g -nostdlib -I lib/ -Wno-builtin-declaration-mismatch -std=c23


%.o: %.asm 
	$(ASM) $< -o $@

%.o: %.c $(DEPS)
	gcc -fPIC $(CFLAGS) $< -o $@

.PHONY: tracer
$(BIN_DIR)/$(TARGET_EXEC): $(C_OBJ) $(ASM_OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) $(ASM_OBJ) $(C_OBJ) -o $@

.PHONY: python
python: $(C_OBJ) $(ASM_OBJ)
	mkdir -p $(BIN_DIR)
	$(CC) -fPIC -shared $(ASM_OBJ) $(C_OBJ) -o tracer.so -lm


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
