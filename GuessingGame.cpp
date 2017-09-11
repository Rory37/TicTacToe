#include <iostream>
#include <cstdlib>
using namespace std;

int  main()
{
  bool game = true;
  while (game == true){ //Loop to restart game
    cout << "Welcome to RNG, also known as the Random Number Guesser. As the name implies," << endl << " a random number will be determined between 0 and one hundred, inclusive, and" << endl << " you have to guess it." << endl;
    srand(time(NULL));//Sets random seed based on time
    int input_var = 0; //Type int
    int random =rand()%101;//Sets random number between 0 and 100
    int guess; //records the guess
    bool tf = false; //Sees if more guessing needed
    int attempts = 0; //number of attempts
    char yn; //Char y or n for yes no
    while(tf == false){//While guess wasn't correct
      do {
	cout << "Please type in a guess for the number between 0 and 100." << endl;
	cin >> guess;//takes in guess
	if(!(guess >> input_var)){//if not int
	  cout <<"Please only enter integers between 0 and 100" << endl;
	  cin.clear(); //clears the log
	  cin.ignore(10000,'\n'); //ignores the cin
	}
      }
      while (!(0 <= guess && guess <= 100)); //continues until its between 1 and 100
      attempts++;// adds to attempts
      if (guess == random){//You won
	cout << "You were correct!! Yay!!!" << endl;
	cout << "It took " << attempts << " attempts" << endl;
	cout << "Do you want to play again" << endl;
	cin >> yn;
	if (yn == 'y') { //Checks if you want to play again
	  game = true;
	}
	else {
	  game = false;
	}
	tf = true;//Done guessing
      }
      else {
	cout << "You were incorrect...";
	if(guess > random){ //Determines if too high
	  cout <<"Your guess was too high" << endl;
	}
	else{ //otherwise too low
	  cout << "Your guess was too low" << endl;
	}
      }
    }
  }
}
