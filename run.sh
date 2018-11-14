#!/bin/bash

echo "running with n=2^30, p=(1,2,4,8)"
#./pi 1048576 1
#./pi 1048576 2
#./pi 1048576 4
#./pi 1048576 8


echo "running with constand n/p"
./pi 1024 8
./pi 2048 8
./pi 4096 8
./pi 8192 8
./pi 16384 8
./pi 32768 8
./pi 65536 8
./pi 131072 8
./pi 262144 8
