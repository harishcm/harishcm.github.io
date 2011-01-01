/******************************************************************************
****************** Simulating Perfect Competition - 1st Pass ****************** 
******************************************************************************/

/*
** Here we start off in our attempt to simulate Perfect Competition.
**
** In this program, there initially are a fixed number of companies. At every 
** round, the companies vie for contracts. Those that receive contracts 
** survive, while those that don't die out. 
**
** We are taking all the companies to be equally capable and all the contract 
** issuers to be completely unbiased.
**
** For simplicity, there is neither growth nor strengthening of companies as 
** they keep getting more contracts. Companies that die out are not replaced by
** new ones either.
*/ 

/* 
** We will be doing simple input output and using random numbers, so we include
** the necessary headers.
*/
#include <stdio.h> /* For input output */
#include <stdlib.h> /* For random number functions */
#include <time.h> /* To access the time for better random number generation */

/* 
** The companies are represented by elements in a 2-d array as they will be 
** displayed as such in the output later. Here we define the number of 
** companies we start off with as rows and cols of the array. 
** 
** Thus, number of companies = rows*cols.
*/
#define ROWS 4
#define COLS 6

/* 
** We also define the number of rounds of competiton per run of the simulation.
** A higher number of round per run makes it easier to simulate over longer
** time periods.
*/ 
#define ROUNDS 1

/*
** Now we go on to define a few useful functions. 
*/

/* 
** First, a function to throw out a random integer that corresponds to the 
** array subscript of the company chosen to receive the contract.
*/
int rand_coy_chosen()
{
	int r;
	r = (int) (rand()/(RAND_MAX + 1.0)*ROWS*COLS);
	return r;
}

/*
** Next, a couple of utility functions. initialise_board() fills the board with
** '1's to represent the starting state where all companies are alive.
*/
void initialise_board(int board[ROWS][COLS])
{
	int i, j;

	for (i=0;i<ROWS;i++)
		for (j=0;j<COLS;j++)
			board[i][j] = 1;
}
/*
** And print_board() prints out the board onto the screen.
*/
void print_board(int board[ROWS][COLS], int run)
{
	int i, j;

	printf("Run %i:\n", run);
	
	for (i=0;i<ROWS;i++){
		for (j=0;j<COLS;j++)
			printf("%i ",board[i][j]);
		printf("\n");
	}
	printf("\n");
}
	
/* Here we come to the function that simulates the competition. A random winner
** is chosen and if the company still exists, the result is added to the result
** board. Else, the result is discarded. This goes on till all the contracts 
** have been awarded.
**
** Then, the result board is checked for existing companies that did not get any
** contracts during this round. These companies die out. So, only those that
** received contracts live till the next round.
*/
void competition(int board[ROWS][COLS])
{
	int i, j, result[ROWS][COLS]={{0}}, winner, trial=0;
	
	while(trial <= ROWS*COLS){
		winner=rand_coy_chosen();
		if (*(&board[0][0]+winner) != 0){
			(*(&result[0][0]+winner))++;
			trial++;
		}
	}

	for (i=0;i<ROWS;i++)
		for (j=0;j<COLS;j++)
			if (result[i][j]==0)
				board[i][j]=0;
	
	return;
}

/* 
** Having defined required constants and functions, we come to the main()
** function. First, we set variables to hold the user 'input' the 'run'
** and the current 'round'. Second, we set the seed for the random number
** generator to the current time and intialise and print the array 'board' 
** that represents the companies. 
** 
** The user is then asked if he / she wants to perfom the next run. If 
** not, the program will exit.
** 
** If the user wants to perform the next run, the competition is carried 
** out for the number of rounds defined above. The resulting 'board' is printed
** out and the user is again asked if he / she wants perform the next run.
*/
int main(void)
{
	int board[ROWS][COLS], input=0, run=0;
	unsigned int round ;

	srand( (unsigned int)time(NULL) );
	
	initialise_board(board);
	print_board(board,run);

	printf("Enter: \n");
	printf("(1) for next run or\n");
	printf("(2) to quit\n");
	scanf("%i", &input);
	
	while (input != 2){
		for (round=0;round<ROUNDS;round++)
			competition(board);
			
		run++;
		print_board(board,run);
		
		printf("Enter: \n");
		printf("(1) for next run or\n");
		printf("(2) to quit\n");
		scanf("%i", &input);
	}

	return 0;
}
		


