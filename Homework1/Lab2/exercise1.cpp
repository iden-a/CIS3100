#include<iostream>
using namespace std;

/*
Write a program using if, else if, and else statements that will ask the user to input
today’s temperature. If the temperature is above 80 degrees, display a message saying: "It is
very hot today!" If the temperature is below 40 degrees, display a message saying: "It
is very cold today!" If the temperature is between 40 and 80 degrees, display a
message saying: "It is a beautiful day outside!"
*/

int main(){

    // declaring the temp variable 
    double temp;

    // initializing the variable with user input 
    cout << "Enter The Temperature: " << endl;
    cin >> temp;

    /* if the temp is greater than or equal to 80,
    the user's screen will show that it is hot outside.
    */
    if (temp >= 80 ) {
        cout << "It is very hot today!" << endl;
    }

    /*
    if the temp is less than or equal to 40,
    the user's screen will show that it is hot outside.
    */
    else if (temp <= 40) {
        cout << "It is very cold today!" << endl;
    }

    /*
    if the temp does not fit either of the previous scenarios, 
    then it must be less an 80 and greater than 40
    User's screen will show that it is a beautiful day outside.
    */
    else {
         cout << "It is a beautiful day outside!" << endl;
    }

    return 0;
}