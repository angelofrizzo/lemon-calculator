#!/bin/bash

if [ ! -e ./lemon-parser/lemon ]; then
    cc ./lemon-parser/lemon.c -o ./lemon-parser/lemon
fi

rm -rf ./out
mkdir ./out
mkdir ./out/grammar

./lemon-parser/lemon ./src/gram.y

mv ./src/gram.c ./src/gram.h ./src/gram.out ./out/grammar

mkdir ./src/temp 

cp ./src/main.c ./src/utils.h ./src/utils.c ./out/grammar/gram.c ./src/temp

cat ./src/temp/main.c >> ./src/temp/gram.c

cc ./src/temp/gram.c ./src/temp/utils.c -o ./out/lemon_calc

rm -rf ./src/temp 
