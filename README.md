*This project has been created as part of the 42 curriculum by slaaouin.*

The push_swap project is a very simple and highly effective algorithm project: data will need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.

This project contains 1 programs:

    push_swap that calculates and displays on the standard output the smallest progam using push_swap instruction language that sorts inte-ger arguments received.
push_swap instructions

    sa: swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
    sb: swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
    ss: sa and sb at the same time.
    pa: push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
    pb: push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
    ra: rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
    rb: rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
    rr: ra and rb at the same time.
    rra: reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
    rrb: reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
    rrr: rra and rrb at the same time.

Algorithm Choice: Radix Sort

To efficiently sort large sets of numbers, this project implements a Radix Sort–based algorithm adapted to the constraints of the push_swap subject.

Since the available operations are limited to stack manipulations, the algorithm first compresses the input values into indexed ranks. Each number is replaced by its position in the sorted order. This normalization removes negative values and reduces the maximum number of bits required, making the algorithm faster and more predictable.

The sorting process then iterates over each bit of the indexed values, starting from the least significant bit. For each pass:

Numbers are examined at the top of stack a

If the current bit is 0, the value is pushed to stack b

If the bit is 1, the value is rotated within stack a

Once all elements have been processed for a given bit, all values from stack b are pushed back to stack a

This procedure is repeated until all bits have been processed, resulting in a fully sorted stack.

For small input sizes, the project uses dedicated sorting logic instead of Radix Sort to minimize the number of operations. Radix Sort is therefore reserved for larger inputs, where it provides better performance and scalability.


Compilation
run make

Execution
push_swap: ./push_swap 0 2 3 1

Resources
https://www.geeksforgeeks.org/dsa/radix-sort/
https://en.wikipedia.org/wiki/Radix_sort
https://visualgo.net/en
https://github.com/o-reo/push_swap_visualizer

AI Usage :

AI tools were used as a learning aid, not for code generation.
They helped with:

Understanding sorting algorithms and their complexity

Visualizing how the algorithm behaves step by step

Clarifying how stack operations affect the sorting process

Improving explanations and documentation clarity

All implementation logic and coding decisions were made manually.

Notes:

The program handles invalid input according to project specifications

Duplicate numbers are not allowed

The focus is on producing an optimized and efficient instruction sequence
