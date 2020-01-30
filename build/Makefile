CC=gcc
CFLAGS+=-Wall -Werror
INC= -I$(PWD)/../inc/
API_SRC= $(PWD)/../src
OUT_DIR=$(PWD)/../bin

SRC=$(API_SRC)/daemon_main.c \
    $(API_SRC)/server_sock.c

all:output_directory daemon_usr

output_directory: ${OUT_DIR}

${OUT_DIR}:
	mkdir -p $(OUT_DIR)

OUTPUT_EXE=$(OUT_DIR)/testApp

daemon_usr:
	$(CC) $(CFLAGS) $(SRC) $(INC) -L$(OUT_DIR) -o $(OUTPUT_EXE)
clean:
	$(RM) $(OUTPUT_EXE) $(PWD)/../src/.*o
