CC=g++
CFLAGS=-c -Wall -std=c++11
LDFLAGS=
SOURCES=main.cpp funcoes/inserir.cpp suporte.cpp funcoes/estruturas.cpp funcoes/remover.cpp funcoes/listar.cpp funcoes/buscar.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=buscaIMD

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
