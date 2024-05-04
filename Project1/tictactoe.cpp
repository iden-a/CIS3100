#include <iostream>
using namespace std;

// function prototypes
void displayBoard(char [][3], int ,int);
void getPlayerChoice(char [][3]);
bool playerWinOrLose(char [][3], char); 
void getResult(char [][3]); 
void resetBoard(char [][3], int ,int); 
void displayMenu(); 

int main() {
                    // the board
char board[3][3] = { { ' ', ' ', ' ' }, 
                     { ' ', ' ', ' ' }, 
                     { ' ', ' ', ' ' } }; 

    // do while loop to display game menu and enter/exit the game
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case 1:
            cout << endl;
            displayBoard(board, 3,3);
            getPlayerChoice(board);
            break;

            case 2:
            cout << endl;
            cout << "\tExiting the Game!" << endl;
            break;

            default:
            cout << "\tInvalid Choice" << endl;
        }
    
    } while( choice != 2); // loop continues as long as users do not pick 2

    return 0;
}

void displayBoard(char board[][3], int rows, int cols) {
    // utilizing tab for a more appealing UI
    // printing to board to the console for interaction w/ users
    cout << "\tPlayer 1 - X " << endl;
    cout << "\tPlayer 2 - O " << endl << endl;
    cout << "\t-------------" << endl;
    for (int i = 0; i < rows; i++)
	    {
            cout << "\t| ";

		    for (int j = 0; j < cols; j++) {
			    cout << board[i][j] << " | ";
		    }
		    cout << endl;
            cout << "\t-------------" << endl;

	    }
	    return;
}

bool playerWinOrLose(char board[][3], char player) {

    /*  EXAMPLE BOARD W/ INDEX
        0 [0 1 2] 
        1 [0 1 2]
        2 [0 1 2]
    */

    // check the rows  - if a player gets a row, return true
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == player  && board[row][1] == player && board[row][2] == player){
            return true;
        }
    }

    // check the columns - if a players gets a column, return true
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return true;
        }
    }
    
    // check the first diagonal - if a player gets a diagonal return true
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }

    // check the second diagonal - if a player gets a diagonal return true
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    // if none of the above work return false - no winner (draw)
    return false;
}

void getResult(char board[][3]) {

    bool boardFilled = true; // setting the condition to true 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') { // if we see that any part of the board is empty 
                boardFilled = false; // we change the condition to false 
                break; // this is exiting the inner loop
            }
        }
    }

    // calling the playerWinLose function to get the result  
    // in case of win, lose, or draw we want to reset the board so another game can occur
    if (playerWinOrLose(board, 'X')) {
        cout << "\tPlayer 1 - Team X Wins!" << endl;
        resetBoard(board, 3,3);
    }
    else if (playerWinOrLose(board, 'O')) {
        cout << "\tPlayer 2 - Team O Wins!" << endl;
        resetBoard(board, 3,3);
    }
    else if (boardFilled) { // if the board is filled and there is no winner, then it must be a draw
        cout << "\tDraw! " << endl;
        resetBoard(board, 3,3);
    }
    else {
        cout << "\tContinue Playing!" << endl;
    }
}

void getPlayerChoice(char board[][3]) {

    int user_row, user_col;

    int player = 1;

    do {
        cout << endl;
        // check to see which player it is 
        cout << "\tPlayer " << player << " Go!" << endl;

        // get the row
        cout << "\tEnter Row: ";
        cin >> user_row;
        // get the column 
        cout << "\tEnter Column: ";
        cin >> user_col;

        // making the user_row and user_col match the proper index position
        user_row--; 
        user_col--;

        // make sure the user inputted row and column does not exceed the board values 
        // if the board[row][col] != '-' then it must be equal to X or O, placing a value there would be invalid
        if (user_row < 0 || user_row >= 3 || user_col < 0 || user_col >= 3 || board[user_row][user_col] != ' ' ) {
            cout << "\tInvalid Move. Try Again." << endl;
            continue;
        }

        // update the board with the player that is currently playing
        // if it is not player 1 then it must be player 2
        board[user_row][user_col] = (player == 1 ? 'X' : 'O');

        // display the board - call the function
        // get the result - call the function 
        cout << endl;
        displayBoard(board,3,3);
        getResult(board);

        // switch the players 
        // if player is at 1, switch the player to 2, if not switch to 1
        player = (player == 1 ? 2 : 1);
        
    // the loop will run as long as player X has not won and play O has not won
    // it will also continue as long as there is no space left on the board
    } while (!playerWinOrLose(board, 'X') && !playerWinOrLose(board, 'O') && (board[user_row][user_col] != ' '));

}

void resetBoard(char board[][3], int rows, int cols) {
    // resetting the board 
        for (int i = 0; i < rows; i++)
	    {
		    for (int j = 0; j < cols; j++)
		    {
			    board[i][j] = ' ';
		    }
		    cout << endl;
	    }
	    return;
}

//printing the menu
void displayMenu() {
    cout << endl;
    cout << "\t-----------------------------" << endl;
    cout << "\t-- Tic-Tac-Toe Dashboard -- " << endl;
    cout << endl;
    cout << "\t1. Play!" << endl;
    cout << "\t2. Quit. " << endl;
    cout << endl;
    cout << "\t-----------------------------" << endl;
    cout << "\tChoice: ";
}
