CC := gcc
CFLAGS := -Wall -Werror -pedantic -ansi -std=c99

SRC_DIR= src
OBJ_DIR = obj
BIN_DIR = bin

TARGET= ${BIN_DIR}/game
SRC_FILES = ${wildcard ${SRC_DIR}/*.c}
OBJ_FILES = ${SRC_FILES:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

# TARGETS
${TARGET}: ${OBJ_FILES} | ${BIN_DIR}
	${CC} $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf ${OBJ_DIR} ${BIN_DIR}

${OBJ_DIR}:
	mkdir -p ${OBJ_DIR}

${BIN_DIR}:
	mkdir -p ${BIN_DIR}

.PHONY: clean
