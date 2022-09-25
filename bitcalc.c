#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int validateInteger(long unsigned* hexdec);

// I have these here for ops to make my code look beter
#define QUIT_OPT 'q'
#define AND_OPT '&'
#define OR_OPT '|'
#define XOR_OPT '^'

// funciton to validate operation
int validOperation(char user_operator){
	if(user_operator == '&' || user_operator == '|' || user_operator == '^' || user_operator == 'q')
		return 1;
	else
		return 0;
}

// function to validate an integer greater than 1
int validIntegerGreaterThanOne(int user_int){
	char c;
	while(c != '\n'){scanf("%c", &c); }
	if(user_int > 1)
		return 1;
	else
		return 0;
}

// function to validate if a number is an integer
int validInteger(long unsigned* hexdec){
	int scanReturn = scanf(" %lx", hexdec);
	char c;
	while(c != '\n')
		scanf("%c", &c);
	if((scanReturn >= 1) && (*hexdec <= 0xffffffff))
		return 1;
	else{
		printf("ERROR! Please intput a hexadecimal that has at least 8 characters\n");
		return 0;
	}
}
// Function to print binary of hex
void hexToBinary(unsigned bin){
	unsigned binary[32];
	for(int i = 0; i<32; i++){
		int remainder = bin % 2;
		binary[i] = remainder;
		bin /= 2;
	}
	for(int i = 31; i >= 0; i--){
		if( i % 4 == 3)
			printf(" ");
		printf("%d", binary[i]);
	}
	printf(" ");

}

int clean_stdin()
{
    char c;
    while(c!='\n')
	    scanf("%c", &c);
}

int main(){

	//instantiate the variables I will be using
	char user_operator;
	int user_first_int;
	int valid_input;
	char user_int_input;
	int i;	
	bool valid_user_operation;
	int count;
	bool valid_hex;
	char str[100];
	do {
		
		printf("\nPlease enter an operation: ");
		scanf("%s", &user_operator);
		valid_user_operation = validOperation(user_operator);
		valid_input = 0;
		if(user_operator != 'q' && valid_user_operation == 1){// if statement to leave out 'q' option	
			while(valid_input == 0){
				printf("Please enter an integer: ");
				scanf("%d", &user_first_int);
				valid_input = validIntegerGreaterThanOne(user_first_int);
				if(valid_input == 0)
					printf("PLEASE INPUT AN INTEGER GREATER THAN 1\n");
	       
			}
			long hexArray[user_first_int];
			for(i = 0; i< user_first_int; i++){ // for loop to add integers to an array
				do{
					printf("Enter integer %d: ", (i+1));
					valid_input = validInteger(&hexArray[i]);
				}while(valid_input == 0);
			}
			
			int sum;
			switch(user_operator){ // switch cases to do each equation and print out the solution
				case AND_OPT:
					sum = hexArray[0];
					printf("\nBinary Operation:\n");
					printf("\n      = ");
					hexToBinary(hexArray[0]);
					for(int i = 1; i < user_first_int; i++){
						sum = sum & hexArray[i];
						printf("\n      & ");
						hexToBinary(hexArray[i]);
					}
					printf("\n      = ");
					hexToBinary(sum);
					printf("\n");

					// Print hex
					printf("\nHexadecimal operation:\n");
					for(int i = 0; i < user_first_int; i++){
						if(i<1)
							printf("\n         ");
						else
							printf("\n      &  ");
						printf("%08lx", hexArray[i]);
					}
					printf("\n      =  %08lx\n", hexArray[i]);
					break;

				case OR_OPT:
					sum = hexArray[0];
					printf("\nBinary Operation:\n");
					printf("\n      = ");
					hexToBinary(hexArray[0]);
					for(int i = 1; i < user_first_int; i++){
						sum = sum | hexArray[i];
						printf("\n      | ");
						hexToBinary(hexArray[i]);
					}
					printf("\n      = ");
					hexToBinary(sum);
					printf("\n");

					// Print hex
					printf("\nHexadecimal operation:\n");
					for(int i = 0; i < user_first_int; i++){
						if(i<1)
							printf("\n         ");
						else
							printf("\n      |  ");
						printf("%08lx", hexArray[i]);
					}
					printf("\n      =  %08lx\n", hexArray[i]);
					break;

				case XOR_OPT:
					sum = hexArray[0];
					printf("\nBinary Operation:\n");
					printf("\n      = ");
					hexToBinary(hexArray[0]);
					for(int i = 1; i < user_first_int; i++){
						sum = sum ^ hexArray[i];
						printf("\n      ^ ");
						hexToBinary(hexArray[i]);
					}
					printf("\n      = ");
					hexToBinary(sum);
					printf("\n");

					// Print hex
					printf("\nHexadecimal operation:\n");
					for(int i = 0; i < user_first_int; i++){
						if(i<1)
							printf("\n         ");
						else
							printf("\n      ^  ");
						printf("%08lx", hexArray[i]);
					}
					printf("\n      =  %08lx\n", hexArray[i]);
					break;

				default:
					printf("PLEASE ENTER A VALID OPERATOR: &, |, ^, q\n"); // this is just to have a default here
			}
		}
	} while (user_operator != QUIT_OPT); // This will stop the program once 'q' is input
	return 0;

}
