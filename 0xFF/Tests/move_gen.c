#include <stdio.h>
#include <assert.h>

#include "../board.h"
#include "../util.h"

int failed_tests = 0;
int total_tests = 0;

void move_gen_test(char str[73], int depth, int nodes){
	total_tests++;
	
	board_t board;
	init_board_t(&board,str);
	
	if(perft(&board,depth) != nodes){
		printf("FAILED TEST : DEPTH %d : %s\n",depth,str);
		failed_tests++;
	}
	else 
		printf("PASSED TEST : DEPTH %d : %s\n",depth,str);
}

int main(){	
	printf("Beginning Tests\n");
	
	/* Standard board setups */
	move_gen_test("rnbqkbnrppppppppeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeePPPPPPPPRNBQKBNR11110000",1,20);
	move_gen_test("rnbqkbnrppppppppeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeePPPPPPPPRNBQKBNR11110000",2,420);
	move_gen_test("rnbqkbnrppppppppeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeePPPPPPPPRNBQKBNR11110000",3,9322);
	move_gen_test("rnbqkbnrppppppppeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeePPPPPPPPRNBQKBNR11110000",4,206603);
	move_gen_test("rnbqkbnrppppppppeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeePPPPPPPPRNBQKBNR11110000",5,5071954);
	move_gen_test("rnbqkbnrppppppppeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeePPPPPPPPRNBQKBNR11110000",6,124120395);
	
	printf("\nCompleted Tests with %d failures\n",failed_tests);
}
