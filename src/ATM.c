/*
 * Programmer: Henrik A. Christensen     Date Completed: in progress
 * Instructor: Kurt Nørmark              Class:          Imperative Programming
 *
 * American ATM
 * available banknotes | $100, $50, $20 and $10
 * 
 * User enters how much he/she wants to withdraw
 * and the ATM should return the fewest number of banknotes
 * 
 * examples:
 * 
 * 180 should return 1x $100, 1x $50, 1x $20 and 1x $10
 *  10 should return 0x $100, 0x $50, 0x $20 and 1x $10
 * 570 should return 5x $100, 1x $50, 1x $20 and 0x $10
*/

#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

bool is_valid_input(int amout_to_withdraw);
void payout(int *payout_amount, int *hundreds, int *fifties, int *twenties, int *tens);

int main(void)
{
  int withdraw = 0;
  int hundred_notes = 0;
  int fifty_notes = 0;
  int twenty_notes = 0;
  int ten_notes = 0;

  /* prompt user for input */
  while (true)
  {
    printf("How much do you want to withdraw? ");
    if (scanf(" %d", &withdraw) != 1)
    {
      printf("Invalid input\n");
      fflush(stdin);
      continue;
    }

    if (is_valid_input(withdraw))
      break;
    fflush(stdin);
  }

  payout(&withdraw, &hundred_notes, &fifty_notes, &twenty_notes, &ten_notes);

  printf("\n-------");
  printf("\n%d hundreds", hundred_notes);
  printf("\n%d fifties", fifty_notes);
  printf("\n%d twenties", twenty_notes);
  printf("\n%d tens", ten_notes);

  return EXIT_SUCCESS;
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
  int remaind_amount = *payout_amount;

  *hundreds = remaind_amount / 100;
  remaind_amount -= *hundreds * 100;

  *fifties = remaind_amount / 50;
  remaind_amount -= *fifties * 50;

  *twenties = remaind_amount / 20;
  remaind_amount -= *twenties * 20;

  *tens = remaind_amount / 10;
  remaind_amount -= *tens * 10;
}
