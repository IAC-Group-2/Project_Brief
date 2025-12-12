#!/bin/bash

rm -rf test_out/obj_dir

./assemble.sh reference/f1.s

verilator -Wall -cc --trace ../rtl/top.sv --exe ./vbuddy_tb/f1_tb.cpp -y ../rtl/ --prefix "Vdut"

make -j -C obj_dir -f Vdut.mk Vdut

obj_dir/Vdut
