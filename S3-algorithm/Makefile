CC		 = g++
CFLAGS	 = -Wall -I'/usr/include' #-DDEBUG_RESULT
LDFLAGS  = -L'/usr/local/lib' -lm -lgflags -lprotobuf
SRC_DIR  = ./src
INC_DIR  = ./inc
OBJ_DIR	 = obj
SHARED_INC_DIR = ../S1-sharedCode/inc
SHARED_OBJ_DIR = ../S1-sharedCode/obj

SRC_FILES := $(shell ls $(SRC_DIR)/*.cpp;)
OBJ_FILES := ${SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o}
SHARED_OBJ_FILES := $(shell ls $(SHARED_OBJ_DIR)/*.o 2> /dev/null;)

all: alg viewer


alg: $(OBJ_DIR) $(OBJ_FILES)
	@$(CC) -I$(INC_DIR) -I$(SHARED_INC_DIR) -c prog/alg.cpp $(CFLAGS) \
															 -o $(OBJ_DIR)/alg.o
	@$(CC) $(LDFLAGS) -o alg $(OBJ_FILES) $(SHARED_OBJ_FILES) $(OBJ_DIR)/alg.o

viewer: $(OBJ_DIR) $(OBJ_FILES)
	@$(CC) -I$(INC_DIR) -I$(SHARED_INC_DIR) -c prog/viewer.cpp $(CFLAGS) \
														-o $(OBJ_DIR)/viewer.o
	@$(CC) $(LDFLAGS) -o viewer $(OBJ_FILES) $(SHARED_OBJ_FILES) \
															$(OBJ_DIR)/viewer.o

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@$(CC) -I$(INC_DIR) -I$(SHARED_INC_DIR) -c $< $(CFLAGS) -o $@

clean:
	@rm -f alg viewer
	@rm -Rf $(OBJ_DIR)

