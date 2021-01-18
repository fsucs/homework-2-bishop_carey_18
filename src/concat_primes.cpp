/** 
   Project 2: Concatenated Primes

   Author:Alice Bishop and Kathryn Carey

   This program asks the use to input a number. It then returns the the
   prime numbers to five places from the inputted number.
*/

/** \file concat_primes.cpp
    \brief Brief explanation...
    
    Long explination goes here...

    Requires: C++11
*/


#include<iostream>
#include<string>


/** \brief Brief function explaination
   
  
   And a long one...

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
			concat_primes = concat_primes + to_strig(x);
	}
    return concat_primes.substr(0, 1000);//shortens the string to the length of 1000
}


std::string get_slice_of_5(const std::string & primes, const int index)
{
    std::string ret = "";
    
    ret = primes.substr(index, 5); //returns the prime numbers starting at given to 5 places
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
       assert(get_slice_of_5(concat_primes, 6) == "1");
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
