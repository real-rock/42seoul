#!/bin/bash

echo "input: <0> "
./ex00 0

echo "input: <10.0>"
./ex00 10.0

echo "input: <1000>"
./ex00 1000

echo "input: <f>"
./ex00 f

echo "input: <42.0f>"
./ex00 42.0f

echo "input: <42.0fq>"
./ex00 42.0fq

echo "input: <nan>"
./ex00 nan

echo "input: <inf>"
./ex00 inf

echo "input: <-inff>"
./ex00 -inff

echo "input: <test>"
./ex00 test

echo "input: <10.ewrewrf>"
./ex00 10.ewrewrf

echo "input: <11111111>"
./ex00 11111111

echo "input: <111111>"
./ex00 111111

echo "input: <1111111111111>"
./ex00 1111111111111

echo "input: <111111111111111111111111111111111111111111111111111111111>"
./ex00 111111111111111111111111111111111111111111111111111111111