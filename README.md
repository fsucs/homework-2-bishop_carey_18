Getting Started
===============

In this project, the user will input an int n, and the function will return 5 numbers from a string starting at the index n. 

To do this, the program will first call the function get_concatenated_primes in main. The function will find all the prime numbers between 2 and 2000. Once a prime number is found, it is turned into a string and concated onto the concat_primes string. Once all the prime numbers are found and in the string, the string is shorten to a length of 1000, and is returned to the main. In the main, the user is asked to input an int that will be used as an index. Next, the function get_slice_of_5 is called using the string returned by get_concatenated_primes and the user entered index as the parameters. The get_slice_of_5 function will run an if/else statement that states, if 1000-index is less than 5, then store the number starting at the index and ending at the end of the string into string ret. The else statement uses the substr command to store in the string ret the numbers starting at the index and make it a length of 5. Once ret has the slice of 5, it is returned to the main. Main then couts the ret string.

To run the code:

     1. In a SSH terminal, use either g++ concat_primes.cpp or clang++ concat_primes.cpp to compile. 
     2. Once compiled, use a.out concat_primes.cpp to run the program. 

Documentation
=============

Feel free to generate a new Doxygen configuration. Please tell us how to look at your documentation.
