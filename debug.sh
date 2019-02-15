!#/bin/bash

cd build
cmake ..
make
mv compile_commands.json ..
make clean
cd ..

