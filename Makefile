CXX = g++

# Pour utiliser une variable $(CC)

# Pour les flags CFLAGS / CXXFLAGC
CFLAGS = -Wall -Wextra -O2

# Pour les editions de liens LDFLAGS
LDFLAGS = -lsfml-window -lsfml-graphics -lsfml-system

# Pour l'executable EXEC
EXEC = App

# Variables speciales
# $@ -> nom cible
# $< -> nom de la premiere dependance
# $^ -> liste des dependances
# $? -> liste de dependance plus recentes que la cible
# $* -> nom fichier, sans son extension

# % -> egale a * en programmation
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst src/%.cpp,bin/%.o,$(SRC))

#all: $(EXEC)

# Rule for object files
bin/%.o: src/%.cpp
	$(CXX) $(CFLAGS) -o $@ -c $<

# Rule for executable
$(EXEC): $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)

# Clean target
clean:
	rm -f bin/*.o $(EXEC)

.PHONY: all clean
