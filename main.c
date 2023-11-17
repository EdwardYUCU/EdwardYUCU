#include <stdio.h>
#include "game.h"
#include "ai_player_1155211255.h"

int main(void) {
	int mode;
	int position;
	int new_score = 0;

	init_game();
	printf("%s", "Please choose the game mode:");
	mode = read_mode();

	if (mode == 1) {
		while (!game_over()) {
			print_game(show_board());
			position = human_player();
			if (valid(position) == 1) {
				print_move(position);
				add_step();
				new_score = cal_show_score(show_board()->board, position);
				updata_board(position);
				update_score(new_score);
				take_turn();
			}
			else if (valid(position) == 0) {
				printf("%s", "Input out of the game board, please ");
				printf("%s\n", "input again(in[11, 88]).");
			}
			else {
				printf("%s", "Input invalid, the provided location is ");
                printf("%s\n", "not empty, please input again.");
			}
	    }
    }
    else {
        while (!game_over()) {
            print_game(show_board());
            if (turn() == 1) {
                position = human_player();
            }
            else {
                position = ai_player(show_board()->board, turn());
            }

            if (valid(position) == 1) {
                print_move(position);
                add_step();
                new_score = cal_show_score(show_board()->board, position);
                updata_board(position);
                update_score(new_score);
                take_turn();
            }
            else if (valid(position) == 0) {
                printf("%s", "Input out of the game board, please ");
                printf("%s\n", "input again(in[11, 88]).");
            }
            else {
                printf("%s", "Input invalid, the provided location is ");
                printf("%s\n", "not empty, please input again.");
            }
        }
    }
    print_game(show_board());
    printf("%s\n", "Game over");
    if (score_of_blue() > score_of_red()) {
        printf("%s\n", "Blue wins!");
    }
    else if (score_of_blue() < score_of_red()) {
        printf("%s\n", "Red wins!");
    }
    else {
        printf("%s\n", "It is a draw!");
    }
	
    return 0;
}
