#include <iostream>
#include <cstdlib>
using namespace std;

int  main()
{
  bool game = true;
  while (game == true){
    cout << "Welcome to RNG, also known as the Random Number Guesser. As the name implies," << endl << " a random number will be determined between 0 and one hundred, inclusive, and" << endl << " you have to guess it." << endl;
    srand(time(NULL));
    int input_var = 0;
    int random =rand()%101;
    int guess;
    bool tf = false;
    int attempts = 0;
    char yn;
    while(tf == false){
      do {
	cout << "Please type in a guess for the number between 0 and 100." << endl;
	cin >> guess;
	if(!(guess >> input_var)){
	  cout <<"Please only enter integers between 0 and 100" << endl;
	  cin.clear();
	  cin.ignore(10000,'\n');
	}
      }
      while (!(0 <= guess && guess <= 100));
      attempts++;
      if (guess == random){
	cout << "You were correct!! Yay!!!" << endl;
	cout << "It took " << attempts << " attempts" << endl;
	cout << "Do you want to play again" << endl;
	cin >> yn;
	  if (yn == 'y') {
	  game = true;
	}
	else {
	  game = false;
	}
	tf = true;
      }
      else {
	cout << "You were incorrect...";
      }
    }
  }
}
