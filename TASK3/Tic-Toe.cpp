#include <iostream>
#include <vector>
void displayBoard(const std::vector<char>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << board[i * 3 + j] << ' ';
        }
        std::cout << '\n';
    }
}
bool checkWin(const std::vector<char>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i * 3] == player && board[i * 3 + 1] == player &&

board[i * 3 + 2] == player) {
            return true;
        }
        if (board[i] == player && board[i + 3] == player && board[i +6] == player) {

            return true;
        }
    }
    if (board[0] == player && board[4] == player && board[8] ==player) {

    return true;
    }

    if (board[2] == player && board[4] == player && board[6] ==
    player) {

        return true;
    }
    return false;
}
bool checkDraw(const std::vector<char>& board) {
    for (char c : board) {
        if (c == ' ') {
            return false;
            }
    }
    return true;
}
int main() {
    std::vector<char> board(9, ' ');
    char currentPlayer = 'X';
    bool playAgain;
    do {
        displayBoard(board);
        int move;
        std::cout << "Player " << currentPlayer << ", enter your move (1-9): ";

        std::cin >> move;
        --move;
        if (move < 0 || move > 8 || board[move] != ' ') {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }
        board[move] = currentPlayer;
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            std::cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if (checkDraw(board)) {


        displayBoard(board);
        std::cout << "It's a draw!\n";
        break;
    }
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    std::cout << "Do you want to play again? (y/n): ";
    char answer;
    std::cin >> answer;
    playAgain = (answer == 'y' || answer == 'Y');
    } while (playAgain);
    return 0;
}