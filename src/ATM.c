/*
 * Programmer: Henrik A. Christensen     Date Completed: in progress
 * Instructor: Kurt Nørmark              Class:          Imperative Programming
 *
 * Coming soon...
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

void get_input(int *withdraw);
bool is_valid_input(int amout_to_withdraw);
void payout(int *payout_amount, int *hundreds, int *fifties, int *twenties, int *tens);

int main(void)
{
  int withdraw = 0;
  int hundred_notes = 0;
  int fifty_notes = 0;
  int twenty_notes = 0;
  int ten_notes = 0;

  get_input(&withdraw);
  payout(&withdraw, &hundred_notes, &fifty_notes, &twenty_notes, &ten_notes);

  printf("\n-------");
  printf("\n%d hundreds", hundred_notes);
  printf("\n%d fifties", fifty_notes);
  printf("\n%d twenties", twenty_notes);
  printf("\n%d tens", ten_notes);
  printf("\n%d left", withdraw);

  return EXIT_SUCCESS;
}

/* prompt user for input until valid input entered */
void get_input(int *withdraw)
{
  while (true)
  {
    printf("How much do you want to withdraw? ");
    if (scanf(" %d", withdraw) != 1)
    {
      printf("Invalid input\n");
      fflush(stdin);
      continue;
    }

    if (is_valid_input(*withdraw))
      break;
    fflush(stdin);
  }
}

bool is_valid_input(int amout_to_withdraw)
{
  if (amout_to_withdraw < 1)
  {
    printf("You have to withdraw more than 0\n");
    return false;
  }
  else if (amout_to_withdraw % 10 != 0)
  {
    printf("The amount you want to withdraw has to be divisible by 10\n");
    return false;
  }
  
  return true;  
}

void payout(int *payout_amount, int *hundreds, int *fifties, int *twenties, int *tens)
{
  *hundreds = *payout_amount / 100;
  *payout_amount -= *hundreds * 100;

  *fifties = *payout_amount / 50;
  *payout_amount -= *fifties * 50;

  *twenties = *payout_amount / 20;
  *payout_amount -= *twenties * 20;

  *tens = *payout_amount / 10;
  *payout_amount -= *tens * 10;
}
