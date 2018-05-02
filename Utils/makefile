ifeq ($(OS),Windows_NT)
EXT = .exe
REM = rm
CC 			= gcc
else
CC 			= clang
REM = del
endif

# ----- Compiler
CFLAGS		= -g -Wall -c
TFLAGS		= -g -Wall -std=c++14	
LFLAGS		= -g -lc++

# ----- Directories
TEMP		= Temp/
BIN			= bin/
TEST		= Test/

# ----- Targets
all:	CPUInfo.o
	-@ECHO -n "Creating Graphics.o"
	-@ld -r $(TEMP)CPUInfo.o -o $(TEMP)Utils.o
	-@ECHO "...ok"

.PHONY:
clean:
	-@ECHO "Cleaning Files"
	$(REM) $(TEMP)Utils.o

Test: CPUInfo.o
	-@ECHO "Testing CPUInfo.c"
	-@$(CC) $(CFLAGS) $(TEST)CPUInfo.test.c -o $(TEMP)CPUInfo.test.o
	-@$(CC) $(TEMP)CPUInfo.o $(TEMP)CPUInfo.test.o -o $(TEMP)CPUInfo$(EXT)
	-@$(TEMP)CPUInfo$(EXT)

CPUInfo.o: CPUInfo.c CPUInfo.h
	-@ECHO -n "Building CPUInfo.o"
	-@$(CC) $(CFLAGS) CPUInfo.c -o $(TEMP)CPUInfo.o
	-@ECHO "...ok"