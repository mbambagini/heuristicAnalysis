CC		 = g++
CFLAGS	 = -Wall -I'/usr/include'
LDFLAGS  = -L'/usr/local/lib' -lm -lgflags -lconfig++ -lprotobuf
SRC_DIR  = ./src
INC_DIR  = ./inc
OBJ_DIR	 = ./obj

SRC_FILES := $(shell ls $(SRC_DIR)/*.cpp;)
OBJ_FILES := ${SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o}

all: $(OBJ_DIR) $(OBJ_FILES)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@$(CC) -I$(INC_DIR) -c $< $(CFLAGS) -o $@

clean:
	@rm -Rf $(OBJ_DIR)

proto:
	@protoc --cpp_out=. problem.proto
	@mv problem.pb.h inc/
	@mv problem.pb.cc src/problem.pb.cpp
	@protoc --cpp_out=. simulations.proto
	@mv simulations.pb.h inc/
	@mv simulations.pb.cc src/simulations.pb.cpp
	@protoc --cpp_out=. results.proto
	@mv results.pb.h inc/
	@mv results.pb.cc src/results.pb.cpp

