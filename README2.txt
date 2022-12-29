Name: Raz Poradosu
ONID: poradosr@oregonstate.edu
Section: CS 162-010
Assignment 5, due December 4th 2022

Extra Credit - Guess the TA: Hello Zach.

Description: A program containing functions that can alter a linked list. 
If functions are called in a test file, a linked list with an inserted node in the front, back,
and specified index could be created. A sorted linked list in ascending or descending order can be printed.
A count for the number of primes in the linked list can be portrayed.

Instructions: 
1. Compile the program with make and press enter
2. Run the program with run and press enter
3. The program will tell you if the list was successfully created and test the get_length and push_front functions.
   It will show the expected vs. actual length of the list.
4. Press enter to continue.
5. The program will test the push_back function and display the expected vs. actual length of the
   linked list.
6. Press enter to continue.
7. The program will test the insert function and display the expected vs. actual length of the
   linked list.
8. Press enter to continue.
9. The program will test the sort_ascending function and display the expected vs. actual sorted
   linked list.
10. Press enter to continue.
11. The program will test the sort_descending function and display the expected vs. actual sorted
   linked list.
12. Press enter to continue.
13. The program will test the count_prime and clear functions and display the expected vs. actual 
    number of primes and length of the linked list. The passing of test 4 and 5 will be displayed.
14. The program ends.

Limitations: 
- I am assuming that the test file run by the TA will be the same version that was provided to us in
  the assignment.
- I am assuming a negative number is not considered to be prime.

Complexity Analysis: 
a. sort_ascending:  O(n * log(n))
b. sort_descending:  O(n * log(n))
c. count_prime: O(n^2)