/** 
   Project 2: Concatenated Primes

   Author: Alice Bishop and Kathryn Carey

   This program asks the use to input a number. It then returns the the
   prime numbers to five places from the inputted number.
*/

/** \file concat_primes.cpp
    program returns a string of the first 5 numbers starting at a user inputed index
    
    In this program, the user will input an int n. While n is being read in, 
    the function get_concatenated_primes() is called. This function finds all the prime numbers starting at 2 and ends at 2000.
    Once a prime number is found, it will turn the int into a string and concate it onto the concat_primes string.
    After it finds all the prime numbers between 2 and 2000, the function will shorten the string to a length of 1000 using substr and returns it to main. 
    The string returned is set equal to the string concat_primes. The function get_slice_of_5 is called next. 
    It uses concat_primes and the user input int n as the parameters. In the get_slice_of_5 function, substr is used again, index is where it will start
    and it will read the next 5 numbers. It is set equal to the ret string, and ret is returned. In the main, when ret is returned it is printed on the screen using cout.
    
 
    Requires: C++11
    Assumptions:User always wnters an integer 0 to 1000
*/


#include<iostream>
#include<string>
#include<assert.h>
#include<boost/lexical_cast.hpp>

/** \brief Brief function explaination
   get_concatenated_primes : This function returns a string of prime numbers with the length of a 1000.
   The function starts with creating a string concat_primes. It then goes into a for loop starting at the number 2 and going until 2000.
   The number goes to 2000 because that is the number in which there is at least 1000 prime numbers counted. It then sets a boolean isPrime to
   true. It goes into a second for loop starting at 2 and going through an if statement that determines if the number is divisible. If it is 
   the function breaks and goes to the next number from the first for loop. If the numbers are true then the numbers are concatenated to the 
   concat_primes string. The function then returns the string of the length of 1000.
   get_slice_of_5 : This function returns the concat_primes string starting at the given index number to 5 places. The function starts
   by creating a string called ret. It then goes into an if else statement that checks if the length of the string is less than 5, if
   that is true, it returns what is left in the string. Else the string returns a length of 5 from the given index.


    @return std::string
*/
std::string get_concatenated_primes()
{
    using namespace std;
    string concat_primes = "";
	for (int x = 2; x < 2000; x++){//k starting at 2
		bool isPrime = true; //prime number is true unless if statements are true
		for (int i = 2; i <= x / 2; i++){
			if (x % i == 0){ //checks if the number is divisible
				isPrime = false;
				break;
			}
		}
		if (isPrime == true){//if the number is prime, it adds it to the string

			concat_primes = concat_primes + boost::lexical_cast<string>(x);
	}
	}
    return concat_primes.substr(0, 1000);//shortens the string to the length of 1000
 	
}

std::string get_slice_of_5(const std::string & primes, const int index)
{
    std::string ret = "";
    
    if ((1000 - index) < 5)
	ret = primes.substr(index);
    else 
	ret = primes.substr(index, 5);

    return ret;
}

int main(int argc, char *argv[]){
    using namespace std;
    int n;
    string concat_primes;
    if (argc >= 2){
        concat_primes = get_concatenated_primes();
        assert(get_slice_of_5(concat_primes, 3) == "71113");
        cout<<"Unit Test 1 passed\n";
        assert(get_slice_of_5(concat_primes, 6) == "13171");
        cout<<"Unit Test 2 passed\n";
        
       assert(get_slice_of_5(concat_primes, 7) == "31719");
       cout<<"Unit Test 3 passed\n";
       assert(get_slice_of_5(concat_primes, 120) == "92332");
       cout<<"Unit Test 4 passed\n";
       assert(get_slice_of_5(concat_primes, 999) == "1");
       cout<<"Unit Test 5 passed\n";
	    
    } else{
        cout<< "Please input n: ";
        while(std::cin >> n)
        {
            concat_primes = get_concatenated_primes();
            std::cout << get_slice_of_5(concat_primes, n) << std::endl;
            cout<< "Please input n: ";
        }
    }
    return 0;
}
