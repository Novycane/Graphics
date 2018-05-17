ifeq ($(OS),Windows_NT)
EXT = .exe
REM = rm
CC = gcc
else
CC = clang
REM = del
endif

# ----- Compiler
CFLAGS		= -g -Wall -c
TFLAGS		= -g -Wall -std=c++14	
LFLAGS		= -g -lc++

# ----- Directories
TEMP		= ./Temp/
BIN			= ../bin/
TEST		= ./Test/
COMMON		= ../
MATH		= ../Math/

# ----- Targets
all:	DataStructs.o

DataStructs.o: BSP.o $(MATH)Temp/Primatives.o
	-@ECHO -n "Creating DataStructs.o "
	-@ld -r $(TEMP)BSP.o $(MATH)Temp/Primatives.o -o $(TEMP)DataStructs.o
	-@ECHO "...ok"

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	rm $(TEMP)DataStructs.o
	rm $(TEMP)BSP.o

Test: DataStructs.o
	-@ECHO "Testing DataStructs.o"
	-@$(CC) $(CFLAGS) $(TEST)BSP.test.c -o $(TEMP)BSP.test.o
	-@$(CC) $(TEMP)DataStructs.o $(TEMP)BSP.test.o -o $(TEMP)BSP$(EXT)
	-@$(TEMP)BSP$(EXT)

BSP.o: BSP.c BSP.h 
	-@ECHO -n "Building BSP.o"
	-@$(CC) $(CFLAGS) BSP.c -o $(TEMP)BSP.o
	-@ECHO "...ok"