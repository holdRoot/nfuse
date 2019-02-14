#!/usr/bin/env bash

if mount | grep nfusestore > /dev/null; then
    sudo umount nfusestore
fi

rm -rf nfusestore

mkdir nfusestore

exit 0
