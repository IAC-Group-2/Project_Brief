#!/bin/bash

#run all component testbenches under component_tests/

SCRIPT_DIR=$(dirname "$(realpath "$0")")
TEST_FOLDER=$(realpath "$SCRIPT_DIR")
RTL_FOLDER=$(realpath "$SCRIPT_DIR/../../rtl")
OUT_FOLDER="$SCRIPT_DIR/../test_out/component_tests"
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
RESET=$(tput sgr0)

passes=0
fails=0

mkdir -p "$OUT_FOLDER"
OUT_FOLDER=$(realpath "$OUT_FOLDER")

if [ -z "$OUT_FOLDER" ] || [ "$OUT_FOLDER" = "/" ]; then
    echo "bad OUT_FOLDER path, stopping"
    exit 1
fi

cd "$SCRIPT_DIR"

#clean previous output safely
rm -rf "${OUT_FOLDER:?}"/*

for file in "${TEST_FOLDER}"/component_tests/*_tb.cpp; do
    name=$(basename "$file" _tb.cpp)

    echo "Running $name..."

    verilator -Wall --trace \
        -cc "${RTL_FOLDER}/${name}.sv" \
        --exe "${file}" \
        -y "${RTL_FOLDER}" \
        --prefix "Vdut" \
        -o Vdut \
        -LDFLAGS "-lgtest -lgtest_main -lpthread"

    make -j -C obj_dir/ -f Vdut.mk

    ./obj_dir/Vdut
    status=$?

    if [ $status -eq 0 ]; then
        ((passes++))
        echo "${GREEN}PASS${RESET} ${name}"
    else
        ((fails++))
        echo "${RED}FAIL${RESET} ${name}"
    fi

    #stash build output per test
    mv obj_dir "${OUT_FOLDER}/${name}_obj_dir"
done

echo "Passed: ${passes}"
echo "Failed: ${fails}"

exit $fails

