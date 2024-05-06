#include<iostream>
using namespace std;

int main() {

    cout << "Question #1: Pointer Basics" << endl;
    int num = 10;
    int* pNum = &num;
    int** ppNum = &pNum;
    cout << "First Pointer pNum: " << *pNum << endl;
    cout << "Second Pointer ppNum: " << **ppNum << endl;
    cout << endl;




    cout << "Question #2: Pointer Arithmetic" << endl;
    double arr[] = { 1.1, 2.2, 3.3, 4.4, 5.5}; // initialize the array with these values 
    double* arrNums = arr; // set a pointer to the array

    for (int i = 0; i < 5; i++) { 
        // loop over the array
        *arrNums += 1.0; // update the values inside of the array
        cout << *arrNums << " "; // print out the updated value 
        arrNums++; // move the pointer to the next index position 
    }
    cout << endl << endl;

    


    cout << "Question #3: Dynamic Memory Allocation" << endl;
    int* dynamArr = new int[10]; // allocating space in memory for 10 values
    int* tempArr = dynamArr; // setting the array to a pointer

    for (int i = 0; i < 10; i++) { // loop over the array
        *tempArr = i + 1; // populating the array with values, with each space in memory we add 1
        tempArr++; // update the pointer to the next index position
    }
    
    tempArr = dynamArr; // reset the pointer to the start of the array
    int sum = 0; // initialize the sum variable to 0
    for (int i = 0; i < 10; i++) { // loop over the array
        sum+= *tempArr; // for each value inside of tempArr we add it to the sum 
        tempArr++; // move the index position to the next value 
    }

    cout << "The Sum of the Array: " << sum << endl;
    // deallocating memory be deleteing the dynamArr
    delete[] dynamArr; // this is what is initialize in memory so we need to deallocate it
    dynamArr = nullptr; // setting it to a null value to successfully deallocate
    cout << endl;




   cout << "Question #4: Smart Pointers" << endl;
   unique_ptr<int[]> smartArr(new int[10]); // using unique_ptr for smart pointers

   for (int i = 0; i < 10; i++) {
        smartArr[i] = i + 1; // initializing the array, for each value we are adding 1 on to it,
        // ex. [1, 1+1, 2+1, 3+1, .....]
   }
   sum = 0; // resetting the sum value to 0
   for (int i = 0; i < 10; i++) {
        sum += smartArr[i]; // adding every value inside of the smartArr to the sum variable
        // smartArr = [1,2,3,4,5,6,7,8,9,10] --- added up = 55
   }
   cout << "Smart Array Sum: " << sum << endl; // printing the sum from the smartArr
   // The benefits of using unqiue_ptr is that we do not have to manually deallocate the memory, it is done automatically for us.

}