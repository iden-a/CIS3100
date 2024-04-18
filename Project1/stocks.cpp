#include <iostream>
#include <string>
#include <array>
#include <unordered_map>
using namespace std;

// Define an array to hold number of shares, purchase price, and current value, this represents the StockInfo
typedef array<double, 3> StockInfo; 

typedef unordered_map<string, StockInfo> StockData; // this is the StockData key - Symbol values - StockInfo 

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
                addStock();
                break;
            case '2':
                deleteStock();
                break;
            case '3':
                viewPortfolio();
                break;
            case '4':
                cout << "Total Portfolio Value: $" << calculatePortfolioValue() << endl;
                break;
            case '5':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}

void addStock() {
    string symbol;
    cout << "Enter stock symbol: ";
    cin >> symbol;

    // Check if the stock already exists in the portfolio
    if (portfolio.find(symbol) != portfolio.end()) {
        cout << "Stock already exists in the portfolio." << endl;
        return;
    }

    // Add new stock to the portfolio
    // each stock we are adding will follow the template of Stockinfo - Num of Shares, Purchase Price, Current Value
    StockInfo stockInfo;
    cout << "Enter number of shares: ";
    cin >> stockInfo[0]; // Number of shares 1st index 
    cout << "Enter purchase price per share: $";
    cin >> stockInfo[1]; // Purchase price 2nd index
    stockInfo[2] = stockInfo[0] * stockInfo[1];     // Calculate and store current value 3rd index
    portfolio[symbol] = stockInfo; // key,value pair
}

void deleteStock() {
    string symbol;
    cout << "Enter stock symbol to delete: ";
    cin >> symbol;

    // Check if the stock exists in the portfolio
    if (portfolio.find(symbol) != portfolio.end()) {
        portfolio.erase(symbol);
        cout << "Stock deleted successfully." << endl;
    } else {
        cout << "Stock symbol not found in the portfolio." << endl;
    }
}


void viewPortfolio() {
    if (portfolio.empty()) {
        cout << "Portfolio is empty." << endl;
        return;
    }

    cout << "Portfolio:" << endl;
    // Define the iterator type
    typedef unordered_map<string, StockInfo>::const_iterator PortfolioIterator;

    // Iterate over the portfolio and print stock information
    for (PortfolioIterator it = portfolio.begin(); it != portfolio.end(); ++it) {
        const string& symbol = it->first;
        const StockInfo& stockInfo = it->second;

        cout << "Symbol: " << symbol << ", Shares: " << stockInfo[0]
             << ", Purchase Price: $" << stockInfo[1]
             << ", Current Value: $" << stockInfo[2] << endl;
    }
}

double calculatePortfolioValue() {
    double totalValue = 0;

    // Define the iterator type
    typedef unordered_map<string, StockInfo>::const_iterator PortfolioIterator;

    // Iterate over the portfolio and calculate the total value
    for (PortfolioIterator it = portfolio.begin(); it != portfolio.end(); ++it) {
        const StockInfo& stockInfo = it->second;
        totalValue += stockInfo[2]; // Add current value of the stock
    }

    return totalValue;
}


void displayMenu() {
    cout << "\nStock Portfolio Management System" << endl;
    cout << "1. Add Stock" << endl;
    cout << "2. Delete Stock" << endl;
    cout << "3. View Portfolio" << endl;
    cout << "4. Calculate Total Portfolio Value" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}
