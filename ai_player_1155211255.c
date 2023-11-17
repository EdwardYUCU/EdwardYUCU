#include <stdlib.h>
#define BOARD_SIZE 89

void change_board(int* board);

int ai_player(int* board, int player) {
	int my_board[BOARD_SIZE];
    int i;
    for (i = 0; i < BOARD_SIZE; i++) {
        my_board[i] = board[i];
    }
    change_board(my_board);

    for (i = 0; i < BOARD_SIZE; i++) {
        if (my_board[i] == 0 && i >= 11 && i % 10 && i % 10 != 9) {
            return i;
        }
    }
    return 0;
}

void change_board(int* board) {
    int i;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i] == '#') {
            board[i] = 1;
        }
        else if (board[i] == 'O') {
            board[i] = 2;
        }
        else {
            board[i] = 0;
        }
    }
}
