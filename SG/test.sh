#!/bin/bash
iter=16777216

echo "---------------------testovi SG------------------" > ../testsg.txt
make;
for CORE_NUM in 1 2 3 4
do
export CORE_NUM;
make test_k;
echo "----------------test${CORE_NUM}-------------" >> ../testsg.txt
{ time ./stream_gate_host ; } >> ../testsg.txt 2>&1;
{ time ./stream_gate_host ; } >> ../testsg.txt 2>&1;
{ time ./stream_gate_host ; } >> ../testsg.txt 2>&1;
{ time ./stream_gate_host ; } >> ../testsg.txt 2>&1;
{ time ./stream_gate_host ; } >> ../testsg.txt 2>&1;

if [ $CORE_NUM != 4 ]
then
make clean;
fi

done
