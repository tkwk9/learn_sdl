APP_NAME = main
FRAMEWORKS_DIR = /Library/Frameworks
GLAD_SRC_DIR = ./glad/src
GLAD_INCLUDE_DIR = ./glad/include

all: $(APP_NAME)

$(APP_NAME): main.o glad.o
	clang++ main.o glad.o -o $(APP_NAME) -F$(FRAMEWORKS_DIR) -framework SDL2 -Wl,-rpath,$(FRAMEWORKS_DIR)

main.o: main.cpp
	clang++ -c main.cpp -o main.o -I$(FRAMEWORKS_DIR)/SDL2.framework/Headers -I$(GLAD_INCLUDE_DIR) -F$(FRAMEWORKS_DIR) -framework SDL2

glad.o: $(GLAD_SRC_DIR)/glad.c
	clang++ -c $(GLAD_SRC_DIR)/glad.c -o glad.o -I$(GLAD_INCLUDE_DIR)

clean:
	rm -f $(APP_NAME) main.o glad.o
