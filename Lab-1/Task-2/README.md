### Task

Write a C program that takes two integers and an operator (+, -, *, /) as command line arguments and prints the result of the operation specified by the operator on the two integers. Name the executable file as `calc`. If the user executes calc by writing:
```
calc 2 + 3
```
Then the output of your program should be 5.

### Running

1. Run `make`. If you haven't installed `make` them generate the output file using `gcc calc.c -o calc`.

2. Use `./calc 5 / 2` to run the program.

_Note: To use the mulitplication operand, make sure you quote the `*`. `./calc 25 "*" 5`._