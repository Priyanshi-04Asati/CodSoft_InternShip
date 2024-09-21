#include <iostream>
using namespace std;

void displayBoard();
bool checkWin();
bool checkDraw();
void switchPlayer();
void resetBoard();

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentPlayer = 'X'; 

int main() {
    bool playAgain = true;
    char choice;

    do {
        int move;
        bool gameWon = false;
        bool gameDraw = false;

        resetBoard(); 

        while (!gameWon && !gameDraw) {
            displayBoard(); 
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;

            if (move >= 1 && move <= 9) {
                int row = (move - 1) / 3;
                int col = (move - 1) % 3;

                if (board[row][col] != 'X' && board[row][col] != 'O') {
                    board[row][col] = currentPlayer;
                    gameWon = checkWin();
                    gameDraw = checkDraw();

                    if (!gameWon && !gameDraw) {
                        switchPlayer(); 
                    }
                }
                else {
                    cout << "Invalid move, try again.\n";
                }
            } else {
                cout << "Invalid input! Please enter a number between 1 and 9.\n";
            }
        }
        displayBoard(); 

        if (gameWon) {
            cout << "Player " << currentPlayer << " wins the game!\n";
        } else if (gameDraw) {
            cout << "The game is a draw!\n";
        }

        cout << "Do you want to play again? (Y/N): ";
        cin >> choice;
        playAgain = (choice == 'Y' || choice == 'y');

    } while (playAgain);

    cout << "Thanks for playing!\n";
    return 0;
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}
bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}
bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; 
            }
        }
    }
    return true; 
}
void switchPlayer() {
    if (currentPlayer == 'X') {
        currentPlayer = 'O';
    } else {
        currentPlayer = 'X';
    }
}
void resetBoard() {
    char counter = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = counter++; 
        }
    }
    currentPlayer = 'X'; 
}
