#ifndef __GAME__HH__
#define __GAME__HH__    1

#define BOARD_SIZE 89

typedef struct gamestate {
    int board[BOARD_SIZE];
    int steps;
    int bscore;
    int rscore;
    int turn;
} Gamestate;

int init_game(void);
int score_of_blue(void);
int score_of_red(void);
int step(void);
int turn(void);
int valid(int position);
void updata_board(int position);
void update_score(int new_score);
void add_step(void);
const Gamestate* show_board(void);
void take_turn(void);
int game_over(void);
//game_board.c

//output
void print_game(const Gamestate* my_game);
void print_turn(void);
void print_score(void);
void print_board(const Gamestate* my_game);
void print_move(int location);
//input
int read_mode(void);
int read_pos(void);
//interface.c

int human_player(void);
//human_player.c


int cal_show_score(const int board[], int location);
//data_process.c
#endif // !__GAME__HH__