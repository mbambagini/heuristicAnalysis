CC		 = g++
CFLAGS	 = -Wall -I'/usr/include'
LDFLAGS  = -lm -lgflags -L'/usr/local/lib' -lprotobuf
OBJ_DIR	 = obj
SHARED_INC_DIR = ../sharedCode/inc
SHARED_OBJ_DIR = ../sharedCode/obj


SHARED_OBJ_FILES := $(shell ls $(SHARED_OBJ_DIR)/*.o 2> /dev/null;)

all: sim viewer

sim:
	@$(CC) $(LDFLAGS) -I$(SHARED_INC_DIR) sim.cpp -o sim $(SHARED_OBJ_FILES)

viewer:
	@$(CC) $(LDFLAGS) -I$(SHARED_INC_DIR) viewer.cpp -o viewer $(SHARED_OBJ_FILES)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@rm -f sim
	@rm -f viewer
	@rm -Rf $(OBJ_DIR)

