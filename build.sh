#!/bin/bash

# 编译server
echo "Compiling server..."
cd server || {
    echo "Failed to enter directory 'server'"
    exit 1
}
mkdir -p build
cd build || {
    echo "Failed to enter directory 'build'"
    exit 1
}
cmake ..
make

cd ../..

# 编译client
echo "Compiling client..."
cd client || {
    echo "Failed to enter directory 'client'"
    exit 1
}
mkdir -p build
cd build || {
    echo "Failed to enter directory 'build'"
    exit 1
}
cmake ..
make

echo "Build process completed."
