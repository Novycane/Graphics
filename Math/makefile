ifeq ($(OS),Windows_NT)
EXT = .exe
REM = rm
else
REM = del
endif

# ----- Compiler
CC 			= clang
CFLAGS		= -g -Wall -c
TFLAGS		= -g -Wall -std=c++14	
LFLAGS		= -g -lc++

# ----- Directories
TEMP		= Temp/
BIN			= bin/
TEST		= Test/

# ----- Targets
all:	SIMD.o
	-@ECHO -n "Creating Math.o"
	-@ld -r $(TEMP)SIMD.o -o $(TEMP)Math.o
	-@ECHO "...ok"

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	$(REM) $(TEMP)SIMD.o

Test: SIMD.o
	-@ECHO "Testing Math.c"
	-@$(CC) $(CFLAGS) $(TEST)SIMD.test.c -o $(TEMP)SIMD.test.o
	-@$(CC) $(TEMP)SIMD.o $(TEMP)SIMD.test.o -o $(TEMP)SIMD$(EXT)
	-@$(TEMP)SIMD$(EXT)

SIMD.o: SIMD.c SIMD.h
	-@ECHO -n "Building Math.o"
	-@$(CC) $(CFLAGS) SIMD.c -o $(TEMP)SIMD.o
	-@ECHO "...ok"