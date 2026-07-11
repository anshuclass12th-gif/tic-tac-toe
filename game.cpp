#include <iostream>
using namespace std;

char board[3][3];
char currentPlayer;

// Initialize Board
void initializeBoard() {
    char ch = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
    currentPlayer = 'X';
}

// Display Board
void displayBoard() {
    cout << "\n";
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

// Check Win
bool checkWin() {

    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;
    }

    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == currentPlayer &&
            board[1][i] == currentPlayer &&
            board[2][i] == currentPlayer)
            return true;
    }

    // Diagonals
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}

// Check Draw
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;

    return true;
}

// Make Move
void makeMove() {

    int choice;
    cout << "\nPlayer " << currentPlayer << ", Enter Position (1-9): ";
    cin >> choice;

    if (choice < 1 || choice > 9) {
        cout << "Invalid Position!\n";
        makeMove();
        return;
    }

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Position Already Taken!\n";
        makeMove();
        return;
    }

    board[row][col] = currentPlayer;
}

// Switch Player
void switchPlayer() {
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

// Main
int main() {

    char playAgain;

    do {

        initializeBoard();

        while (true) {

            displayBoard();

            makeMove();

            if (checkWin()) {
                displayBoard();
                cout << "\nPlayer " << currentPlayer << " Wins!\n";
                break;
            }

            if (checkDraw()) {
                displayBoard();
                cout << "\nGame Draw!\n";
                break;
            }

            switchPlayer();
        }

        cout << "\nPlay Again? (Y/N): ";
        cin >> playAgain;

    } while (playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for Playing!\n";

    return 0;
}