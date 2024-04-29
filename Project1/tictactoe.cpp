#include <iostream>
using namespace std;

// having issues with the win, loss, draw function 
// draw should only appear if the board is completely filled 
// win and loss is showing up correctly so far!

void displayBoard(char [][3], int ,int);
void getPlayerChoice(char [][3]);
bool playerWinOrLose(char [][3], char);
void getResult(char [][3]);

int main() {

char board[3][3] = {
                        {'-', '-', '-'},
						{'-', '-', '-'},
						{'-', '-', '-'}
};

    cout << "Tic-Tac-Toe" << endl;
    displayBoard(board, 3, 3);
    getPlayerChoice(board);

    return 0;
}

void displayBoard(char board[][3], int rows, int cols) {

    for (int i = 0; i < rows; i++)
	    {
		    for (int j = 0; j < cols; j++)
		    {
			    cout << board[i][j] << " ";
		    }
		    cout << endl;

	    }
	    return;
}


bool playerWinOrLose(char board[][3], char player) {
    /*
        0 [0 1 2] 
        1 [0 1 2]
        2 [0 1 2]
    */
    // check the rows  - for loop iterating over the board 
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == player  && board[row][1] == player && board[row][2] == player){
            return true;
        }
    }

    // check the columns 
    for (int col = 0; col < 3; col++) {
        if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
            return true;
        }
    }
    
    // check the first diagonal
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }

    // check the second diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }

    // if none of the above work return false - no winner
    return false;

}

void getResult(char board[][3]){

    bool boardFilled = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != '_') {
                boardFilled = true;
                break; // this is exiting the inner loop
            }
        }
        // we need to also check the outer loop, so  our loop isnt continuing on for no reason 
        if (boardFilled) 
            break;
    }


    // calling the playerWinLose function to get the result 
    if (playerWinOrLose(board, 'X'))
        cout << "Player X Wins!   " << "Board Filled " << boardFilled << endl;
    
    else if (playerWinOrLose(board, 'O')) 
        cout << "Player O Wins!" << "Board Filled " << boardFilled << endl;

    else if (!boardFilled) 
        cout << "Draw!  " << "ConsoleLogo:" << boardFilled << endl;
        

};


void getPlayerChoice(char board[][3]) {

    int user_row, user_col;

    int player = 1;



    do {
        
        cout << endl;
        cout << "Go!" << endl;
        // check to see which player it is 
        // get the row
        cout << "Enter Row: ";
        cin >> user_row;

        cout << "Enter Column: ";
        cin >> user_col;
        // get the column 

        user_row--;
        user_col--;

        // make sure the user inputted row and column does not exceed the board values 
        if (user_row < 0 || user_row >= 3 || user_col < 0 || user_col >= 3 || board[user_row][user_col] != '-' ) {
            cout << "Invalid Move. Try Again.";
            continue;
        }


        // update the board with the player that is currently playing
        board[user_row][user_col] = (player == 1 ? 'X' : 'O');

        // display the board - call the function
        // get the result - call the function 
        cout << endl;
        displayBoard(board,3,3);
        getResult(board);



        // switch the players 
        player = (player == 1 ? 2 : 1);
        // if player is at 1, switch the player to 2, if not switch to 1
        
    // the loop will run as long as player X has not won and play O has not won
    // it will also continue as long as there is no space left on the board
    } while (!playerWinOrLose(board, 'X') || !playerWinOrLose(board, 'O') || (board[user_row][user_col] != '-'));

}

