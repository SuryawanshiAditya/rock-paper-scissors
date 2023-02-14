#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define rock 1
#define paper 2
#define scissor 3
#define player1_win 1
#define player2_win 2
#define draw 0

// This function takes two integer arguments (player1 and player2)
// and returns an integer representing the result of the game.
int ROCK_PAPER_SCISSOR(int player1, int player2)
{
    int result;

    // Compare player choices and determine the winner or if it's a draw.
    if (player1 == rock && player2 == paper)
    {
        result = player2_win;
    }
    else if (player1 == rock && player2 == scissor)
    {
        result = player1_win;
    }
    else if (player1 == paper && player2 == rock)
    {
        result = player1_win;
    }
    else if (player1 == paper && player2 == scissor)
    {
        result = player2_win;
    }
    else if (player1 == scissor && player2 == rock)
    {
        result = player2_win;
    }
    else if (player1 == scissor && player2 == paper)
    {
        result = player1_win;
    }
    else
    {
        result = draw;
    }
    return result;     // Return the result of the game.
}

int get_user_input()
{
    int choise;
    do
    {
        printf("1. ROCK\n"); // Print "ROCK"
        printf("2. PAPER\n");  // print "PAPER"
        printf("3. SCISSOR\n"); //print "SCISSOR"
        printf(" Enter Your Choise [1, 2, 3]:-"); 
        scanf("%d", &choise); // acepting the choise form user
        if (!(choise >= 1 && choise <= 3)) // If the choice is not between 1 and 3 (inclusive)
        {
            printf("ERROR-- Invalid input,it should be 1 or 2 or 3"); // Print an error message
        }

    } while (!(choise >= 1 && choise <= 3));
    return choise; // returning the choise
}

void print_word(int v)
{
    if (v == rock) // If the input value is equal to the rock value
    {
        printf("ROCK\n"); // Print "ROCK"
    }
    else if (v == paper) // If the input value is equal to the paper value
    {
        printf("PAPER\n"); // print "PAPER"
    }
    else if (v == scissor)  // If the input value is equal to the scissor value
    {
        printf("SCISSOR\n"); //print "SCISSOR"
    }
}

int main()
{   // Initializing user score and computer score
    int User_score = 0;
    int Computer_score = 0;

    // Setting the seed for random number generation
    srand(time(NULL));  

     // Variable to keep track of whether the user wants to quit or continue playing
    int quit = 0;
    // While loop to keep playing the game until the user quits
    while (!quit)
    {
        // Get user's input for rock, paper or scissors
        int user_input = get_user_input();
         // Get computer's random choice for rock, paper or scissors
        int computer_choise = (rand() % 3) + 1;

        // Print the computer's choice and the user's choice
        printf(" Computer chose: ");
        print_word(computer_choise);
        printf("User chose: ");
        print_word(user_input);

         // Determine the result of the game based on user's and computer's choices
        int result = ROCK_PAPER_SCISSOR(user_input, computer_choise); 
        // Check the result of the game and update the scores accordingly
        if (result == draw)
        {
            printf("It is draw");
        }
        else if (result == player1_win)
        {
            printf("User wins and computers lost the round\n");
            User_score++;
        }
        else if (result == player2_win)
        {
            printf("Computer wins and user lost the round\n");
            Computer_score++;
        }

        // Print the current scores of user and computer
        printf("\n");
        printf("---------------------------\n");
        printf("user score : %d\n", User_score);
        printf("computer score : %d\n", Computer_score);
        printf("---------------------------\n");
        printf("\n\n");
        // Ask user if they want to continue playing or quit the game  
        printf("If you want to continue the game enter any integer key , 0 to terminate.\n ");
        int response;
        scanf("%d", &response);
        // If the user enters 0, quit the game
        if (response == 0)
        {
            quit = 1;
        }
        system("clear"); // Clear the screen for the next round
    } // END OF WHILE ;


// Print the final scores and determine the winner of the game
    printf("....Final score....\n");
    printf("\n");
    printf("---------------------------\n");
    printf("user score : %d\n", User_score);
    printf("computer score : %d\n", Computer_score);
    printf("---------------------------\n");
    printf("\n\n");
    if (User_score == Computer_score)
    {
        printf("GAME IS DRAW\n ");
    }
    else if (User_score > Computer_score)
    {
        printf("USER WINS THE GAME\n");
    }
    else if (User_score < Computer_score)
    {
        printf("COMPUTER WINS THE GAME \n");
    }

    return 0;
}