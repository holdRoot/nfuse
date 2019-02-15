!#/bin/bash

rm -rf build
mkdir -p build
cd build
cmake ..
make
if [ $? -ne "0" ]; then
    echo "COMPILE FAILED!"
    exit 1
fi
mv compile_commands.json ..
cp -r generated ..
make clean
cd ..

