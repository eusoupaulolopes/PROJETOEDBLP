CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp funcoes/inserir.cpp suporte.cpp funcoes/ListaComSentinelas.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=buscaIMD

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
