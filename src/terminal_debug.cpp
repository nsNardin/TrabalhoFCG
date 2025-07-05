// This program runs a terminal minesweeper_logic at the backend
//This allows to debug the game from the terminal.

#include "minesweeper_logic.cpp"
#include <string>
#include <iostream>

// Function to represent one block as a character
char blockToChar(Block block) {
    if (block.revealed){
        if (block.bomb) {
            return 'X';
        } else if (block.bomb_counter == 0) {
            return ' ';
        } else {
            return std::to_string(block.bomb_counter)[0];
        }
    } else {
        if (block.flag) {
            return 'F';
        } else {
            return '?';
        }
    }
}

// Function to print the board
void printBoard(Board board) {
    for (int y = 0; y < BOARD_HEIGHT; y++) {
        for (int x = 0; x < BOARD_WIDTH; x++) {
            std::cout << blockToChar(board.getBlock(x, y));
        }
        std::cout << std::endl;
    }
}

// Main function
int main() {
    Board board;
    board.init();
    board.start();
    printBoard(board);
    return 0;
}