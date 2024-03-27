
.PHONY: format build clean

format:
	clang-format -i -style=file include/*.hpp tests/*.cpp

build:
	mkdir -p build
	cd build && cmake .. && make

# first build the project, then do ctest
test:
	mkdir -p build
	cd build && cmake .. && make && cd tests && ctest