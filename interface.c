#include <stdio.h>
#include "game.h"

//output
void print_game(const Gamestate* my_game) {
    print_turn();
    print_score();
    print_board(my_game);
}

void print_turn(void) {
    if (turn() == 1) {
        printf("%s\n", "This is Blue's turn.");
    }
    else {
        printf("%s\n", "This is Red's turn.");
    }
}

void print_score(void) {
    printf("[ Blue's score = %d; Red's score = %d ]\n", score_of_blue(), score_of_red());
}

void print_board(const Gamestate* my_game) {
    printf("%s\n", "   1 2 3 4 5 6 7 8");
    int i, j;
    for (i = 1; i <= 8; i++) {
        printf("%d ", i);
        for (j = 1; j <= 8; j++) {
            printf("%2c", my_game->board[10 * i + j]);
        }
        puts("");
    }
}

void print_new_score(){}

void print_move(int location) {
    if (turn() == 1) {
        printf("Blue move to %d!\n", location);
    }
    else {
        printf("Red move to %d!\n", location);
    }
}
//input
int read_mode(void) {
    int mode;
    scanf("%d", &mode);
    return mode;
}

int read_pos(void) {
    int position;
    scanf("%d", &position);
    if (valid(position)) {
        return position;
    }
    else {
        return -1;
    }
}
