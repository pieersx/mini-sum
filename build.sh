#!/bin/bash

set -xe

CFLAGS="-Wall -Wextra -std=c++17 -pedantic -g"

clang++ $CFLAGS -o main main.cpp ./plug.cpp