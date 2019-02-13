#!/bin/bash

umount store &> /dev/null
rm -rf store

mkdir store

make

./nfuse store

make clean
