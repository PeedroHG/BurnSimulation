BUILD     := build
OBJ_DIR   := $(BUILD)/objects
APP_DIR   := $(BUILD)
TARGET    := app
INCLUDE   := -Iinclude/
SRC       := $(wildcard src/*.cpp)
OBJECTS   := $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

CXX       := g++
CXXFLAGS  := -Wall -Wextra -Werror
LDFLAGS   := -lm

# Regra principal: make => compilar apenas
all: $(APP_DIR)/$(TARGET)

# Compilar o executável
$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	@$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)
	@chmod +x $@
	@echo "Compilado com sucesso!"

# Compilar os .o
$(OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

# Limpar arquivos compilados
clean:
	@rm -rf $(BUILD)
	@echo "Build limpo!"

# Rodar o programa (já precisa estar compilado)
run: $(APP_DIR)/$(TARGET)
	@clear
	@echo "Executando $(APP_DIR)/$(TARGET)..."
	@./$(APP_DIR)/$(TARGET)

# Regra para: limpar, compilar e rodar de uma vez
full: clean all run

.PHONY: all clean run full
