#include<iostream>
using namespace std;

/*

Create a program to calculate how many months and years it will take for a user to pay off
his/her student loan.

Ask the user to input the total amount of money owed in student loan debt, the annual interest
rate being charged, and how much will be paid each month towards it. (HINT: You will need to
handle having an annual interest rate calculate the amount of interest to be charged monthly.
Simply divide the annual by 12). Display a message informing the user how many months it will
take until the loan is fully paid off.

*/

int main() {

    double student_loan_debt, monthly_payment, annual_interest;  // declaring the debt, monthly payment, and annual interest
    int months = 0 ; // setting the initial value of months to 0
    double interest_accrued = 0;
    double total_interest_accrued;

    cout << "What is your student loan debt amount?: ";
    cin >> student_loan_debt; // receiving user input for the debt amount

    cout << "What is the annual interest rate being charged?: ";
    cin >> annual_interest; // receiving user input for the annual interest amount

    annual_interest /= 100;
    double monthly_interest = annual_interest/12; // the interest that is charged per month

    cout << "What is the amount you are paying each month?: ";
    cin >> monthly_payment; // receiving user input for the monthly payment 

    
    while ( student_loan_debt > 0) {
        total_interest_accrued += student_loan_debt * monthly_interest; // Accumulating interest accrued
        interest_accrued = student_loan_debt * monthly_interest; // this holds the interest that is accrued based on the monthly interest
        student_loan_debt += interest_accrued; // updating the student loan with the interest accrued for each month
        student_loan_debt -= monthly_payment; // subtracting the monthly payment from the student loan debt
        months++; // incrementing the months until the student loan debt reaches 0
    }

    cout << "It will take " << months << " months to pay off your student loans!" << endl;
    cout << "This is the total interest accrued " <<  total_interest_accrued << endl;
    return 0;
}