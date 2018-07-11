#!/usr/bin/env bash

rm -rf build
cmake -DCMAKE_CONFIGURATION_TYPES="Debug"	\
	-H./	\
	-B./build

cmake --build ./build
