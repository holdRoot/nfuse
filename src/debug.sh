#!/bin/bash

sudo umount store
rm -rf store

mkdir store

bear make

./nfuse store

make clean
