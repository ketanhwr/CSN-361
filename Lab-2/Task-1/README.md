### Task

Implement an error detection mechanism using the standard CRC algorithm. Write two programs: generator and verifier. The generator program reads from standard input: a `n`-bit message as a stringo of `0`'s and `1`'s as a line of ASCII text. The second line is the `k`-bit polynomial, also in ASCII. It outputs to standard output a line of ASCII text with `n` +`k` `0`'s and `1`'s representing the message to be transmitted. Then it outputs the polynomial, just as it reads it in. The verifier program reads in the output of the generator program and outputs a message indicating whether it is correct or not. Finally write a program, alter, that inverts one bit on the first line depending on its argument but copies the rest of the two lines correctly. Now type the following and report the outcome.

- `generator < file | verifier`
- `generator < file | alter arg | verifier`