# push_swap

push_swap is a project at 42 that aims to create a sorting algorithm that uses two stacks and a limited set of instructions.

## Getting Started

To use this program, you need to clone this repository and compile it with `make`. This will generate the `push_swap` executable file.

## Usage

To use this program in your own project, you need to provide a list of integers as arguments to the `push_swap` program. For example:

```bash
./push_swap 3 2 1 4 5
```

The program will output the most efficient list of instructions to sort the list in ascending order using two stacks: A and B. The possible instructions are:

- `sa` : swap the first two elements of stack A
- `sb` : swap the first two elements of stack B
- `ss` : swap the first two elements of both stacks
- `pa` : push the top element of stack B onto stack A
- `pb` : push the top element of stack A onto stack B
- `ra` : rotate stack A up by one element (the first element becomes the last one)
- `rb` : rotate stack B up by one element (the first element becomes the last one)
- `rr` : rotate both stacks up by one element
- `rra` : rotate stack A down by one element (the last element becomes the first one)
- `rrb` : rotate stack B down by one element (the last element becomes the first one)
- `rrr` : rotate both stacks down by one element

For example, for the list 3 2 1 4 5, the output could be:

```bash
pb
ra
pb
ra
sa
ra
pa
pa
```

You can check if the output is correct using the `checker` program, which takes the same list of integers as arguments and reads the instructions from the standard input. The program will print `OK` if the instructions sort the list correctly, or `KO` otherwise. For example:

```bash
$ ARG="3 2 1 4 5"; ./push_swap $ARG | ./checker $ARG
OK
```

## Evaluation

The grade depends on how efficient the program's sorting process is. The maximum number of allowed instructions varies according to the size of the list:

- For a list of 3 integers: no more than 3 instructions.
- For a list of 5 integers: no more than 12 instructions.
- For a list of 100 integers: rating from 1 to 5 points depending on the number of instructions:
    - 5 points for less than 700 instructions
    - 4 points for less than 900 instructions
    - 3 points for less than 1100 instructions
    - 2 points for less than 1300 instructions
    - 1 point for less than 1500 instructions
- For a list of 500 integers: rating from 1 to 5 points depending on the number of instructions:
    - 5 points for less than 5500 instructions
    - 4 points for less than 7000 instructions
    - 3 points for less than 8500 instructions
    - 2 points for less than 10000 instructions
    - 1 point for less than 11500 instructions

Validating the project requires at least an average score of 80/100.
