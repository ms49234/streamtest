#!/bin/bash

echo "---------------------testovi c++------------------" > ../testcpp.txt
{ time ./VectorDist ; } >> ../testcpp.txt 2>&1;
{ time ./VectorDist ; } >> ../testcpp.txt 2>&1;
{ time ./VectorDist ; } >> ../testcpp.txt 2>&1;
{ time ./VectorDist ; } >> ../testcpp.txt 2>&1;
{ time ./VectorDist ; } >> ../testcpp.txt 2>&1;
