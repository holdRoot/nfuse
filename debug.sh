!#/bin/bash

cd build
cmake ..
make
mv compile_commands.json ..
cp -r generated ..
make clean
cd ..

