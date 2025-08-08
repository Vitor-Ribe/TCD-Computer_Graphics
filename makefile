# Nome do compilador
CC = g++-13

# Flags de compilação
CFLAGS = -g -Wall

# Flags de linkagem para as bibliotecas OpenGL, GLU e GLUT
LDFLAGS = -lglut -lGLU -lGL

# Nome do arquivo fonte e do executável
SRC = src/main.cpp src/globals.cpp src/control.cpp
HEADERS = src/globals.hpp src/control.hpp
OUT = big_wheel

# Regra padrão: compilar o executável
all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC) $(LDFLAGS)

# Target para executar o programa
run: $(OUT)
	./$(OUT)

# Limpa os arquivos gerados
clean:
	rm -f $(OUT)