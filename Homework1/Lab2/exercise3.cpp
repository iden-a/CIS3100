#include <iostream>
using namespace std;

/*
Write a program using if, else if and else statements that will sort three characters in
ascending order (smallest to largest). Remember that characters are stored in ASCII! Another
way of saying this might be to put the characters in alphabetical order, but be careful of
lowercase versus uppercase values, as well as handling special characters (those that are not
letters, such as the dollar sign.) Ask the user to input three characters, then ultimately output
the same three characters in the correct order.
*/

int main()
{
    // i used the bubble sorting algorithm
    // this example helped me along the way as well!
    // https://prepinsta.com/data-structures-algorithms/sorting-of-array/

    char char_1, char_2, char_3; // receiving user input for the characters

    cout << "Enter Character 1: ";
    cin >> char_1;

    cout << "Enter Character 2: ";
    cin >> char_2;

    cout << "Enter Character 3: ";
    cin >> char_3;

    char array[3] = {char_1, char_2, char_3}; // storing the user input inside of an array, this way i will be able to just sort through the array!

    cout << "This is what you entered: " << endl;
    // looping through the array, returning each value inside of the array for the user to see, i represents the index value 
    for (int i = 0; i < 3; i++)
    {
        cout << array[i] << " ";
    }

    // nested for loop
    // this is the first loop we are doing 
    for (int i = 0; i < 3; i++)
    {
        // this is the second loop we are doing
        for (int j = 0; j < 3; j++)
        // for the first iteration, if value i and greater than value j -- swap. This will continue for each iteration in the list
        {if (array[i] < array[j])
            {
                char temp = array[i];  // if i is less than j, we will store i in the temp variable.
                array[i] = array[j]; // we will update i with the value of j, this is the first step in our swap
                array[j] = temp; // we will then take the value that is stored in temp (i), and store it inside of j
            }
                // this process will continue until we are done iterating through the array.
        }
    }

    cout << endl;
    cout << "This is the array after sorting: " << endl;
      for (int i = 0; i < 3; i++)
    {
        cout << array[i] << " ";
    }
    return 0;
}