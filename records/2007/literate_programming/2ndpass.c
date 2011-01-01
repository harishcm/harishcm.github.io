/******************************************************************************
****************** Simulating Perfect Competition - 2nd Pass ****************** 
******************************************************************************/

/*
** Let's make things more interesting in this 2nd pass of our attempt at
** simulating Perfect Competition.
**
** As in the 1st pass, the simulation starts off with several companies laid
** out in a 2-d array for easy handling and representation. The companies again
** compete for a fixed number of contracts. In this 2nd pass though, the number
** of contracts need not be equal to the initial number of companies.
**
** Again, similar to the 1st pass, companies that get one or more contracts 
** stay on till the next round. However, to make things more interesting,
** companies that get more than one contract increase in size corresponding to 
** the number of contracts received. 
** i.e 1 contract -> remain the same size, 2 contracts -> +1 unit in size, 
**     3 contracts -> +2 units in size 
** Companies that do not get any contracts decrease by 1 unit in size. If their
** size becomes zero, they die out.
** 
** We still take all companies to be equally capable in competing for contracts
** and the contract issuers to be totally unbiased.
**
** As a final addition, there is a chance that new companies can take the place
** of those that have died out. With this, lets get on with the program!
*/

/* 
** We will again be dealing with simple input output and using random numbers,
** so we include the following headers.
*/
#include <stdio.h> /* Input Output functions */
#include <stdlib.h> /* Random number generators */
#include <time.h> /* time() function to set initial seed for random numbers */

/* 
** Next we define a few constants to be used throughout the program 
*/
/* Number of rounds of competition per run */
#define ROUNDS_PER_RUN 1000
/* Number of companies = ROWS*COLS */
#define ROWS 10 
#define COLS 10
/* Number of contracts available */
#define NUM_CONTRACTS 90
/* 
** Chance for a new company emerging at an empty space in the array of 
** companies
*/
#define CHANCE_NEW_ENTRY 0.2
				

/* 
** Now we create the functions that we need.
*/

/*
** First, a function to throw out a random integer that corresponds to the
** array subscript of the company chosen to receive.
*/
int rand_coy_chosen()
{
        int r;
        r = (int) (rand()/(RAND_MAX + 1.0)*ROWS*COLS);
        return r;
}

/*
** Next, a couple of utility functions. initialise_array() fills all elements
** of the array with the number given by 'number'. This is used to initialise
** the array of companies at the start and the result array before every
** competition.
*/
void initialise_array(int array[ROWS][COLS],int number)
{
        int i, j;

	for (i=0;i<ROWS;i++)
		for (j=0;j<COLS;j++)
			array[i][j] = number;
}
/*
** print_array() is used to print the array of companies onto the screen. 
*/
void print_array(int array[ROWS][COLS], int run)
{
        int i, j;

	printf("Run %i:\n", run);
	printf("Rounds so far: %i:\n", run*ROUNDS_PER_RUN);

	for (i=0;i<ROWS;i++){
		for (j=0;j<COLS;j++)
			printf("%-7i ",array[i][j]);
		printf("\n");
        }

	printf("\n");
}
/*
** ask_for_input() returns an integer from the user's input. It is used by the
** program to determine if it is tasked to do another run or to quit.
*/
int ask_for_input()
{
	int input;
	
	printf("Enter: \n");
        printf("(1) for next run or\n");
        printf("(2) to quit\n");

	scanf("%i", &input);

	return input;
}

/* 
** Here we come to the function that simulates the competition. 
** 
** First the result array is initialised to '-1's. This represents the initial
** condition of companies decreasing in size by 1 unit if they fail to receive
** any contracts. 
**
** As before, a random winner is picked and if the company exists, the result
** is added to the result array. If the company does not exist, the result is
** discarded. This goes on till all the predefined number of contracts have 
** been awarded.
**
** Then, the elements of the result array are added to the corresponding
** elements of the array of companies. Thus, companies evolve according to the 
** number of contracts they receive.
*/
void competition(int companies[ROWS][COLS])
{
	int i, j, result[ROWS][COLS], winner, contract=0;

	initialise_array(result, -1);

	while(contract <= NUM_CONTRACTS){
		winner = rand_coy_chosen();

		if (*(&companies[0][0]+winner) != 0){
			(*(&result[0][0]+winner))++;
			contract++;
		}
	}

	for (i=0;i<ROWS;i++)
		for (j=0;j<COLS;j++)
			if (companies[i][j] != 0)
				companies[i][j] += result[i][j];
	
	return;
}

/* The last function to be defined, add_new_entries(), will search the array of 
** companies for 'empty slots' and generate a random number in the interval
** [0,1]. If the number generated is less than the the predefined chance of
** new entries, a new company of size 1 is created. Else, no new company is 
** created. 
*/
void add_new_entries(int companies[ROWS][COLS])
{
	int i, j;
	float r;
	for(i=0;i<ROWS;i++)
		for(j=0;j<COLS;j++)
			if (companies[i][j] == 0){
				r = rand()/(RAND_MAX + 0.0);
				if (r < CHANCE_NEW_ENTRY)
					companies[i][j] = 1;
			}

	return; 
}

/* 
** Having defined the required constants and functions, we come to the main()
** function. First we set the variable to hold the 'user_input', the 'run_num'
** and the current 'round' of competition. Second, we set the seed for the 
** random number generator to the current time and intialise & print the 
** array of 'companies'.
**
** Unlike the 1st pass, one run of the simulation- the number of rounds of
** competition as defined by ROUNDS_PER_RUN- is carried out and the result
** printed.
** 
** The program then asks the user if he / she wants to perform the next run. A
** negative answer the program to quit while a positive answer performs another
** run.
**
*/
int main(void)
{
	int companies[ROWS][COLS], user_input=1, run_num=0;
	int round;

	srand( (unsigned int)time(NULL) );

	initialise_array(companies, 1);
	print_array(companies, run_num);

	do{
		printf("Running Simulation...\n\n");
		
		for (round=0;round<ROUNDS_PER_RUN; round++){
			competition(companies);
			add_new_entries(companies);
		}
		run_num++;
		print_array(companies, run_num);

		user_input = ask_for_input();
	}while(user_input != 2);

	return 0;
}
		

		
		

