#include <iostream>
#include <iomanip> // importing library for setprecision
using namespace std;

/* Write a program for the IRS that will calculate income tax. You will need as input the person’s
annual salary.
This year you paid $_______ dollars in
tax. So your net salary after taxes are taken out is $________.

*******************
Extra Credit:
Ask the user if he/she has any children.
If they do have children, ask them how many, and calculate their new tax amount factoring in a
5% deduction per child off their pre-tax annual salary.  // they will not be paying regular tax anymore!

Ask the user if he/she makes student loan payments, ask how much interest was paid on the
loan last year, and calculate their new tax amount by subtracting the student loan interest from
the pre-tax annual salary (after child deduction).
*/

int main()
{
    cout << fixed << setprecision(2);
    double annual_salary, tax_paid, net_salary, child_deduction_amount = 0;
    string response, loan_response; // yes/no

    int children; // tax amount per child is 5%

    // this is for the student loans
    double student_loan_debt, monthly_payment, annual_interest; // declaring the debt, monthly payment, and annual interest
    int months = 0;                                             // setting the initial value of months to 0
    double interest_accrued = 0;
    double total_interest_accrued = 0;

    cout << "Enter Annual Salary: ";
    cin >> annual_salary;

    cout << "Do you have any children? (yes/no): ";
    cin >> response;

    cout << "Do you pay student loans? (yes/no): ";
    cin >> loan_response;

    

    if (annual_salary <= 12000)
    {
        // if the user has children but does not pay student loans
        if (response == "yes" && loan_response == "no")
        {
            cout << "___________________________________________________________________________" << endl;
            cout << endl;
            cout << "How many children do you have?: ";
            cin >> children;

            if (children >= 1)
            {
                // if they have children, we are giving them a child deduction
                child_deduction_amount = children * 0.05 * annual_salary;

                // if they have children, we are updating their annual salary with the child deduction amount
                annual_salary -= child_deduction_amount;
                tax_paid = annual_salary * 0.06;
            }

            net_salary = annual_salary - tax_paid;
        }

        // if the user does not have child but they pay student loans
        else if (response == "no" && loan_response == "yes")
        {
            cout << "___________________________________________________________________________" << endl;
            cout << endl;
            cout << "What is your student loan debt amount?: $";
            cin >> student_loan_debt; // receiving user input for the debt amount

            cout << "What is the annual interest rate being charged?: %";
            cin >> annual_interest; // receiving user input for the annual interest amount

            annual_interest /= 100;
            double monthly_interest = annual_interest / 12; // the interest that is charged per month

            cout << "What is the amount you are paying each month?: $";
            cin >> monthly_payment; // receiving user input for the monthly payment

            while (student_loan_debt > 0)
            {
                total_interest_accrued += student_loan_debt * monthly_interest; 
                interest_accrued = student_loan_debt * monthly_interest;        
                student_loan_debt += interest_accrued;                          
                student_loan_debt -= monthly_payment;                           
                months++;                                                       
            }

            annual_salary -= total_interest_accrued;
            tax_paid = annual_salary * 0.06;
            net_salary = annual_salary - tax_paid;
        }

        // if the user has children AND they have student loans
        else if (response == "yes" && loan_response == "yes")
        {
            cout << "___________________________________________________________________________" << endl;
            cout << endl;
            cout << "How many children do you have?: ";
            cin >> children;

            cout << "What is your student loan debt amount?: $";
            cin >> student_loan_debt; // receiving user input for the debt amount

            cout << "What is the annual interest rate being charged?: %";
            cin >> annual_interest; // receiving user input for the annual interest amount

            annual_interest /= 100;
            double monthly_interest = annual_interest / 12; // the interest that is charged per month

            cout << "What is the amount you are paying each month?: $";
            cin >> monthly_payment; // receiving user input for the monthly payment

            if (children >= 1)
                child_deduction_amount = children * 0.05 * annual_salary;

            while (student_loan_debt > 0)
            {
                total_interest_accrued += student_loan_debt * monthly_interest; 
                interest_accrued = student_loan_debt * monthly_interest;        
                student_loan_debt += interest_accrued;                          
                student_loan_debt -= monthly_payment;                           
                months++;                                                       
            }

            annual_salary -= (child_deduction_amount + total_interest_accrued);
            tax_paid = annual_salary * 0.06;
            net_salary = annual_salary - tax_paid;
        }

        else
            tax_paid = annual_salary * 0.06;
    }

    else if (annual_salary >= 12001 && annual_salary <= 38000)
    {
        // if the user has children but does not pay student loans
        if (response == "yes" && loan_response == "no")
        {
            cout << "___________________________________________________________________________" << endl;
            cout << endl;
            cout << "How many children do you have?: ";
            cin >> children;

            if (children >= 1)
            {
                // if they have children, we are giving them a child deduction
                child_deduction_amount = children * 0.05 * annual_salary;

                // if they have children, we are updating their annual salary with the child deduction amount
                annual_salary -= child_deduction_amount;
                tax_paid = annual_salary * 0.27;
            }

            net_salary = annual_salary - tax_paid;
        }

        // if the user does not have child but they pay student loans
        else if (response == "no" && loan_response == "yes")
        {
            cout << "___________________________________________________________________________" << endl;
            cout << endl;
            cout << "What is your student loan debt amount?: $";
            cin >> student_loan_debt; // receiving user input for the debt amount

            cout << "What is the annual interest rate being charged?: %";
            cin >> annual_interest; // receiving user input for the annual interest amount

            annual_interest /= 100;
            double monthly_interest = annual_interest / 12; // the interest that is charged per month

            cout << "What is the amount you are paying each month?: $";
            cin >> monthly_payment; // receiving user input for the monthly payment

            while (student_loan_debt > 0)
            {
                total_interest_accrued += student_loan_debt * monthly_interest; 
                interest_accrued = student_loan_debt * monthly_interest;        
                student_loan_debt += interest_accrued;                          
                student_loan_debt -= monthly_payment;                           
                months++;                                                       
            }

            annual_salary -= total_interest_accrued;
            tax_paid = annual_salary * 0.27;
            net_salary = annual_salary - tax_paid;
        }

        // if the user has children AND they have student loans
        else if (response == "yes" && loan_response == "yes")
        {
            cout << "___________________________________________________________________________" << endl;
            cout << endl;
            cout << "How many children do you have?: ";
            cin >> children;

            cout << "What is your student loan debt amount?: $";
            cin >> student_loan_debt; // receiving user input for the debt amount

            cout << "What is the annual interest rate being charged?: %";
            cin >> annual_interest; // receiving user input for the annual interest amount

            annual_interest /= 100;
            double monthly_interest = annual_interest / 12; // the interest that is charged per month

            cout << "What is the amount you are paying each month?: $";
            cin >> monthly_payment; // receiving user input for the monthly payment

            if (children >= 1)
                child_deduction_amount = children * 0.05 * annual_salary;

            while (student_loan_debt > 0)
            {
                total_interest_accrued += student_loan_debt * monthly_interest; 
                interest_accrued = student_loan_debt * monthly_interest;       
                student_loan_debt += interest_accrued;                         
                student_loan_debt -= monthly_payment;                           
                months++;                                                       
            }

            annual_salary -= (child_deduction_amount + total_interest_accrued);
            tax_paid = annual_salary * 0.27;
            net_salary = annual_salary - tax_paid;
        }

        else
            tax_paid = annual_salary * 0.27;
    }

    else if (annual_salary >= 38001 && annual_salary <= 55000)
    {

        // if the user has children but does not pay student loans
        if (response == "yes" && loan_response == "no")
        {
            cout << "___________________________________________________________________________" << endl;
            cout << endl;
            cout << "How many children do you have?: ";
            cin >> children;

            if (children >= 1)
            {
                // if they have children, we are giving them a child deduction
                child_deduction_amount = children * 0.05 * annual_salary;

                // if they have children, we are updating their annual salary with the child deduction amount
                annual_salary -= child_deduction_amount;
                tax_paid = annual_salary * 0.33;
            }

            net_salary = annual_salary - tax_paid;
        }

        // if the user does not have child but they pay student loans
        else if (response == "no" && loan_response == "yes")
        {
            cout << "___________________________________________________________________________" << endl;
            cout << endl;
            cout << "What is your student loan debt amount?: $";
            cin >> student_loan_debt; // receiving user input for the debt amount

            cout << "What is the annual interest rate being charged?: %";
            cin >> annual_interest; // receiving user input for the annual interest amount

            annual_interest /= 100;
            double monthly_interest = annual_interest / 12; // the interest that is charged per month

            cout << "What is the amount you are paying each month?: $";
            cin >> monthly_payment; // receiving user input for the monthly payment

            while (student_loan_debt > 0)
            {
                total_interest_accrued += student_loan_debt * monthly_interest; 
                interest_accrued = student_loan_debt * monthly_interest;        
                student_loan_debt += interest_accrued;                          
                student_loan_debt -= monthly_payment;                          
                months++;                                                       
            }

            annual_salary -= total_interest_accrued;
            tax_paid = annual_salary * 0.33;
            net_salary = annual_salary - tax_paid;
        }

        // if the user has children AND they have student loans
        else if (response == "yes" && loan_response == "yes")
        {
            cout << "___________________________________________________________________________" << endl;
            cout << endl;
            cout << "How many children do you have?: ";
            cin >> children;

            cout << "What is your student loan debt amount?: $";
            cin >> student_loan_debt; // receiving user input for the debt amount

            cout << "What is the annual interest rate being charged?: %";
            cin >> annual_interest; // receiving user input for the annual interest amount

            annual_interest /= 100;
            double monthly_interest = annual_interest / 12; // the interest that is charged per month

            cout << "What is the amount you are paying each month?: $";
            cin >> monthly_payment; // receiving user input for the monthly payment

            if (children >= 1)
                child_deduction_amount = children * 0.05 * annual_salary;

            while (student_loan_debt > 0)
            {
                total_interest_accrued += student_loan_debt * monthly_interest; 
                interest_accrued = student_loan_debt * monthly_interest;        
                student_loan_debt += interest_accrued;                          
                student_loan_debt -= monthly_payment;                           
                months++;                                                       
            }

            annual_salary -= (child_deduction_amount + total_interest_accrued);
            tax_paid = annual_salary * 0.33;
            net_salary = annual_salary - tax_paid;
        }

        else
            tax_paid = annual_salary * 0.33;
    }

    else
    {
        // if the user has children but does not pay student loans
        if (response == "yes" && loan_response == "no")
        {
            cout << "___________________________________________________________________________" << endl;
            cout << endl;
            cout << "How many children do you have?: ";
            cin >> children;

            if (children >= 1)
            {
                // if they have children, we are giving them a child deduction
                child_deduction_amount = children * 0.05 * annual_salary;

                // if they have children, we are updating their annual salary with the child deduction amount
                annual_salary -= child_deduction_amount;
                tax_paid = annual_salary * 0.39;
            }

            net_salary = annual_salary - tax_paid;
        }

        // if the user does not have child but they pay student loans
        else if (response == "no" && loan_response == "yes")
        {
            cout << "___________________________________________________________________________" << endl;
            cout << endl;
            cout << "What is your student loan debt amount?: $";
            cin >> student_loan_debt; // receiving user input for the debt amount

            cout << "What is the annual interest rate being charged?: %";
            cin >> annual_interest; // receiving user input for the annual interest amount

            annual_interest /= 100;
            double monthly_interest = annual_interest / 12; // the interest that is charged per month

            cout << "What is the amount you are paying each month?: $";
            cin >> monthly_payment; // receiving user input for the monthly payment

            while (student_loan_debt > 0)
            {
                total_interest_accrued += student_loan_debt * monthly_interest; 
                interest_accrued = student_loan_debt * monthly_interest;       
                student_loan_debt += interest_accrued;                          
                student_loan_debt -= monthly_payment;                           
                months++;                                                       
            }

            annual_salary -= total_interest_accrued;
            tax_paid = annual_salary * 0.39;
            net_salary = annual_salary - tax_paid;
        }

        // if the user has children AND they have student loans
        else if (response == "yes" && loan_response == "yes")
        {
            cout << "___________________________________________________________________________" << endl;
            cout << endl;
            cout << "How many children do you have?: ";
            cin >> children;

            cout << "What is your student loan debt amount?: $";
            cin >> student_loan_debt; // receiving user input for the debt amount

            cout << "What is the annual interest rate being charged?: %";
            cin >> annual_interest; // receiving user input for the annual interest amount

            annual_interest /= 100;
            double monthly_interest = annual_interest / 12; // the interest that is charged per month

            cout << "What is the amount you are paying each month?: $";
            cin >> monthly_payment; // receiving user input for the monthly payment

            if (children >= 1)
                child_deduction_amount = children * 0.05 * annual_salary;

            while (student_loan_debt > 0)
            {
                total_interest_accrued += student_loan_debt * monthly_interest; 
                interest_accrued = student_loan_debt * monthly_interest;        
                student_loan_debt += interest_accrued;                          
                student_loan_debt -= monthly_payment;                           
                months++;                                                      
            }

            annual_salary -= (child_deduction_amount + total_interest_accrued);
            tax_paid = annual_salary * 0.39;
            net_salary = annual_salary - tax_paid;
        }

        else
            tax_paid = annual_salary * 0.39;
    }

    cout << "___________________________________________________________________________" << endl;
    cout << endl;
    cout << "It will take " << months << " months to pay off your student loans!" << endl;
    cout << "Total Interest Accrued: $" << total_interest_accrued << endl;
    cout << "Child Deduction: $" << child_deduction_amount << endl;
    cout << "Child Deduction + Interest Accrued: $" << child_deduction_amount + total_interest_accrued << endl;
    cout << "Tax Paid: $" << tax_paid << endl;
    cout << "Annual Salary: $" << annual_salary << endl;
    cout << "Net Salary: $" << net_salary << endl;

    return 0;
}