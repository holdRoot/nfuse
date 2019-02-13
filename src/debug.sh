#!/bin/bash

umount store
rm -rf store

mkdir store

make

nfuse store

make clean
