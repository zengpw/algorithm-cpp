rd /s /Q build

cmake -G"MinGW Makefiles" ^
	-DCMAKE_CONFIGURATION_TYPES="Debug" ^
	-H./ ^
	-B./build

cmake --build ./build
