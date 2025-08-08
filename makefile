# Nome do compilador
CC = g++-13

# Flags de compilação
CFLAGS = -g -Wall

# Flags de linkagem
LDFLAGS = -lglut -lGLU -lGL

# Pastas
SRC_DIR = src
OBJ_DIR = obj

# Lista automática de .cpp e .hpp
SRC = $(wildcard $(SRC_DIR)/*.cpp)
HEADERS = $(wildcard $(SRC_DIR)/*.hpp)

# Arquivos objeto
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Nome do executável
OUT = big_wheel

# Regra padrão
all: $(OUT)

# Linkagem final
$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Compilar cada .cpp para .o e depender dos headers
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Criar pasta obj se não existir
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rodar
run: $(OUT)
	./$(OUT)

# Limpar
clean:
	rm -rf $(OUT) $(OBJ_DIR)
