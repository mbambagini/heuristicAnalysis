CC		 = g++
CFLAGS	 = -Wall -I'/usr/include'
LDFLAGS  = -lm -lgflags -L'/usr/local/lib' -lprotobuf
OBJ_DIR	 = obj
SHARED_INC_DIR = ../sharedCode/inc
SHARED_OBJ_DIR = ../sharedCode/obj

SHARED_OBJ_FILES := $(shell ls $(SHARED_OBJ_DIR)/*.o 2> /dev/null;)

all: power unfeasible

power:
	@$(CC) -I$(SHARED_INC_DIR) $(CFLAGS) $(LDFLAGS) power.cpp  -o power $(SHARED_OBJ_FILES)

unfeasible:
	@$(CC) -I$(SHARED_INC_DIR) $(CFLAGS) $(LDFLAGS) unfeasible.cpp  -o unfeasible $(SHARED_OBJ_FILES)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@rm -f power unfeasible
	@rm -Rf $(OBJ_DIR)

