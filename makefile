ifeq ($(OS),Windows_NT)
EXT = .exe
REM = rm
else
REM = del
endif

# ----- Compiler
CC 			= clang++
CFLAGS		= -g -Wall -c -std=c++14
TFLAGS		= -g -Wall -std=c++14	
LFLAGS		= -g -lc++

# ----- Directories
TEMP		= ../../temp/
BIN			= ../../bin/
TEST		= ../../test/
COMMON		= ../

# ----- Targets
all:	SIMD.o
	-@ECHO -n "Creating Graphics.o"
	-@ld -r $(TEMP)SIMD.o -o $(TEMP)Graphics.o
	-@ECHO "...ok"

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	rm $(TEMP)Factorial.o
	rm $(TEMP)Gamma.o
	rm $(TEMP)Random.o
	rm $(TEMP)Stats.o

Test: SIMD.o
	-@ECHO "Testing SIMD.c"
	-@$(CC) $(TEMP)SIMD.o $(TEMP)SIMD.test.o -o $(TEMP)SIMD$(EXT)
	-@$(TEMP)SIMD$(EXT)

SIMD.o: SIMD.c SIMD.h
	-@ECHO -n "Building Factorial"
	-@$(CC) $(CFLAGS) SIMD.c -o $(TEMP)SIMD.o
	-@ECHO "...ok"