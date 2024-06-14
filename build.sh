#!/bin/bash

set -xe

CFLAGS="-Wall -Wextra -Werror -pedantic -std=c++17 -ggdb"

clang++ $CFLAGS -o main main.cpp ./plug.cpp