#!/bin/bash
read -p "File name {exp. : code.c or code.cpp vs..} : " name
read -p "Output file name {exp. : code or program vs..} : " output
gcc -o $output $name -lm
echo "Done !"
