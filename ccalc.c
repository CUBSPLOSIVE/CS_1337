#include <stdio.h>
#include <stdbool.h>

// I have these here for ops to make my code look beter
#define ADDITION_OPT '+'
#define SUBTRACTION_OPT '-'
#define MULTIPLICATION_OPT '*'
#define DIVISION_OPT '/'
#define QUIT_OPT 'q'

// funciton to validate operation
bool validOperation(char user_operator){
	if(user_operator == '+' || user_operator == '-' || user_operator == '*' || user_operator == '/' || user_operator == 'q')
		return 1;
	else
		return 0;
}

// function to validate an integer greater than 1
bool validIntegerGreaterThanOne(int user_int){
	char c;
	while(c != '\n'){scanf("%c", &c); }
	if(user_int > 1)
		return 1;
	else
		return 0;
}

// function to validate if a number is an integer
bool validInteger(int user_int){
	int checkInt = scanf("%d", &user_int);
	char c;
	while(c!= '\n') {scanf("%c", &c); }
	if(checkInt >= 1)
		return 1;
	else
		printf("PLEASE INPUT A VALID INTEGER\n");
		return 0;
}

int main(){

	//instantiate the variables I will be using
	char user_operator;
	int user_first_int;
	bool valid_input;
	int user_int_input;
	int i;	
	bool valid_user_operation;
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
			int intArray[user_first_int];
			for(i = 0; i< user_first_int; i++){ // fo loop to add integers to an array
				//valid_input = 0;
				printf("Enter integer %d: ", (i+1));
				valid_input = scanf(" %d", &user_int_input);
				while(valid_input != 1){ // it breaks right here after the user inputs two non-ints in a row
					valid_input = validInteger(intArray[i]);
					printf("Enter integer %d: ", (i+1));
				}
				intArray[i] = user_int_input; // add the current item in the loop to array
			}
			
			int sum;
			switch(user_operator){ // switch cases to do each equation and print out the solution
				case ADDITION_OPT:
					sum = 0;
					printf("\nComputing: ");
					for (i = 0; i< user_first_int; i++){
						sum += intArray[i];
						printf("%d", intArray[i]);
						if(i+1 < user_first_int)
							printf(" + ");
					}
					printf(" = %d\n", sum);
					break;

				case SUBTRACTION_OPT:
					sum = intArray[0];
					printf("\nComputing: %d - ", intArray[0]);
					for(i = 1; i< user_first_int; i++){
						sum -= intArray[i];
						printf("%d", intArray[i]);
						if(i + 1 < user_first_int)
							printf(" - ");
					}
					printf(" = %d\n", sum);
					break;
			
				case MULTIPLICATION_OPT:
					sum = intArray[0];
					printf("\nComputing: %d * ", intArray[0]);
					for(i = 1; i < user_first_int; i++){
						sum *= intArray[i];
						printf("%d", intArray[i]);
						if(i + 1 < user_first_int)
							printf(" * ");
					}
					printf(" = %d\n", sum);
					break;

				case DIVISION_OPT:
					sum = intArray[0];
					printf("\nComputing: %d / ", intArray[0]);
					for(i = 1; i < user_first_int; i++){
						sum = sum / intArray[i];
						printf("%d", intArray[i]);
						if(i + 1 < user_first_int)
							printf(" / ");
					}
					printf(" = %d\n", sum);
					break;
			
				default:
					printf("PLEASE ENTER A VALID OPERATOR\n"); // this is just to have a default here
			}
		}
	} while (user_operator != QUIT_OPT); // This will stop the program once 'q' is input
	return 0;

}
