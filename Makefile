# Kompilator i flagi
CXX := g++
CXXFLAGS := -Wall -Wextra -Wpedantic -Werror -std=c++20 -I./src

# Ścieżki i pliki
SRC := src/order.cpp src/dish.cpp src/table.cpp
MAIN := main.cpp
OBJS := order.o dish.o table.o main.o
TARGET := app

# Domyślny cel
all: $(TARGET)

# Kompilacja pliku wykonywalnego
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Kompilacja plików .cpp do .o
order.o: src/order.cpp src/order.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

dish.o: src/dish.cpp src/dish.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

table.o: src/table.cpp src/table.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp src/order.hpp src/dish.hpp src/table.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Uruchamianie aplikacji
run: $(TARGET)
	./$(TARGET)

# Czyszczenie
clean:
	rm -f *.o $(TARGET)

.PHONY: all run clean