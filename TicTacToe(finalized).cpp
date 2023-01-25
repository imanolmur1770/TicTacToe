/*
Imanol Murillo
EGR126
TicTacToe Project
*/
#include <cmath>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;
// declare functions and variables

int user = 0;
int computer = 0;
void display(int[]);
bool gameover(int[]);
void computerAI(int[]);

// calling functions

int main() {
  int nums[9];
  int i = 0;
  int loc = 0;
  int ch = 0;
  string str = "";
  int opt = 0;
  cout << "Welcome to the Tick tac Toe Game.\n";
  do {
    cout << "-------------------------------------------------\n";
    cout << "User has " << user << " and the computer has " << computer << " .";
    cout << "\n-------------------------------------------------";
    cout << "\n\t1 Play Game."; // Play game option
    cout << "\n\t2 Exit.";      // Exit option
    cout << endl;
    do {
      // menu
      cout << "Enter a select code: "; // Menu option select
      cin >> opt;
      if (opt == 1 || opt == 2) {
        break;
      } else
        cout << "Invalid entry. Please try again.\n";
    } while (true);
    switch (opt) {
    case 1:
      cout << "Entering Game\n"; // Game
      srand(time(NULL));
      for (i = 0; i < 9; i++)
        nums[i] = -1;
      // code.  -1 = Space available, 1 = X, 0 = O.

      // function to display the game
      system("clear");
      cout << "-------------------------------------------------\n";
      display(nums);
      cout << "-------------------------------------------------\n";
      while (true) {
        do {
          cout << "please enter an X in an avaiable spot: ";
          cin >> loc;
          // test if its taken
          if (nums[loc - 1] == -1) {
            nums[loc - 1] = 1;
            break;
          } else
            cout << "Location is not available \n";
        } while (true);
        // enter the x, the it sees if spot is avaivle or not.
        if (gameover(nums)) {
          cout << " Game is Over.\n";
          break;
        }
        // checks if someone has won yet
        computerAI(nums);
        // computer AI,
        cout << "-------------------------------------------------\n";
        display(nums);
        cout << "-------------------------------------------------\n";
        // display updated computer move
        if (gameover(nums)) {
          cout << "Game is Over.\n";
          break;
        }
        // checks if game is over, if not repeats loop
      }
      break;
    case 2:
      break; // exit
    default:
      cout << "Inavlid entry\n";
    }
  } while (opt != 2);
  cout << "Thank you for playing Tick Tac Toe\n"; // exit message
  system("pause");
  return 0;
}

// functions
void display(int n[]) {
  // displays the board and the X and O postitions
  int r, c;
  int count = 0;

  for (r = 0; r < 3; r++) {
    for (c = 0; c < 3; c++) {
      if (n[count] == -1)
        cout << setw(10) << count + 1; // available space
      else if (n[count] == 1)
        cout << setw(10) << "X"; // X taken to space
      else if (n[count] == 0)
        cout << setw(10) << "O"; // O taken the space
      count++;
    }
    cout << endl;
  }
  return;
}

// displays table

bool gameover(int n[]) {
  // goes to Game over if one of the possiblites is true
  // If X is the winner
  const int check = -1;
  if (n[0] == 1 && n[1] == 1 && n[2] == 1) {
    cout << "X is the winner!";
    user++;
    return true;
  } else if (n[3] == 1 && n[4] == 1 && n[5] == 1) {
    cout << "X is the winner!";
    user++;
    return true;
  } else if (n[6] == 1 && n[7] == 1 && n[8] == 1) {
    cout << "X is the winner!";
    user++;
    return true;
  } else if (n[0] == 1 && n[3] == 1 && n[6] == 1) {
    cout << "X is the winner!";
    user++;
    return true;
  } else if (n[1] == 1 && n[4] == 1 && n[7] == 1) {
    cout << "X is the winner!";
    user++;
    return true;
  } else if (n[2] == 1 && n[5] == 1 && n[8] == 1) {
    cout << "X is the winner!";
    user++;
    return true;
  } else if (n[0] == 1 && n[4] == 1 && n[8] == 1) {
    cout << "X is the winner!";
    user++;
    return true;
  } else if (n[2] == 1 && n[4] == 1 && n[6] == 1) {
    cout << "X is the winner!";
    user++;
    return true;
  }
  // If O is the winner
  else if (n[0] == 0 && n[1] == 0 && n[2] == 0) {
    cout << "O is the winner!";
    computer++;
    return true;
  } else if (n[3] == 0 && n[4] == 0 && n[5] == 0) {
    cout << "O is the winner!";
    computer++;
    return true;
  } else if (n[6] == 0 && n[7] == 0 && n[8] == 0) {
    cout << "O is the winner!";
    computer++;
    return true;
  } else if (n[0] == 0 && n[3] == 0 && n[6] == 0) {
    cout << "O is the winner!";
    computer++;
    return true;
  } else if (n[1] == 0 && n[4] == 0 && n[7] == 0) {
    cout << "O is the winner!";
    computer++;
    return true;
  } else if (n[2] == 0 && n[5] == 0 && n[8] == 0) {
    cout << "O is the winner!";
    computer++;
    return true;
  } else if (n[0] == 0 && n[4] == 0 && n[8] == 0) {
    cout << "O is the winner!";
    computer++;
    return true;
  } else if (n[2] == 0 && n[4] == 0 && n[6] == 0) {
    cout << "O is the winner!";
    computer++;
    return true;
  }
  // If all the spaces are occupied
  else if (n[0] > check && n[1] > check && n[2] > check && n[3] > check &&
           n[4] > check && n[5] > check && n[6] > check && n[7] > check &&
           n[8] > check) {
    cout << "All spaces are occupied, game is tied";
    return true;
  }
  // return false which does not end the game and continues the looop
  else
    return false;
}

// gameover function

void computerAI(int n[]) {
  // First rule, AI will try to get three in a row to win
  // Second rule, AI will try to block X's moves
  // Third, it will just random generate
  int c;

  // Rule 1: To win
  if (n[0] == -1 && n[1] == 0 && n[2] == 0)
    n[0] = 0;
  else if (n[0] == -1 && n[3] == 0 && n[6] == 0)
    n[0] = 0;
  else if (n[0] == -1 && n[4] == 0 && n[8] == 0)
    n[0] = 0;
  // 0 to win
  else if (n[1] == -1 && n[0] == 0 && n[2] == 0)
    n[1] = 0;
  else if (n[1] == -1 && n[4] == 0 && n[7] == 0)
    n[1] = 0;
  // 1 to win
  else if (n[2] == -1 && n[0] == 0 && n[1] == 0)
    n[2] = 0;
  else if (n[2] == -1 && n[5] == 0 && n[8] == 0)
    n[2] = 0;
  else if (n[2] == -1 && n[4] == 0 && n[6] == 0)
    n[2] = 0;
  // 2 to win
  else if (n[3] == -1 && n[0] == 0 && n[6] == 0)
    n[3] = 0;
  else if (n[3] == -1 && n[4] == 0 && n[5] == 0)
    n[3] = 0;
  // 3 to win
  else if (n[4] == -1 && n[1] == 0 && n[7] == 0)
    n[4] = 0;
  else if (n[4] == -1 && n[3] == 0 && n[5] == 0)
    n[4] = 0;
  else if (n[4] == -1 && n[2] == 0 && n[6] == 0)
    n[4] = 0;
  else if (n[4] == -1 && n[0] == 0 && n[8] == 0)
    n[4] = 0;
  // 4 to win
  else if (n[5] == -1 && n[2] == 0 && n[8] == 0)
    n[5] = 0;
  else if (n[5] == -1 && n[4] == 0 && n[3] == 0)
    n[5] = 0;
  // 5 to win
  else if (n[6] == -1 && n[4] == 0 && n[2] == 0)
    n[6] = 0;
  else if (n[6] == -1 && n[3] == 0 && n[0] == 0)
    n[6] = 0;
  else if (n[6] == -1 && n[7] == 0 && n[8] == 0)
    n[6] = 0;
  // 6 to win
  else if (n[7] == -1 && n[4] == 0 && n[1] == 0)
    n[7] = 0;
  else if (n[7] == -1 && n[6] == 0 && n[8] == 0)
    n[7] = 0;
  // 7 to win
  else if (n[8] == -1 && n[2] == 0 && n[5] == 0)
    n[8] = 0;
  else if (n[8] == -1 && n[0] == 0 && n[4] == 0)
    n[8] = 0;
  else if (n[8] == -1 && n[6] == 0 && n[7] == 0)
    n[8] = 0;
  // 8 to win

  // Rule 2: To block
  else if (n[0] == -1 && n[1] == 1 && n[2] == 1)
    n[0] = 0;
  else if (n[0] == -1 && n[3] == 1 && n[6] == 1)
    n[0] = 0;
  else if (n[0] == -1 && n[4] == 1 && n[8] == 1)
    n[0] = 0;
  // 0 to block
  else if (n[1] == -1 && n[0] == 1 && n[2] == 1)
    n[1] = 0;
  else if (n[1] == -1 && n[4] == 1 && n[7] == 1)
    n[1] = 0;
  // 1 to block
  else if (n[2] == -1 && n[0] == 1 && n[1] == 1)
    n[2] = 0;
  else if (n[2] == -1 && n[5] == 1 && n[8] == 1)
    n[2] = 0;
  else if (n[2] == -1 && n[4] == 1 && n[6] == 1)
    n[2] = 0;
  // 2 to block
  else if (n[3] == -1 && n[0] == 1 && n[6] == 1)
    n[3] = 0;
  else if (n[3] == -1 && n[4] == 1 && n[5] == 1)
    n[3] = 0;
  // 3 to block
  else if (n[4] == -1 && n[1] == 1 && n[7] == 1)
    n[4] = 0;
  else if (n[4] == -1 && n[3] == 1 && n[5] == 1)
    n[4] = 0;
  else if (n[4] == -1 && n[2] == 1 && n[6] == 1)
    n[4] = 0;
  else if (n[4] == -1 && n[0] == 1 && n[8] == 1)
    n[4] = 0;
  // 4 to block
  else if (n[5] == -1 && n[2] == 1 && n[8] == 1)
    n[5] = 0;
  else if (n[5] == -1 && n[4] == 1 && n[3] == 1)
    n[5] = 0;
  // 5 to block
  else if (n[6] == -1 && n[4] == 1 && n[2] == 1)
    n[6] = 0;
  else if (n[6] == -1 && n[3] == 1 && n[0] == 1)
    n[6] = 0;
  else if (n[6] == -1 && n[7] == 1 && n[8] == 1)
    n[6] = 0;
  // 6 to block
  else if (n[7] == -1 && n[4] == 1 && n[1] == 1)
    n[7] = 0;
  else if (n[7] == -1 && n[6] == 1 && n[8] == 1)
    n[7] = 0;
  // 7 to block
  else if (n[8] == -1 && n[2] == 1 && n[5] == 1)
    n[8] = 0;
  else if (n[8] == -1 && n[0] == 1 && n[4] == 1)
    n[8] = 0;
  else if (n[8] == -1 && n[6] == 1 && n[7] == 1)
    n[8] = 0;
  // 8 to block

  // Rule3: to random
  else {
    do {

      c = rand() % 9;
      if (n[c] == -1) {
        n[c] = 0;
        break;
      }
    } while (true);
  }
  return;
}

// computer AI
