#!/bin/bash

set -xe

CFLAGS="-Wall -Wextra -Werror -pedantic -std=c++17 -ggdb"

g++ $CFLAGS -o sum main.cpp ./plug.cpp