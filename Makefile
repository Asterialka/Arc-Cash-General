BUILD_DIR=build
DEPENDENCIES=$(BUILD_DIR)/list.o $(BUILD_DIR)/hash.o $(BUILD_DIR)/cache.o

all: makeDirs cache.exe

makeDirs:
ifeq (,$(wildcard ./$(BUILD_DIR)))
	mkdir $(BUILD_DIR)
endif

cache.exe: $(DEPENDENCIES)
	g++ $^ -o $@

$(BUILD_DIR)/cache.o: ARC_cache/cache.c ARC_cache/cache.h ARC_cache/hash.h ARC_cache/list.h
	g++ $^ -c -o $@

$(BUILD_DIR)/list.o: ARC_cache/list.c ARC_cache/list.h
	g++ $^ -c -o $@

$(BUILD_DIR)/hash.o: ARC_cache/hash.cpp ARC_cache/hash.h
	g++ $< -c -o $@