*This project has been created as part of the 42 curriculum by fsitter.*

**DESCRIPTION**

The goal of the subject pushswap is to sort a given sequence of integers.
For smaller sequences it locates the smallest number in stack A, brings it to the top
and pushes it to stack B until there are 3 numbers left in A.
This leads to stack B beeing sorted in decending order.
It then sorts the 3 numbers in stack A in ascending order and pushes the numbers in stack B back to stack A.
For bigger sequences it uses radix.
It goes through each bit positions starting from the right and pushes numbers that have a 0 there
from stack A to stack B and rotates the 1's to the bottom.
Then it puts all the 0 on top of the 1's by pushing them back to stack A. 
Then it shifts one position to the right and does the described pushing and rotating again.


**INSTRUCTIONS**

To compile this project use the Makefile and run:

	make

To run it eather use:

	./push_swap "4 2 42"

using any shell or:

	ARG="4 2 42";./push_swap $ARG

but be sure to use the bash shell.


**RESOURCES**

- Peers and Evaluations
- Libft
- YouTube - Neso Academy - Doubly Linked List (Insertion at the Beginning)
	https://www.youtube.com/watch?v=SPKCATQ--KY
- YouTube - Neso Academy - Doubly Linked List (Insertion at the End)
	https://www.youtube.com/watch?v=LDMF8iqO8pg
- YouTube - Neso Academy - Doubly Linked List (Deleting the First Node)
	https://www.youtube.com/watch?v=ZxGz3XkGlyA
