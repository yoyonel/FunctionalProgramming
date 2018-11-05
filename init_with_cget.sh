#!/usr/bin/env sh
# https://github.com/pfultz2/cget

mkdir -p with_cget
cd with_cget/

cget init --std=c++14
cget install Dobiasd/FunctionalPlus\

cd -

export CGET_PREFIX=$(realpath with_cget/cget/cget)
