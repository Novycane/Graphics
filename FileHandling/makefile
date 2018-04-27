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
all:	FileHandling.o

FileHandling.o: ObjFile.o
	-@ECHO -n "Creating FileHandling.o"
	-@ld -r $(TEMP)ObjFile.o -o $(TEMP)FileHandling.o
	-@ECHO "...ok"

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	$(REM) $(TEMP)ObjFile.o

Test: FileHandling.o
	-@ECHO "Testing File Handling Routines"
	-@$(CC) $(CFLAGS) $(TEST)ObjFile.test.c -o $(TEMP)ObjFile.test.o
	-@$(CC) $(TEMP)FileHandling.o $(TEMP)ObjFile.test.o -o $(TEMP)ObjFile$(EXT)
	-@$(TEMP)ObjFile$(EXT)

ObjFile.o: ObjFile.c ObjFile.h
	-@ECHO -n "Building ObjFile.o"
	-@$(CC) $(CFLAGS) ObjFile.c -o $(TEMP)ObjFile.o
	-@ECHO "...ok"