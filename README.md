*This project has been created as part of the 42 curriculum by nfaronia.*

# push_swap

## Description
**push_swap** is a sorting algorithm project where the goal is to sort a list of integers using two stacks (Stack A and Stack B) and a limited set of operations. The challenge is to sort the numbers in ascending order with the fewest possible operations.

## Instructions

### Compilation
To compile the project, run:
```
make
```
This will generate the executable push_swap.

Additional Makefile rules:
```
make clean    # remove object files
make fclean   # remove object files and executable
make re       # recompile the project
```

### Execution
Run the program with a list of integers as arguments:
```
./push_swap 3 2 5 1 4
```
The program will output a list of operations such as:
```
ra
ra
ra
pb
ra
ra
pb
sa
rra
pa
pa
```
These operations, when executed in order, will sort the stack.

### Checker
To verify that the output correctly sorts the numbers, you can use the checker:
```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```
If the result is correct, the checker will display:
```
OK
```

### Number of Lines
```
ARG="4 67 3 87 23"; ./push_swap $ARG | wc-l
```
The output will be:
```
9
```

## Resources

### References
- 42 push_swap subject
- **Linked list & stack:**
  - [Linked List Explanation](https://youtu.be/VOpjAHCee7c?si=x5iqZk2ciHj2qXNe)
  - [Stack Implementation Tutorial](https://youtu.be/A4sRhuGkRb0?si=A489n2RR3qWUCSeC)
  - [Stack Using Linked List in C](https://www.geeksforgeeks.org/c/stack-using-linked-list-in-c/)
- **Radix Sort:**
  - [Radix Sort Algorithm](https://www.geeksforgeeks.org/dsa/radix-sort/)
  - [Radix Sort Using Array of Linked Lists](https://stackoverflow.com/questions/67750089/radix-sort-using-array-of-linked-list-as-bin-in-c)

### AI Usage

AI tools were used as a learning aid to help find study resources, understand algorithms, and clarify edge cases.
