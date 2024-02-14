// incrementing / decrementing
#include <iostream>
using namespace std;

int main() {

    // declaring and initializing the variables 
    int x = 0, odd_sum = 0, even_sum = 0, total = 0;

    // creating a while loop
    while (x <= 100){
        /*
        Checking to see if the value is even.
        If the value is even, we are adding it to the even_sum.
        */ 
        if (x % 2 == 0){
            even_sum += x;
        }

        /*
        This is the edge case for non even (odd) values.
        If the value is odd, we will add it to the odd_sum
        */
        else{
            odd_sum += x;
        }

        // calculating the total which is all even + odd numbers
        total = even_sum + odd_sum;

        // we are incrementing the x value by 1 for each time it goes through the while loop.
        x++;
    }

    // printing out the values for the even_sum, odd_sum, and the total
    cout << "This is the even " << even_sum << endl;
    cout << "This is the odd " << odd_sum << endl;
    cout << "This is the total " << total << endl;

    return 0;
}