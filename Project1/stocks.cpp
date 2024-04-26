#include <iostream>
#include <string>
#include <array>
#include <unordered_map>
using namespace std;
/*
Resources Used:
Traversing a Map and unordered_map in C++ STL: https://www.geeksforgeeks.org/traversing-a-map-or-unordered_map-in-cpp-stl/

Dealing with cin failure: https://stackoverflow.com/questions/5864540/infinite-loop-with-cin-when-typing-string-while-a-number-is-expected

I was having issues with my complier, that is why I am specifying the type with typedef
https://stackoverflow.com/questions/2566027/what-is-the-use-of-typedef
*/

// Define an array to hold number of shares, purchase price, and current value, this represents the StockInfo
typedef array<double, 3> StockInfo; 

typedef unordered_map<string, StockInfo> StockData; // StockData - {Key: Value} { Symbol : [NumberOfShares, PurchasePrice, CurrentValue]}


// Function prototypes
void addStock(StockData &portfolio);
void deleteStock(StockData &portfolio);
void viewPortfolio(StockData &portfolio);
double calculatePortfolioValue(StockData &portfolio);
double getvalidinput( const string &prompt, const string &error);
void displayMenu();

int main() {

    StockData portfolio; // Define the portfolio as a global variable

    int choice;
    do {
        // prompting the user to pick a menu item
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << endl;
                addStock(portfolio);
                break;
            case 2:
                cout << endl;
                deleteStock(portfolio);
                break;
            case 3:
                cout << endl;
                viewPortfolio(portfolio);
                cout << endl;
                break;
            case 4:
                cout << endl;
                cout << "Total Portfolio Value: $" << calculatePortfolioValue(portfolio) << endl;
                break;
            case 5:
                cout << endl;
                cout << "Exiting program." << endl;
                break;
            default:
                cout << endl;
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5); // as long as the user decides to not exit the program, the loop will run.

    return 0;
}

double getvalidinput(const string &prompt, const string &error) {

    double input;

    // this will execute when the function is called
    while (true) {
        cout << prompt; 
        cin >> input;

        // Check if the input is a valid number and meets the condition
        if (input >= 1) {
            break;  // Valid input, exit the loop
        } else {
            // Not valid, show error message and clear the input buffer
            cout << error << endl;
        }
    }

    return input;
}


void addStock(StockData &portfolio) {
    // getting the symbol from the user
    string symbol;
    cout << "Enter stock symbol: ";
    cin >> symbol;

    if (cin.fail()) {
        cout << "ERROR -- Input error occurred";

    // Clear the failure state
        cin.clear(); 

    // Discard any incorrect input left in the input buffer
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
    // Check if the stock already exists in the portfolio using the symbol given from the user
    // portfolio.find() - search operation 
    // portfolio.end() - signifies the end of the portfolio 
    // if our search operation does not reach the end of our portfolio, it means it found a symbol that already exists
    if (portfolio.find(symbol) != portfolio.end()) {
        cout << "Stock already exists in the portfolio." << endl;
        return;
        }
    }
    
    // stockInfo is initialize as an array following the StockInfo template [NumberOfShares, PurchasePrice, CurrentValue]
    StockInfo stockInfo;
    // double numShares = getvalidinput();
    double numShares = getvalidinput("Enter Number of Shares: ", "Please enter a positive Number of Shares.");

    double purchasePrice = getvalidinput("Enter Purchase Price: ", "Purchase Price value must be positive.");
    
    double currentVal = numShares * purchasePrice;

    stockInfo[0] = numShares;
    stockInfo[1] = purchasePrice;
    stockInfo[2] = currentVal;   // Calculate and store current value in the 3rd index
    portfolio[symbol] = stockInfo; 
}

void deleteStock(StockData &portfolio) {
    // getting the symbol from the user
    string symbol;
    cout << "Enter stock symbol to delete: ";
    cin >> symbol;

    // Check if the stock exists in the portfolio, if it exists we delete it using the built in erase method
    if (portfolio.find(symbol) != portfolio.end()) {
        portfolio.erase(symbol);
        cout << "Stock deleted successfully." << endl;
    } else {
        // if it does not exist we let the user know
        cout << "Stock symbol not found in the portfolio." << endl;
    }
}


void viewPortfolio(StockData &portfolio) {
    // checking to see if the portfolio is empty 
    if (portfolio.empty()) {
        cout << "Portfolio is empty." << endl;
        return;
    }

    // if the portfolio is not empty this will run 
    cout << " STOCK PORTFOLIO " << endl;
    cout << endl;

    // Define the iterator type
    // we are iterating over a hashmap, we are defining our iterator as a constant bc we will not be changing the values inside of portfolio
    typedef unordered_map<string, StockInfo>::const_iterator PortfolioIterator;

    // it stands for iterator 
    // we are using the begin and end built in methods, we are looking at the first value inside of the portfolio and the last value to make sure they are not the same
    for (PortfolioIterator it = portfolio.begin(); it != portfolio.end(); it++) {
        // we want to print out the values in our hashmap, we are going to point to the symbol and stockInfo so that each pair inside of the hashmap is printed on the console.
        const string &symbol = it->first; // pointing to the key
        const StockInfo &stockInfo = it->second; // pointing to the value

        
        cout << " Symbol: " << symbol << " | Shares: " << stockInfo[0] << " | Purchase Price: $" << stockInfo[1] << " | Current Value: $" << stockInfo[2] << endl;
        cout << endl;
    }
}

double calculatePortfolioValue(StockData &portfolio) {
    double totalValue = 0;

    // we are using the const_iterator because we only want to read the data values, there is no intention of changing the values.
    // we want to ensure that there is no modification of the values as we are iterating over them.
    typedef unordered_map<string, StockInfo>::const_iterator PortfolioIterator;

    // we iterate over the portfolio, the loop will continue until we reach the last value.
    // it = { Symbol : [NumberOfShares, PurchasePrice, CurrentValue]}  
    for (PortfolioIterator it = portfolio.begin(); it != portfolio.end(); it++) {
        const StockInfo &stockInfo = it->second; // it->second refers // it->second = [NumberOfShares, PurchasePrice, CurrentValue]
        totalValue += stockInfo[2]; // stockInfo[2] == CurrentValue 
    }

    return totalValue; // returning the totalValue to the user
}


void displayMenu() {
    cout << " _________________________________________________" << endl;
    cout << "| Stock Portfolio Management System               |" << endl;
    cout << "| 1. Add Stock                                    |" << endl;
    cout << "| 2. Delete Stock                                 |" << endl;
    cout << "| 3. View Portfolio                               |" << endl;
    cout << "| 4. Calculate Total Portfolio Value              |" << endl;
    cout << "| 5. Exit                                         |" << endl;
    cout << " _________________________________________________" << endl;
    cout << "Enter your choice:  ";
}
