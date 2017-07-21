#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool isInteger(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (!isdigit(str[i]))
            return false;
        ++i;
    }

    return true;
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        printf("Too few/many arguments!\n");
        exit(0);
    }

    if (!isInteger(argv[1]) || !isInteger(argv[3])) {
        printf("Input are not integers!\n");
        exit(0);
    }

    int value1 = atoi(argv[1]);
    int value2 = atoi(argv[3]);

    if (strlen(argv[2]) != 1) {
        printf("Invalid Operator!\n");
        exit(0);
    }

    char operator = argv[2][0];

    if (operator == '+')
        printf("Result: %d\n", (value1 + value2));
    else if (operator == '-')
        printf("Result: %d\n", (value1 - value2));
    else if (operator == '*')
        printf("Result: %d\n", (value1 * value2));
    else if (operator == '/')
        printf("Result: %d\n", (value1 / value2));
    else
        printf("Invalid Operator!\n");

    return 0;
}