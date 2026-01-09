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

Algorithm Choice: Chunk-Based Sorting

To efficiently handle large input sizes and keep the number of operations low, this project uses a chunk-based sorting algorithm designed specifically for the constraints of the push_swap subject.

As a first step, all input values are compressed into indexed ranks. Each number is replaced by its position in the sorted order, which removes negative values and simplifies comparisons. This normalization creates a predictable range of values and makes it easier to divide the data into chunks.

The core idea behind the chunk algorithm is to split the full range of indexed values into smaller, manageable groups called chunks. Instead of sorting all values at once, the algorithm processes one chunk at a time.

The sorting process works as follows:

The indexed value range is divided into several chunks, based on the total number of elements

Starting with the smallest chunk, the algorithm scans stack a to find values that belong to the current range

When a value from the active chunk reaches the top of stack a, it is pushed to stack b

Stack a is rotated as needed to bring target values to the top using the fewest possible operations

Once all values from a chunk have been moved to stack b, the algorithm moves on to the next chunk

After all chunks have been transferred to stack b, the algorithm rebuilds the sorted stack:

The largest value in stack b is located

Stack b is rotated until this value reaches the top

The value is then pushed back to stack a

This step is repeated until stack b is empty. By always pushing the largest remaining value first, stack a is rebuilt in ascending order.

For small input sizes, the project relies on specialized sorting routines to avoid unnecessary operations. The chunk-based approach is therefore reserved for larger datasets, where breaking the problem into smaller ranges leads to better performance and a more efficient operation count.

Compilation
run make

Execution
push_swap: ./push_swap 0 2 3 1

Resources
https://en.wikipedia.org/wiki/Chunking_(computing)
https://github.com/o-reo/push_swap_visualizer
https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

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
