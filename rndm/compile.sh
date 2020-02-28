#!/bin/bash
make re && make clean
gcc -o ft_printf $1 libftprintf.a