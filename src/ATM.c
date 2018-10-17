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

#ifdef _WIN32
  #define CLEAR "cls"
#else
  #define CLEAR "clear"
#endif

typedef enum { false, true } bool;

bool is_valid_input(int amout_to_withdraw);
void payout(int *payout_amount, int *hundreds, int *fifties, int *twenties, int *tens);
void calculate_notes(int *remaind_amount, int *note_type, int note_value);

int main(void)
{
  int withdraw = 0, hundred_notes = 0, fifty_notes = 0,
      twenty_notes = 0, ten_notes = 0;

  /* clear console */
  system(CLEAR);

  /* prompt user for input until valid input is entered */
  while (true)
  {
    printf("How much do you want to withdraw? ");
    if (scanf(" %d", &withdraw) != 1) /* if user enters a char or string */
    {
      printf("Invalid input\n");
      fflush(stdin); /* flush output buffer */
      continue;
    }

    if (is_valid_input(withdraw)) /* end loop if input is okay */
      break;
    fflush(stdin);
  }

  /* calculate what $-notes to pay out */
  payout(&withdraw, &hundred_notes, &fifty_notes, &twenty_notes, &ten_notes);

  /* final output */
  printf("\n-------");
  printf("\n%d hundreds", hundred_notes);
  printf("\n%d fifties", fifty_notes);
  printf("\n%d twenties", twenty_notes);
  printf("\n%d tens", ten_notes);

  return EXIT_SUCCESS;
}

/* function to check if entered input is valid */
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
  calculate_notes(payout_amount, hundreds, 100);
  calculate_notes(payout_amount, fifties, 50);
  calculate_notes(payout_amount, twenties, 20);
  calculate_notes(payout_amount, tens, 10);
}

void calculate_notes(int *remaind_amount, int *note_type, int note_value)
{
  *note_type = *remaind_amount / note_value;
  *remaind_amount -= *note_type * note_value;
}
