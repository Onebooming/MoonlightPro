#!/bin/bash

protoc --cpp_out=. ./model/protos/*.proto
mkdir -p ./model/protc_cpps
mv ./model/protos/*.pb.cc ./model/protc_cpps
mv ./model/protos/*.pb.h ./model/protc_cpps

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
