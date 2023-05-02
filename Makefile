all: build

build: geometry

rebuild: clean build

geometry:
	cmake -S . -B build
	cmake --build build

unistall:
	find ./ -name "build" -type d -exec rm -rf {} +

clean: unistall

run:
	./build/Geometry

.PHONY: all build rebuild geometry unistall clean