  - Sarika de Bruyn
  - sed2194
  
Part 1:
selection_sort() was implemented using the following source: https://www.geeksforgeeks.org/c-program-to-sort-an-array-in-ascending-order/
However, it was modified to add an extra parameter (ascending) to accommodate the sort_integer_array.
This part of the lab takes in the size of an array from the user, generates random integers, then outputs in the original order, 
in ascending order, then descending order. Everything works according to the instructions. 

Valgrind:

==1018443== Memcheck, a memory error detector
==1018443== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1018443== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==1018443== Command: ./isort
==1018443== 
Insert the size of the array: original: 94 28 47 81 83 49 57 49 13 85 
ascending: 13 28 47 49 49 57 81 83 85 94 
descending: 94 85 83 81 57 49 49 47 28 13 
==1018443== 
==1018443== HEAP SUMMARY:
==1018443==     in use at exit: 0 bytes in 0 blocks
==1018443==   total heap usage: 3 allocs, 3 frees, 2,600 bytes allocated
==1018443== 
==1018443== All heap blocks were freed -- no leaks are possible
==1018443== 
==1018443== For lists of detected and suppressed errors, rerun with: -s
==1018443== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


Part 2:
twecho takes in words as command line arguments, prints each word twice, once as is and once as all-capitalized, separated by
a space. It uses dynamic memory location and memory management to manipulate and sort arrays. Everything works according to
the instructions.

Valgrind:

==1018764== Memcheck, a memory error detector
==1018764== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1018764== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==1018764== Command: ./twecho
==1018764== 
==1018764== 
==1018764== HEAP SUMMARY:
==1018764==     in use at exit: 0 bytes in 0 blocks
==1018764==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==1018764== 
==1018764== All heap blocks were freed -- no leaks are possible
==1018764== 
==1018764== For lists of detected and suppressed errors, rerun with: -s
==1018764== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
