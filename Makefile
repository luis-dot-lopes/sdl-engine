
#For compilation in Linux

OBJS = Sources/*.c Sources/shapes/*.c Headers/*

CC = gcc

COMPILER_FLAGS = -w

LINKER_FLAGS = -lSDL2

OBJ_NAME = game

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

