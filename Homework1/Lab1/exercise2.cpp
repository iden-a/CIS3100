#include<iostream>
using namespace std;

/*
Write a C++ program that will calculate the average of four numbers that are stored in variables. The
variables are all of the data type: double. The values that are stored are 578, 986, 1066, and 714
*/

int main(){

    // declaring an initializing variables
    double num1 = 578, num2 = 986, num3 = 1066, num4 = 714, avg_total, sum_total;

   // adding all the numbers for the sum_total
    sum_total = num1 + num2 + num3 + num4;

    // dividing the sum total by 4 to get the average
    avg_total = sum_total/ 4;

    cout << "The sum of those numbers is " << sum_total << endl;
    cout << "The average of those numbers is " << avg_total << endl;

    return 0;
}