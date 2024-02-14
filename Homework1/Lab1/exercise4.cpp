#include<iostream>
#include <iomanip> // importing library for setprecision
using namespace std;

/*
Write a C++ program that will calculate how much of a profit an investor will make. You will need to get
the following three inputs:
 the number of shares the investor purchased 
 the price of the stock (per share) when the investor purchased it 
 the price of the stock (per share) now 
*/

int main() {

    // declaring the variables 
    double num_of_shares, current_price, purchase_price, profit;

    // needed to have the $ value to be at 2 decimals.
    cout << fixed << setprecision(2);

    // asking the user the values that need to be computed
    cout << "Number of Shares: " << endl;
    cin >> num_of_shares;

    cout << "Current Price: " << endl;
    cin >> current_price;

    cout << "Purchase Price: " << endl;
    cin >> purchase_price;

    // calculating the profit with the equation given
    profit = (num_of_shares * current_price) - (num_of_shares * purchase_price);

    // displaying the profit and depending on the num_of_shares given by the user
    cout << "You have made a profit of $" << profit << " dollars since you bought " << num_of_shares << " shares of this stock." << endl;

    return 0;
}