### Task

Write a program that creates a new process using `fork` and prints the process id of the parent and child process. If the function `fork` is called in a loop that runs 5 times how many new processes will be created?

## Running

1. Run `make`. If you haven't installed `make` them generate the output file using `gcc main.c -o main` and `gcc loop.c -o loop`.

2. Use `./main` or `./loop` to run the program.

_Note: Total 31 new processes are created when `fork` is called in a loop which runs 5 times._