#!/usr/bin/env bash

rm -rf build
cmake -DCMAKE_BUILD_TYPE="Debug"	\
	-H./	\
	-B./build

cmake --build ./build
