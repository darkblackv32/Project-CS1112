all: main

CXX = clang++
override CXXFLAGS += -g -Wno-everything

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
HEADERS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.h' -print)

main: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"

main-debug: $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -O0 $(SRCS) -o "$@"

clean:
	rm -f main main-debug

pr:
	g++  CEmpresa.h CEmpresa.cpp CUsuario.cpp CPelicula.cpp CPelicula.h CUsuario.h signo.h clases.cpp Generator.h -std=c++17 && ./a.out && rm ./a.out