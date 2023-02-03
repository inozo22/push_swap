# push_swap
課題のPush_swapについてまとめる。
目標はとりあえず課題を理解すること。

## 1. The rules
- The game consists of two stacks, called a and b.
- To start with:
    - In a you will have positive and/or negative numbers, never duplicated.
    - There will be nothing in b.
- The purpose of this game is that order stack a's numbers in ascending order.
- The following operations are available:
    - sa :**swap a** Swaps the first two elements on top of stack **a**. It does nothing if there are one or fewer elements.
    - sb :**swap b** Swaps the first two elements on top of stack **b**. It does nothing if there are one or fewer elements.
    - ss :**Swap both** at the same time.
    - pa :**push a** Takes the first element of stack **b** and puts it on top of stack **a**. It does nothing if **b** is empty.
    - pb :**push b** Takes the first element of stack **a** and puts it on top of stack **b**. It does nothing if **a** is empty.
    - ra :**rotate a** Moves all the elements of the stack **a** up one position, so that the first element becomes the last.
    - rb :**rotate b** Moves all the elements of the stack **b** up one position, so that the first element becomes the last.
    - rr :**rotate both** Moves all the elements of stack **a** and stack **b** up one position at the same time, so that the first element becomes the last one.
    - rra :**reverse rotate a** Shifts all the elements of the stack **a** down one position, so that the last element becomes the first.
    - rrb :**reverse rotate b** Shifts all the elements of the stack **b** down one position, so that the last element becomes the first.
    - rrr :**reverse rotate both** Moves all the elements of stack **a** and **b** down one position at the same time, so that the last element becomes the first.

## 2. 
## 3. The programme
- You must write a program called push_swap that will receive as argument the stack a in the format of a list of intgers. The first argument must be the one on top of the stack(be careful with the order).
- The program must display the list of instructions(shortest)
to sort the stack a, from smallest to largest where the smallest is at the top of the stack.
- The instrctions should be separated using a "\n" and nothing else.
- The goal is to sort the stack with as few operation as possible. During the evaluation we will compare the number of instructions obtained by your program with a maximum instruction range.
- Your program will receive no points either if your program displays a list that is too long or if the result is not correct.
- If no parameters are specified, the program should not display anything and should return control to the user.
- In case of an error, you should display Error followed by a "\n" in the standard error output. Some of the possible errors are: arguments that are not integers, arguments greater than an int, and/or finding duplicate numbers.
