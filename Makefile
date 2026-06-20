# Компилятор и флаги
CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -Iinclude
LDFLAGS = 

# Целевой исполняемый файл
TARGET = crypto_program

# Директории
SRC_DIR = algorithms
INCLUDE_DIR = include
BUILD_DIR = build

# Исходные файлы
MAIN_SRC = main.cpp
ALGO_SRCS = $(SRC_DIR)/module_compute.cpp $(SRC_DIR)/euclid_compute.cpp $(SRC_DIR)/el_gamal_compute.cpp

# Объектные файлы (все в build/)
MAIN_OBJ = $(BUILD_DIR)/main.o
ALGO_OBJS = $(BUILD_DIR)/module_compute.o $(BUILD_DIR)/euclid_compute.o $(BUILD_DIR)/el_gamal_compute.o
OBJS = $(MAIN_OBJ) $(ALGO_OBJS)

# Флаги для сборки
.PHONY: all clean run

# Цель по умолчанию
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Сборка main.cpp
$(MAIN_OBJ): $(MAIN_SRC) $(INCLUDE_DIR)/module_compute.h $(INCLUDE_DIR)/euclid_compute.h $(INCLUDE_DIR)/el_gamal_compute.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Сборка модульных файлов
$(BUILD_DIR)/module_compute.o: $(SRC_DIR)/module_compute.cpp $(INCLUDE_DIR)/module_compute.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/euclid_compute.o: $(SRC_DIR)/euclid_compute.cpp $(INCLUDE_DIR)/euclid_compute.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/el_gamal_compute.o: $(SRC_DIR)/el_gamal_compute.cpp $(INCLUDE_DIR)/module_compute.h $(INCLUDE_DIR)/el_gamal_compute.h
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Очистка
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

# Запуск программы (игнорируем ошибки выполнения)
run: $(TARGET)
	-./$(TARGET)

# Отладка
debug: CXXFLAGS += -g -DDEBUG
debug: all

# Установка прав на выполнение
chmod:
	chmod +x $(TARGET)
