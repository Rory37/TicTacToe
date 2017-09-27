#include <iostream>

using namespace std;
//TicTacToe
//9/25/17
//By Aidan Derocher
// Allows you to play a two player game of tictactoe
// Keeps track of x wins and o wins and has an option for if you want to play again
void printboard(char [][3]);
int checkwin(char [][3]);

int main() {
  bool turnx = true; //if it is x turn. If not, it is o turn
  int xwin = 0;// keeps track of scores
  int owin = 0; 
  char board [3][3]; //3 by 3 2d array for board
  char coor [2]; //Takes in input
  bool game = true;//if false game ends
  while (game == true) {
    turnx = true;//Resets to x turn
    cout << "Welcome to TicTacToe!" << endl <<
      "Please enter coordinates of the move as letter, than number. Ex: a1" << endl << "Type in quit if you wish to quit" << endl;
    cout << "X has: " << xwin << " wins" << endl;//prints wins
    cout << "O has: " << owin << " wins" << endl;
    //clears board (could have used nested for loops)
    board [0][0] = ' '; // First is down, then across
    board [0][1] = ' ';
    board [0][2] = ' ';
    board [1][0] = ' ';
    board [1][1] = ' ';
    board [1][2] = ' ';
    board [2][0] = ' ';
    board [2][1] = ' ';
    board [2][2] = ' ';
    bool playing = true;    
    while (playing == true) {//false when games restarts
      printboard(board); //shows board (see function below)
      if (turnx == true) {
	cout << "It is X's turn" << endl;
      }
      else {
	cout << "It is O's turn" << endl;
      }
      cin.getline(coor, 80); //gets coordinates, puts in an array letter than number
      if (strcmp(coor, "quit") == 0){ //if quit is typed
        game = false;// loops are all now false
        playing = false;
        break; //exit loop
      }
      int i = -1;
      int j = -1;
      if (coor [0] == 'a') {//checks whether a b or c. If not rejects the input
	i = 0;
      }
      else if (coor [0] == 'b') {
	i = 1;
      }
      else if (coor [0] == 'c') {
	i = 2;
      }
      else {
	cout << "Please input coordinates in the order of letter than number" << endl;
      }
      if (i != -1) {
	if (coor [1] == '1') { //checks if second is 1 2 or 3. If not rejects input
	  j = 0;
	}
	else if (coor [1] == '2') {
	  j = 1;
	}
	else if (coor [1] == '3') {
	  j = 2;
	}
	else {
	  cout << "Please input coordinates in the order of letter than number" << endl;
	}

	if (j != -1) { //if it is 1 2 or 3
	  
	  if (board [j][i] == ' ') { //if space is blank

	    if (turnx == true) {//set letter in space
	      board [j][i] = 'X';
	      turnx = false; //becomes O's turn
	    }
	    else {
	      board [j][i] = 'O'; //sets letter to O
	      turnx = true; //becomes X's turn
	    }
	    int won = checkwin(board); //runs function checkwin

	    if (won != 0) { //If the game is over
	      printboard(board);
	      if (won == 1) { //if x won
		xwin ++;//adds one to xwins
		cout << "X Wins!!!" << endl;
	      }
	      if (won == 2) { //if O won
		owin ++;//adds one to O wins
		cout << "O Wins!!!" << endl;
	      }
	      if (won == 4) { // if tie
		cout << "It's a Tie!!!" << endl;
	      }
	      bool replay = false; 
	      char a [80]; //char array for input yes or no
	      while (replay == false) { //while has not properly inputted
		cout << "Would you like to play again? Enter y or n" << endl;
		cin.getline(a, 80);
		if (a [0] == 'y' || a [0] == 'Y') { //if yes
		  replay = true;
		  playing = false;//resets game
		}
		else if (a [0] == 'n' || a [0] == 'N') {
		  replay = true;
		  game = false;//ends game
		  playing = false;
		}
	      }
	    }
	  } // ends if board is blank

	  else {
	    cout << "Please choose a blank space to place your piece" << endl;
	  }
	  
	}// ends if j is legal
	
      }// ends if i is legal
      
    } // ends while playing
    
  } // ends while game
  
} //ends main

void printboard(char bor [][3]) {
  //Prints out each row of text to make the board
  cout << "   a   b   c" << endl;
  cout << "1  "<< bor [0][0] << "   " << bor [0][1] << "   " << bor [0][2] << endl;
  cout << "2  "<< bor [1][0] << "   " << bor [1][1] << "   " << bor [1][2] << endl;
  cout << "3  "<< bor [2][0] << "   " << bor [2][1] << "   " << bor [2][2] << endl;
}

int checkwin(char bor [][3]) { //checks for horizontal wins
  int countx = 0; //keeps track of how many x in a row
  int counto = 0; //keeps track of how many o in a row
  for (int a = 0; a < 3; a++) {//Checks horizontal wins
    for (int b = 0; b < 3; b++) {

      if (bor[a][b] == 'X') {
	countx ++;
      }
      else if (bor[a][b] == 'O') {
	counto ++;
      }
    }
    if (countx == 3) { //if 3 x, than x won
      return 1;
    }
    if (counto == 3) { //if three o, o won
      return 2;
    }
    countx = 0; //resets counts
    counto = 0;
  }

  for (int a = 0; a < 3; a++) { //checks for vertical wins
    for (int b = 0; b < 3; b++) {

      if (bor[b][a] == 'X') {
	countx ++;
      }
      else if (bor[b][a] == 'O') {
	counto ++;
      }
    }
    if (countx == 3) { //if three x, x won
      return 1;
    }
    if (counto == 3) { //if three o, o won
      return 2;
    }
    countx = 0; //resets counts
    counto = 0;
  }

  for (int a = 0; a < 3; a++) { // diag left top
    if ( bor [a][a] == 'X') { //goes through a1, b2, and c3
      countx ++;
    }
    else if (bor [a][a] == 'O') {
      counto ++;
    }
  }
  
  if (countx == 3) {
    return 1;
  }
  if (counto == 3) {
    return 2;
  }
  countx = 0;//resets count
  counto = 0;

  for (int a = 0; a < 3; a++) { // diag right top
    if ( bor [a][2-a] == 'X') { //a3, b2, and c1
      countx ++;
    }
    else if (bor [a][2-a] == 'O') {
      counto ++;
    }
  }

  if (countx == 3) {
    return 1;
  }
  if (counto == 3) {
    return 2;
  }
  countx = 0;
  counto = 0;
  int count = 0; //new count to see how many empty spaces
  for ( int a = 0; a < 3; a ++) {
    for ( int b = 0; b < 3; b ++) {
      if (bor [a][b] == ' ') { //if blank
	count++;
      }
    }
  }
  if (count == 0) { // if no blanks
    return 4; //is a tie (4 is used because why not)
  }
  return 0;
}
