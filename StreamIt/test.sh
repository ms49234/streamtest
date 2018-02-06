#!/bin/bash
iter=16777216
{ time ./VectorDist -i $iter ; } >> ../teststreamit.txt 2>&1;
{ time ./VectorDist -i $iter ; } >> ../teststreamit.txt 2>&1;
{ time ./VectorDist -i $iter ; } >> ../teststreamit.txt 2>&1;
{ time ./VectorDist -i $iter ; } >> ../teststreamit.txt 2>&1;
{ time ./VectorDist -i $iter ; } >> ../teststreamit.txt 2>&1;
