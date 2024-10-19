CXX = g++
CXXFLAGS = `pkg-config --cflags --libs opencv4` -std=c++17 -stdlib=libc++

all: test single grid

test: run_test.cpp image_helper.cpp
	$(CXX) run_test.cpp image_helper.cpp -o run-test $(CXXFLAGS)

grid: show_grid.cpp
	$(CXX) show_grid.cpp -o show-grid $(CXXFLAGS)

single: show_single.cpp
	$(CXX) show_single.cpp -o show-single $(CXXFLAGS)

clean:
	rm -rf run-test show-grid show-single decompressed_images/* compressed_images/*


	