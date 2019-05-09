CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -MMD -Werror=vla
EXEC = a4q5
OBJECTS = main.o textprocess.o textdecorator.o echo.o doublewords.o dropfirst.o allcaps.o count.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
