CC		 = g++
CFLAGS	 = -Wall -I'/usr/include'
LDFLAGS  = -lm -lgflags -L'/usr/local/lib' -lprotobuf
OBJ_DIR	 = obj
SHARED_INC_DIR = ../S1-sharedCode/inc
SHARED_OBJ_DIR = ../S1-sharedCode/obj

SHARED_OBJ_FILES := $(shell ls $(SHARED_OBJ_DIR)/*.o 2> /dev/null;)

all: power powerN power_alpha

power:
	@$(CC) -I$(SHARED_INC_DIR) $(CFLAGS) $(LDFLAGS) power.cpp  -o power $(SHARED_OBJ_FILES)

powerN:
	@$(CC) -I$(SHARED_INC_DIR) $(CFLAGS) $(LDFLAGS) powerN.cpp  -o powerN $(SHARED_OBJ_FILES)

power_alpha:
	@$(CC) -I$(SHARED_INC_DIR) $(CFLAGS) $(LDFLAGS) power_alpha.cpp  -o power_alpha $(SHARED_OBJ_FILES)

unfeasible:
	@$(CC) -I$(SHARED_INC_DIR) $(CFLAGS) $(LDFLAGS) unfeasible.cpp  -o unfeasible $(SHARED_OBJ_FILES)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@rm -f power powerN power_alpha
	@rm -Rf $(OBJ_DIR)

