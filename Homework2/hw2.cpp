#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// Declare a global ofstream object for output
// this allows us to create files and write data into files 
ofstream outputFile;

// Function prototypes
bool read3arrays(int exam1[], int exam2[], int exam3[], int k);
void print1array(const int nums[], int k);
void makeweightedavg(const int exam1[], int exam2[], int exam3[], int weightedavg[], int k);
void findsmallestandpos(const int arr[], int k, int &smallest, int &position);

int main() {
    const int k = 20; // Max size of the arrays
    int exam1[k], exam2[k], exam3[k], weightedavg[k]; // declaring the array variables

    // if the function returns false, return an error to the console.
    if (!read3arrays(exam1, exam2, exam3, k)) {
        cout << "Error opening input file or reading data." << endl;
        outputFile.close();
        return 1; // error
    }
    
    outputFile.open("scores_output.txt"); 
    // if the output file is unable to successfully open, return an error to the console.
    if (!outputFile.is_open()) {
        cout << "Error opening output file." << endl;
        return 1; // error
    }
    
    // formatting the data for the output file
    outputFile << "Original Exam Scores:" << endl;
    outputFile << endl;

    outputFile << "Exam 1 Scores: " << endl;
    print1array(exam1, k);
    outputFile << endl << endl;

    outputFile << "Exam 2 Scores: " << endl;
    print1array(exam2, k);
    outputFile << endl << endl;

    outputFile << "Exam 3 Scores: " << endl;
    print1array(exam3, k);
    outputFile << endl << endl;

    makeweightedavg(exam1, exam2, exam3, weightedavg, k);
    outputFile << endl << endl;

    outputFile << "Weighted Averages: " << endl;
    print1array(weightedavg, k);
    outputFile << endl << endl;

    // formatting the data for the output file
    int smallest, position;
    findsmallestandpos(exam1, k, smallest, position);
    outputFile << "The smallest element in Exam 1 is " << smallest << " this value occurs in position " << position <<  " of the array." << endl;
    findsmallestandpos(exam2, k, smallest, position);
    outputFile << "The smallest element in Exam 2 is " << smallest << " this value occurs in position " << position <<  " of the array." << endl;
    findsmallestandpos(exam3, k, smallest, position);
    outputFile << "The smallest element in Exam 3 is " << smallest << " this value occurs in position " << position <<  " of the array." << endl;
    findsmallestandpos(weightedavg, k, smallest, position);
    outputFile << "The smallest element in Weighted Averages is " << smallest << " this value occurs in position " << position <<  " of the array." << endl;

    outputFile.close();
    return 0;
}

bool read3arrays(int exam1[], int exam2[], int exam3[], int k) {
    // reading the exam scores file 
    ifstream inputFile("scores.txt");
    if (!inputFile.is_open()) return false; // return false is the file fails to open

    // as we are reading the data inside of the file
    // this loop will continue as long as i is less than the max size of the array and we have not reached the end of the exam scores file.
    for (int i = 0; i < k && !inputFile.eof(); i++) {
        // we are reading data from the input file and adding it into the arrays
        inputFile >> exam1[i] >> exam2[i] >> exam3[i];
    }
    inputFile.close(); // closing the file when we are done
    return true; // executed successfully
}


void print1array(const int nums[], int k) {
    // k - max size of the array
    // nums - represents the arrays we will receive 
    for (int i = 0; i < k; i++) {
        // specifying 6 elements per line
        // printing each value from the array into the output file.
        outputFile << setw(6) << nums[i];
        if ((i + 1) % 6 == 0)
            outputFile << endl; // creating a new line once we have 6 values on a line
    }
    outputFile << endl;
}

void makeweightedavg(const int exam1[], int exam2[], int exam3[], int weightedavg[], int k) {

    for (int i = 0; i < k; i++) {
        // for each value inside of exam1, exam2, and exam3
        // we are calculating the weighted average and storing it inside of the array
        // we are calculating the average by each array's index
        // so exam1[0], exam2[0], exam3[0] will be computed and stored in weightedAvg[0]
        weightedavg[i] = (exam1[i] + 2 * exam2[i] + 3 * exam3[i]) / 6;
    }
}

void findsmallestandpos(const int arr[], int k, int &smallest, int &position) {
    // defaulting the smallest value to start at the beginning of the array
    smallest = arr[0];

    // position is given the default value of 0, this will be updated when we find the 
    // index position of the smallest value
    position = 0;

    // we are starting our pointer at 1, while 1 is less than k (the max size of the array), we are going to update our iterator (i)
    for (int i = 1; i < k; i++) {

        // if we see a value that is less than our current smallest value
        if (arr[i] < smallest) {

            // we update the 'smallest' variable to hold the value we have just seen 
            smallest = arr[i];

            // we update the position to become the index of the new smallest value 
            position = i;
        }
    }
}