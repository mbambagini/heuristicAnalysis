CC		 = g++
CFLAGS	 = -Wall -I'/usr/include'
LDFLAGS  = -L'/usr/local/lib' -lm -lgflags -lprotobuf
PRG_SW	 = software
PRG_HW	 = hardware
PRG_HW_V = hardware_viewer
PRG_SW_V = software_viewer
SRC_DIR  = ./src
INC_DIR  = ./inc
OBJ_DIR	 = obj
SHARED_INC_DIR = ../sharedCode/inc
SHARED_OBJ_DIR = ../sharedCode/obj

SRC_FILES := $(shell ls $(SRC_DIR)/*.cpp;)
OBJ_FILES := ${SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o}
SHARED_OBJ_FILES := $(shell ls $(SHARED_OBJ_DIR)/*.o 2> /dev/null;)

all: software hardware viewer


software: $(OBJ_DIR) $(OBJ_FILES)
	@$(CC) -I$(INC_DIR) -I$(SHARED_INC_DIR) -c prog/software.cpp $(CFLAGS) \
														-o $(OBJ_DIR)/software.o
	@$(CC) $(LDFLAGS) -o $(PRG_SW) $(OBJ_FILES) $(SHARED_OBJ_FILES) \
														   $(OBJ_DIR)/software.o

hardware: $(OBJ_DIR) $(OBJ_FILES)
	@$(CC) -I$(INC_DIR) -I$(SHARED_INC_DIR) -c prog/hardware.cpp $(CFLAGS) \
														-o $(OBJ_DIR)/hardware.o
	@$(CC) $(LDFLAGS) -o $(PRG_HW) $(OBJ_FILES) $(SHARED_OBJ_FILES) \
														   $(OBJ_DIR)/hardware.o

viewer: $(OBJ_DIR) $(OBJ_FILES)
	@$(CC) -I$(INC_DIR) -I$(SHARED_INC_DIR) -c prog/hardware_viewer.cpp \
									   $(CFLAGS) -o $(OBJ_DIR)/hardware_viewer.o
	@$(CC) $(LDFLAGS) -o $(PRG_HW_V) $(OBJ_FILES) $(SHARED_OBJ_FILES) \
													$(OBJ_DIR)/hardware_viewer.o
	@$(CC) -I$(INC_DIR) -I$(SHARED_INC_DIR) -c prog/software_viewer.cpp \
									   $(CFLAGS) -o $(OBJ_DIR)/software_viewer.o
	@$(CC) $(LDFLAGS) -o $(PRG_SW_V) $(OBJ_FILES) $(SHARED_OBJ_FILES) \
													$(OBJ_DIR)/software_viewer.o


$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	@$(CC) -I$(INC_DIR) -I$(SHARED_INC_DIR) -c $< $(CFLAGS) -o $@

clean:
	@rm -f $(PRG_SW)
	@rm -f $(PRG_HW)
	@rm -f $(PRG_SW_V)
	@rm -f $(PRG_HW_V)
	@rm -Rf $(OBJ_DIR)

