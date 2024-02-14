#include<iostream>
using namespace std;
/*
Write a C++ program that calculates the average of four numbers – just like in the previous exercise –
but this time ask the user to enter which four numbers to calculate. You will have to use the cin
command to get all four numbers from the user.
*/

int main() {

    // declaring the variables 
     double num1, num2, num3, num4, avg_total;

    // taking in the user input as storing it inside of the variables 
     cout << "Enter The First Number: " << endl;
     cin >> num1;

     cout << "Enter The Second Number: " << endl;
     cin >> num2;

     cout << "Enter The Third Number: " << endl;
     cin >> num3;

     cout << "Enter The Fourth Number: " << endl;
     cin >> num4;

    // calculating averages of the numbers given by user
     avg_total = (num1 + num2 + num3 + num4) / 4;

    // displaying the average total for users to see
     cout << "The average of these numbers is " << avg_total << endl;

    return 0;
}