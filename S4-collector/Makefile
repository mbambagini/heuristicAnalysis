CC		 = g++
CFLAGS	 = -Wall -I'/usr/include'
LDFLAGS  = -lm -lgflags -L'/usr/local/lib' -lprotobuf
OBJ_DIR	 = obj
SHARED_INC_DIR = ../S1-sharedCode/inc
SHARED_OBJ_DIR = ../S1-sharedCode/obj

SHARED_OBJ_FILES := $(shell ls $(SHARED_OBJ_DIR)/*.o 2> /dev/null;)

all: collector

collector:
	@$(CC) -I$(SHARED_INC_DIR) $(CFLAGS) $(LDFLAGS) collector.cpp  -o collector $(SHARED_OBJ_FILES)

viewer:
	@$(CC) -I$(SHARED_INC_DIR) $(CFLAGS) $(LDFLAGS) viewer.cpp  -o viewer $(SHARED_OBJ_FILES)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@rm -f collector
	@rm -f viewer
	@rm -Rf $(OBJ_DIR)

