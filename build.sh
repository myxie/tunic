#!/bin/bash

rm tunic.exe
gcc tunic_template.c tunic.h -o tunic.exe
./tunic.exe
echo "Finito Bandito"