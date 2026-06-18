# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I./include -I./src

# Директории
SRC_DIR = src
ALG_DIR = algorithms

# Исходные файлы
SRCS = main.cpp \
       $(SRC_DIR)/algorithm_processing.cpp \
       $(ALG_DIR)/module_compute.cpp \
       $(ALG_DIR)/euclid_compute.cpp \
       $(ALG_DIR)/el_gamal_compute.cpp

# Исполняемый файл
TARGET = main

# Цель по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Очистка
clean:
	rm -f $(TARGET)

# Запуск программы
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
