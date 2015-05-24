CC=gcc
OS=WIN
#OS = LINUX
FINAL_TARGET= RTS
ifeq ($(OS),WIN)
	DEFINE= -D$(OS)
	LIBS = -L"./lib/" -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
	clean = del /f $(OBJ_DIR)\*.o $(BIN_DIR)\$(FINAL_TARGET).exe
else
	DEFINE = -D$(OS)
	LIBS = -lSDL2 -lSDL2_image -lSDL2_ttf
	clean = rm -f $(OBJ_DIR)/*.o $(BIN_DIR)/$(FINAL_TARGET)
endif
CFLAGS=$(DEFINE) -W -Wall -ansi -pedantic
INCLUDE_DIR  = -I/usr/include -Isrc -I"./include/"

OBJ_DIR = obj
SRC_DIR = src
BIN_DIR = bin
SRCS= case.c terrain.c file.c filePath.c uniteBase.c unite.c batimentBase.c batiment.c tabDyn.c joueur.c afficheSDL.c jeu.c main.c
default: $(BIN_DIR)/$(FINAL_TARGET)

$(BIN_DIR)/$(FINAL_TARGET): $(SRCS:%.c=$(OBJ_DIR)/%.o)
	$(CC) -o $@ $^ $(LIB_DIR) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $(CFLAGS) $(INCLUDE_DIR) $< -o $@

clean:
	$(clean)
