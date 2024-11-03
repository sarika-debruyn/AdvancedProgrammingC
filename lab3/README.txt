  - Sarika de Bruyn
  - sed2194
  - lab 3

Part 1: 

Part 1 implements a singly linked list that can hold any data type. I
implemented all functions declared in  mylist.h into mylist.c successfully. I
tested each function incrementally by commenting out the mylist-test.c file. 
The Makefile uses a static library named 'libmylist.a' that contains the
linked list object files. Everything works according to the instructions.

Valgrind: 
 
==788482== Memcheck, a memory error detector
==788482== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==788482== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==788482== Command: ./mylist-test
==788482== 
testing addFront(): 9.0 8.0 7.0 6.0 5.0 4.0 3.0 2.0 1.0 
testing flipSignDouble(): -9.0 -8.0 -7.0 -6.0 -5.0 -4.0 -3.0 -2.0 -1.0 
testing flipSignDouble() again: 9.0 8.0 7.0 6.0 5.0 4.0 3.0 2.0 1.0 
testing findNode(): OK
popped 9.0, the rest is: [ 8.0 7.0 6.0 5.0 4.0 3.0 2.0 1.0 ]
popped 8.0, the rest is: [ 7.0 6.0 5.0 4.0 3.0 2.0 1.0 ]
popped 7.0, the rest is: [ 6.0 5.0 4.0 3.0 2.0 1.0 ]
popped 6.0, the rest is: [ 5.0 4.0 3.0 2.0 1.0 ]
popped 5.0, the rest is: [ 4.0 3.0 2.0 1.0 ]
popped 4.0, the rest is: [ 3.0 2.0 1.0 ]
popped 3.0, the rest is: [ 2.0 1.0 ]
popped 2.0, the rest is: [ 1.0 ]
popped 1.0, the rest is: [ ]
testing addAfter(): 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 
popped 1.0, and reversed the rest: [ 9.0 8.0 7.0 6.0 5.0 4.0 3.0 2.0 ]
popped 9.0, and reversed the rest: [ 2.0 3.0 4.0 5.0 6.0 7.0 8.0 ]
popped 2.0, and reversed the rest: [ 8.0 7.0 6.0 5.0 4.0 3.0 ]
popped 8.0, and reversed the rest: [ 3.0 4.0 5.0 6.0 7.0 ]
popped 3.0, and reversed the rest: [ 7.0 6.0 5.0 4.0 ]
popped 7.0, and reversed the rest: [ 4.0 5.0 6.0 ]
popped 4.0, and reversed the rest: [ 6.0 5.0 ]
popped 6.0, and reversed the rest: [ 5.0 ]
popped 5.0, and reversed the rest: [ ]
==788482== 
==788482== HEAP SUMMARY:
==788482==     in use at exit: 0 bytes in 0 blocks
==788482==   total heap usage: 19 allocs, 19 frees, 1,312 bytes allocated
==788482== 
==788482== All heap blocks were freed -- no leaks are possible
==788482== 
==788482== For lists of detected and suppressed errors, rerun with: -s
==788482== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


Part 2:

Used the linked list library from part 1 to create a program called 'revecho'
which prints out command line arguments in reverse order and looks for the
word "dude" among the arguments. It reports whether "dude" is present or not.
Everything words according to the lab instructions.

Valgrind:
test1:
==811847== Memcheck, a memory error detector
==811847== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==811847== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==811847== Command: ./revecho hello world dude
==811847== 
dude
world
hello

dude found
==811847== 
==811847== HEAP SUMMARY:
==811847==     in use at exit: 0 bytes in 0 blocks
==811847==   total heap usage: 4 allocs, 4 frees, 3,120 bytes allocated
==811847== 
==811847== All heap blocks were freed -- no leaks are possible
==811847== 
==811847== For lists of detected and suppressed errors, rerun with: -s
==811847== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

test 2:

==812027== Memcheck, a memory error detector
==812027== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==812027== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==812027== Command: ./revecho hello world friend
==812027== 
friend
world
hello

dude not found
==812027== 
==812027== HEAP SUMMARY:
==812027==     in use at exit: 0 bytes in 0 blocks
==812027==   total heap usage: 4 allocs, 4 frees, 3,632 bytes allocated
==812027== 
==812027== All heap blocks were freed -- no leaks are possible
==812027== 
==812027== For lists of detected and suppressed errors, rerun with: -s
==812027== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
