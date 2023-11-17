basic : main.o data_process.o game_board.o human_player.o \
		  ai_player_1155211255.o interface.o
	gcc main.o data_process.o game_board.o human_player.o \
		ai_player_1155211255.o interface.o -o basic -lm

main.o : game.h ai_player_1155211255.h

data_process.o : game.h

interface.o : game.h

ai_player_1155211255.o : game.h

human_player.o : game.h

game_board.o :

.PHONY : clean
clean : 
	-rm basic main.o data_process.o game_board.o human_player.o \
		  ai_player_1155211255.o interface.o

