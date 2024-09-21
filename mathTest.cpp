#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

// Declaration of functions
void arithmeticop(char operation, int *correct_answer);
int generate_random();

int main() 
{
    char operation;

    srand(time(NULL));
    int num_correct = 0;
    int num_problems = 0;
  
    time_t current_time;
    char* c_time_string;
    
    printf("Nevaiha Adams' Math Test Program | Main Menu\n");
        
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
    printf("Current time is %s", c_time_string);
    	
    while(1) 
    {
        printf("Enter   'A' for Addition\n	'S' for Subtraction\n	'M' for Multiplication\n	'D' for Division\n	'E' to Exit\n");
        scanf(" %c", &operation);
        operation = toupper(operation);

        while(operation != 'A' && operation != 'S' && operation != 'M' && operation != 'D' && operation != 'E')
        {
            printf("Invalid choice! Please choose a correct option: ");
        	scanf(" %c", &operation);
            operation = toupper(operation);
        }

        if(operation == 'E')
        {
            float percentage = num_correct * 100 / (float) num_problems;
            printf("Number of problems given: %d\n", num_problems);
            printf("Number of correct answers: %d\n", num_correct);
            printf("Percentage of correct answers: %.2f%%\n", percentage);
            break;
        }

        int correct_answer;
        arithmeticop(operation, &correct_answer);
        num_problems++;
        
        int user_answer;
        printf("Enter your answer: ");
        scanf("%d", &user_answer);
    
        if (user_answer == correct_answer) 
        {
            printf("Correct!\n");
            num_correct++;
        }
        else 
        {
            printf("Incorrect\n");
        }
    }
  
    return 0;
}

void arithmeticop(char operation, int *correct_answer)
{
    int num1 = generate_random();
    int num2 = generate_random();
  
    switch(operation)
    {
        case 'A':
            printf("What is %d + %d?\n", num1, num2);
            *correct_answer = num1 + num2;
            break;
        case 'S':
            printf("What is %d - %d?\n", num1, num2);
            *correct_answer = num1 - num2;
            break;
        case 'M':
            printf("What is %d * %d?\n", num1, num2);
            *correct_answer = num1 * num2;
            break;
        case 'D':
            while(num2 == 0)
            {
                num2 = generate_random(); 
            }
            printf("What is %d / %d?\n", num1, num2);
            *correct_answer = num1 / num2;
            break;
    }
}

int generate_random()
{
    return rand() % 100; 
}

