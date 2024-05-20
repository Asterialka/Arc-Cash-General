BUILD_DIR=build
DEPENDENCIES=$(BUILD_DIR)/list.o $(BUILD_DIR)/hash.o $(BUILD_DIR)/cache.o ARC_cache/cache.h ARC_cache/hash.h ARC_cache/list.h

all: makeDirs configure

makeDirs:
ifeq (,$(wildcard ./$(BUILD_DIR)))
	mkdir $(BUILD_DIR)
endif

configure: $(BUILD_DIR)/list.o $(BUILD_DIR)/cache.o $(BUILD_DIR)/hash.o
	@echo "Configured successfully"


cache.exe: $(DEPENDENCIES)
	g++ $^ -o $@

$(BUILD_DIR)/cache.o: ARC_cache/cache.c
	g++ $< -c -o $@

$(BUILD_DIR)/list.o: ARC_cache/list.c
	g++ $< -c -o $@

$(BUILD_DIR)/hash.o: ARC_cache/hash.cpp
	g++ $< -c -o $@
