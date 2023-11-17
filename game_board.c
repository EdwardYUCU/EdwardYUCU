#include "game.h"

static Gamestate my_game;

int init_game(void) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		my_game.board[i] = '.';
	}
	my_game.bscore = 0;
	my_game.rscore = 0;
	my_game.steps = 0;
	my_game.turn = 1;
	return my_game.steps;
}

int score_of_blue(void) {
	return my_game.bscore;
}

int score_of_red(void) {
	return my_game.rscore;
}

int step(void) {
	return my_game.steps;
}

int turn(void) {
	return my_game.turn;
}

int valid(int position) {
	if (position < 11 || position > 88 || position % 10 == 0 || position % 10 == 9) {//outside
		return 0;
	}
	else if (my_game.board[position] == 'O' || my_game.board[position] == '#') {//occupied
		return -1;
	}
	else {
		return 1;
	}
}

void updata_board(int position) {//valid check before
	if (my_game.turn == 1) {//blue
		my_game.board[position] = '#';
	}
	else {//red
		my_game.board[position] = 'O';
	}
}

void update_score(int new_score) {
	if (my_game.turn == 1) {
		my_game.bscore += new_score;
	}
	else {
		my_game.rscore += new_score;
	}
}

void add_step(void) {
	my_game.steps++;
}

const Gamestate* show_board(void) {
	return &my_game;
}

void take_turn(void) {
	my_game.turn = 3 - my_game.turn;
}

int game_over() {
	if (my_game.steps == 64 || \
		(my_game.bscore > 150 && my_game.bscore - my_game.rscore >= 15) || \
		(my_game.rscore > 150 && my_game.rscore - my_game.bscore >= 15)) {
		return 1;
	}
	else {
		return 0;
	}
}
