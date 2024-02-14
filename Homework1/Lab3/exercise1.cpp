#include<iostream>
using namespace std;
/*
Create a program that will ask the user to enter an integer. Write a loop that subtracts one from
that user-inputted number, and keeps subtracting one until the number is down to zero. 
*/

int main() {
    // declaring the user inputed integer
    int user_int;

    // initializing the variable with user response
    cout << "Enter A Number: " << endl;
    cin >> user_int;

   // while the inputted number is greater than 0
   while (user_int > 0) {

    // we are subtracting 1 from the number and
    // outputting it to the user's screen until we reach 0
    // the user int is updated with the decremented value as the loop repeats.
    cout << "It is now " << user_int << endl;
    user_int--;
   }

    return 0;
}