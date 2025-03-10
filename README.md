# PUSH_SWAP

This project is about implementing an algorithm that sorts a stack (A) containing any number of distinct integers. The goal is to sort the stack using an auxiliary stack (B, that is empty at the beginning) and a set of atomic operations. The operations are the following. 

- **sa** (swap A): Swaps the first two elements of stack A.
- **sb** (swap B): Swaps the first two elements of stack B.
- **ss**: Performs sa and sb at the same time.
- **pa** (push A): Takes the element at the top of B and puts it at the top of A.
- **pb** (push B): Takes the element at the top of A and puts it at the top of B.
- **ra** (rotate  A): Shifts up all the elements of A by one. The first element becomes the last.
- **rb** (rotate  B): Shifts up all the elements of B by one. The first element becomes the last.
- **rr**: Performs ra and rb at the same time.
- **rra** (reverse rotate  A): Shifts down all the elements of A by one. The last element becomes the first.
- **rrb** (reverse rotate  B): Shifts down all the elements of A by one. The last element becomes the first.
- **rrr**: Performs rra and rrb at the same time.


For the stack implementation I used doubly linked lists, and I used the [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97), created by Ali Ogun specifically for this project. Here are some visuals of executions with 25, 100 and 500 random numbers, respectively. The visuals are generated with this [push_swap visualizer](https://github.com/o-reo/push_swap_visualizer).

<figure align="center">
	<img src="./gifs/25_numbers.gif" width="400" height="250" alt="GIF" style="float: center;">
	<figcaption>Sorting 25 numbers</figcaption>
</figure>

<figure align="center">
	<img src="./gifs/100_numbers.gif" width="400" height="250" alt="GIF" style="float: center;">
	<figcaption>Sorting 100 numbers</figcaption>
</figure>

<figure  align="center">
	<img src="./gifs/500_numbers.gif" width="400" height="250" alt="GIF" style="float: center;">
	<figcaption>Sorting 500 numbers</figcaption>
</figure>




