#include<iostream>
#include <cmath> 
using namespace std;

/*
A person makes a deal with their boss. The boss says they will be paid a wage of $2 on their first
day on the job, and then have their wage doubled every day after that. Use a loop to figure out
how much the person would make using this method on their 20th day of employment. 
*/

int main() {
    // declaring an initializing the variables 
    int day = 1, wage = 2, total = 0;

   // the day is less than or equal to day 20, this will continue until the day reaches 20.
    while (day <= 20) {

        // we are taking the wage, and we are doubling it
        wage *= 2;

        // we are incremting the day by a value of one
        day++;
    }
    
    cout << "Total Payment: " << endl;
    cout << wage << endl;

    return 0;
}