# push_swap
課題のPush_swapについてまとめる。
目標はとりあえず課題を理解すること。
Summarise the push_swap assignment.
The goal is to understand well the issue.

## Table of contents (Índice)
1. [Subject](#1-subject)
    - [1.1 The rules](#1-the-rules)
    - [1.2 blank](#2-blank)
    - [1.3 The programme](#3-the-programme)
2. [Additional subject](#2-additional-subject)
    - [2.1 How many arguments are required?](#1-how-many-arguments-are-required)
    - [2.2 How many times I can sort?](#2-how-many-times-i-can-sort)
    - [2.3 Is there any time limit?](#3-is-there-any-time-limit)
3. [Posible error](#3-possible-error)

## 1. Subject
### 1. The rules
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
    ![42 Push_swap-15](https://user-images.githubusercontent.com/119419194/217055325-aa2a728e-9a83-4ad5-8ae9-129ca5459d2f.jpg)
    ![42 Push_swap-16](https://user-images.githubusercontent.com/119419194/217055394-9670ef55-5b93-489b-82b8-ce6862a5a2e9.jpg)
    ![42 Push_swap-17](https://user-images.githubusercontent.com/119419194/217055484-5345209b-93f0-4be4-9387-709debf892bb.jpg)

### 2. 
### 3. The programme
- You must write a program called push_swap that will receive as argument the stack a in the format of a list of integers. The first argument must be the one on top of the stack(be careful with the order).
- The program must display the list of instructions(shortest)
to sort the stack a, from smallest to largest where the smallest is at the top of the stack.
- The instrctions should be separated using a "\n" and nothing else.
- The goal is to sort the stack with as few operation as possible. During the evaluation we will compare the number of instructions obtained by your program with a maximum instruction range.
- Your program will receive no points either if your program displays a list that is too long or if the result is not correct.
- If no parameters are specified, the program should not display anything and should return control to the user.
- In case of an error, you should display Error followed by a "\n" in the standard error output. Some of the possible errors are: arguments that are not integers, arguments greater than an int, and/or finding duplicate numbers.

## 2. Cryptic subject
### 1. How many arguments are required.
- At least 500.
### 2. How many times I can sort?
It depends on the number of arguments.
- If it's sorted, it should be 0 times.
- If there are 3 arguments, less than 3 times.
- If there are 5 arguments, less than 12 times(in the subject, it's put 6 arguments, but according to Slack we have to show the instruction shorter than 12 times with 5 arguments, also guidelines.pdf(it's a copy of correction in Urduliz)).
- 100 argumments, 700 times (until 1500 times it's accetable, but points will be deducted)
- 500 argumments, 5500 times (until 11500 times it's accetable, but points will be deducted)
### 3. Is there any time limit?
- No, but it should be reasonable time.

## 3. Possible error
- No arguments (argc should be more than 2) -> Should will be written "\n"
- It's not integer
- There are dubbed numbers
- 



