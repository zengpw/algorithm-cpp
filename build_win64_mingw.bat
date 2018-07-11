rd /s /Q build

cmake -G"MinGW Makefiles" ^
	-DCMAKE_BUILD_TYPE="Debug" ^
	-H./ ^
	-B./build

cmake --build ./build
