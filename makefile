CC := g++

SRC_DIR := .
BUILD_DIR := build
STD := c++11
OUTPUT := output 

build_dir:
	mkdir -p ${BUILD_DIR}

compile: build_dir \
		${BUILD_DIR}/main.o 

${BUILD_DIR}/main.o:${SRC_DIR}/main.cpp
	${CC} -std=${STD} -c ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/main.o -I .

link:compile
	${CC} ${BUILD_DIR}/*.o -o ${BUILD_DIR}/main.exe -Llib -lfreetypedll
	
run:link
	${BUILD_DIR}/main

assemble:link
	mkdir -p ${BUILD_DIR}/${OUTPUT}
	cp -r assets ${BUILD_DIR}/${OUTPUT}
	cp -r shader ${BUILD_DIR}/${OUTPUT}
	cp -r ${BUILD_DIR}/main.exe ${BUILD_DIR}/${OUTPUT}
	cp -r *.dll ${BUILD_DIR}/${OUTPUT}

clean:
	rm -f ${BUILD_DIR}/*.o 
	rm -f ${BUILD_DIR}/main.exe