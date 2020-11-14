SRC = ./src
INC = ./src/include
OBJ = ./obj
 
SOURCE = $(wildcard ${SRC}/*.c)
OBJECT = $(patsubst %.c,${OBJ}/%.o,$(notdir ${SOURCE}))
 
TARGET = bingbg
SRC_TARGET = ./${TARGET}
 
CC = gcc 
CFLAGS = -l curl `xml2-config --cflags --libs` -g -I ${INC} 
 
${SRC_TARGET}:${OBJECT}
	$(CC) -o $@ ${OBJECT} $(CFLAGS)
 
${OBJ}/%.o:${SRC}/%.c 
	$(CC) -o $@ -c $< $(CFLAGS)
 
.PHONY:clean
clean:
	find $(OBJ) -name *.o -exec rm -rf {} \;
	rm -rf $(SRC_TARGET)