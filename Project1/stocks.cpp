#include <iostream>
#include <string>
#include <array>
#include <unordered_map>
using namespace std;
/*
Resources Used:
Traversing a Map and unordered_map in C++ STL: https://www.geeksforgeeks.org/traversing-a-map-or-unordered_map-in-cpp-stl/
*/

// Define an array to hold number of shares, purchase price, and current value, this represents the StockInfo
typedef array<double, 3> StockInfo; 

typedef unordered_map<string, StockInfo> StockData; // StockData - {Key: Value} { Symbol : [NumberOfShares, PurchasePrice, CurrentValue]}

StockData portfolio; // Define the portfolio as a global variable

// Function prototypes
void addStock();
void deleteStock();
void viewPortfolio();
double calculatePortfolioValue();
void displayMenu();

int main() {
    char choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case '1':
                cout << endl;
                addStock();
                break;
            case '2':
                cout << endl;
                deleteStock();
                break;
            case '3':
                cout << endl;
                viewPortfolio();
                cout << endl;
                break;
            case '4':
                cout << endl;
                cout << "Total Portfolio Value: $" << calculatePortfolioValue() << endl;
                break;
            case '5':
                cout << endl;
                cout << "Exiting program." << endl;
                break;
            default:
                cout << endl;
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}

void addStock() {
    // getting the symbol from the user
    string symbol;
    cout << "Enter stock symbol: ";
    cin >> symbol;

    // Check if the stock already exists in the portfolio using the symbol given from the user
    if (portfolio.find(symbol) != portfolio.end()) {
        cout << "Stock already exists in the portfolio." << endl;
        return;
    }

    
    // stockInfo is initialize as an array following the StockInfo template [NumberOfShares, PurchasePrice, CurrentValue]
    StockInfo stockInfo;
    cout << "Enter number of shares: ";
    cin >> stockInfo[0]; // Number of shares 1st index 
    cout << "Enter purchase price per share: $";
    cin >> stockInfo[1]; // Purchase price 2nd index
    stockInfo[2] = stockInfo[0] * stockInfo[1];   // Calculate and store current value in the 3rd index
    portfolio[symbol] = stockInfo; 
    // portfolio is a global variable - {Key: Value} { Symbol : [NumberOfShares, PurchasePrice, CurrentValue]}
}

void deleteStock() {
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


void viewPortfolio() {
    // checking to see if the portfolio is empty 
    if (portfolio.empty()) {
        cout << "Portfolio is empty." << endl;
        return;
    }

    // if the portfolio is not empty this will run 
    cout << " STOCK PORTFOLIO " << endl;
    cout << endl;
    // Define the iterator type
    // we are iterating over a hashmap, we are defining our iterator as a constant bc it will not be modified
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

double calculatePortfolioValue() {
    double totalValue = 0;

    // By using const_iterator, we indicate that we will not modify the elements of the map while traversing it.
    typedef unordered_map<string, StockInfo>::const_iterator PortfolioIterator;

    // Iterate over the portfolio and calculate the total value
    //  initializes the iterator i to point to the beginning of the portfolio map. 
    // It starts the loop by pointing to the first element of the map.

    // This condition checks whether the iterator i has reached the end of the portfolio map. If i is not equal to portfolio.end(), 
    // the loop continues. portfolio.end() returns an iterator pointing to the position just past the last element of the map.

    // we iterate over the portfolio, making sure that the first value is not also the last value!
    // it = { Symbol : [NumberOfShares, PurchasePrice, CurrentValue]}  
    for (PortfolioIterator it = portfolio.begin(); it != portfolio.end(); it++) {
        const StockInfo &stockInfo = it->second; // it->second refers // it->second = [NumberOfShares, PurchasePrice, CurrentValue]
        totalValue += stockInfo[2]; // stockInfo[2] == CurrentValue 
    }

    return totalValue;
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
