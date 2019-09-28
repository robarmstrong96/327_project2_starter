all: src/array_functions.cpp /src/array_functions.h /src/constants.h /src/Project2.cpp /src/utilities.cpp /src/utilities.h
	 g++ -g -Wall -o myexe /src/array_functions.cpp /src/array_functions.h /src/constants.h /src/Project2.cpp /src/utilities.cpp /src/utilities.h

 clean:
	 rm -f myexe *.o
