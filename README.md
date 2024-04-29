# 42Cursus-push_swap
This is my repo for the push_swap project !

## Introduction
The push_swap project is a project from the 42Cursus, which is a sorting algorithm project. 
The goal is to sort a list of numbers using two stacks and a limited set of operations. 
The goal is to sort the list with the least amount of operations possible.

## The rules
The game is composed of two stacks named A and B.
- At the beginning, A contains a random number of either positive or negative numbers without any duplicates.
- The goal is to sort in ascending order numbers into stack A.
- To do this, you have the following operations at your disposal:
  - sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
  - sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
  - ss : sa and sb at the same time.
  - pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
  - pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
  - ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
  - rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
  - rr : ra and rb at the same time.
  - rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
  - rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
  - rrr : rra and rrb at the same time.

## The project
The project is composed of two programs:
- The first program, named **push_swap**, will take a list of numbers as arguments and will output a list of operations to sort the list.
- The second program, named **checker**, will take a list of numbers as arguments and will wait for the user to input a list of operations.
    If the list of operations is correct and sorts the list, the program will output "OK", otherwise it will output "KO".

bash one-liner to checker your average for 500 numbers on 20 sorts, by **yboudoui** :
```bash
export LOOP=20; echo "($(for _ in $(seq 1 $LOOP) ; do ./push_swap $(shuf -i 0-500 | tr '\n' ' ') | wc -l; done |tr '\n' '+'|head -c -1))/$LOOP" | bc
```
