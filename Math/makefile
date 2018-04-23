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
all:	Math.o

Math.o: Primatives.o Polygon.o
	-@ECHO -n "Creating Math.o"
	-@ld -r $(TEMP)Primatives.o $(TEMP)Polygon.o -o $(TEMP)Math.o
	-@ECHO "...ok"

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	$(REM) $(TEMP)SIMD.o

Test: Math.o
	-@ECHO "Testing Math Routines"
	-@$(CC) $(CFLAGS) $(TEST)Primatives.test.c -o $(TEMP)Primatives.test.o
	-@$(CC) $(TEMP)Math.o $(TEMP)Primatives.test.o -o $(TEMP)Primatives$(EXT)
	-@$(TEMP)Primatives$(EXT)

	-@$(CC) $(CFLAGS) $(TEST)Polygon.test.c -o $(TEMP)Polygon.test.o
	-@$(CC) $(TEMP)Math.o $(TEMP)Polygon.test.o -o $(TEMP)Polygon$(EXT)
	-@$(TEMP)Polygon$(EXT)

	
Bench: Primatives.o
	-@ECHO "Benchmarking Math Routines..."
	-@$(CC) $(CFLAGS) $(TEST)Primatives.performance.c -o $(TEMP)Primatives.performance.o
	-@$(CC) $(TEMP)Primatives.o $(TEMP)Primatives.performance.o -o $(TEMP)Bench$(EXT)
	-@$(TEMP)Bench$(EXT)

Primatives.o: Primatives.c Primatives.h
	-@ECHO -n "Building Primatives.o"
	-@$(CC) $(CFLAGS) Primatives.c -o $(TEMP)Primatives.o
	-@ECHO "...ok"

Polygon.o: Polygon.c Polygon.h
	-@ECHO -n "Building Polygon.o"
	-@$(CC) $(CFLAGS) Polygon.c -o $(TEMP)Polygon.o
	-@ECHO "...ok"