#include <iostream>
#include <cstdlib>
#include <cstring>

//Palindrome verifier by Aidan Derocher
// 9/19/17
// This is a program to see if inputed text (excluding spaces and punctuation) is a palindrome
// If it is a palindrome, it will print a message stating so, and if it is not it will express it
using namespace std;

int main() {
  cout << "Welcome to Palindrome verifier, where a line is verified either to be or to not be a Palindrome" << endl;
  while(true) {
    cout << "Please enter a line that you want to verify palindromism (if it is a palindrome)" << endl;
    char in [80]; //makes char array for initial in
    cin.getline(in, 80);//takes input into array
    for (int i = 0; i < strlen(in); i++){
      in[i] = tolower(in[i]);//sets all characters in array to lower case
    }
    int size = strlen(in) - 1; //get number of chars in string, - 1 since loop starts at 0
    char pali [80]; //char array for the reverse
    char spaceless [80]; //char array for input without punctuation
    int count = 0;//counts times there were non letter characters
    int scount = 0;
    for (int i = 0; i <= size; i++) { //for length of in
      if (!isspace(in[size-i]) && !ispunct(in[size-i])){ //If there is no space or punct at the next reverse char
	pali [i - count] = in [size - i]; // pali is the char fom the back of in
      }
      else{
	count++; //Adds count to make sure when there is non letter the space is not skipped
      }
      if (!isspace(in[i]) && !ispunct(in[i])){ //if it is a letter
	spaceless [i - scount] = in [i]; // then it is put in spaceless array
      }
      else {
	scount ++; //makes sure position isnt skipped
      }
    }
    pali [size - count + 1] = '\0'; //adds null chars
    spaceless [size - count + 1] = '\0';
    cout << "The input is: " << spaceless << endl;
    cout << "The reverse is: " << pali << endl;
    if (strcmp(pali,spaceless) == 0) { //If reverse of input and spaceless input are the same
      cout << "This is a palindrome" << endl;
    }
    else {
      cout << "This is not a palindrome" << endl;
    }
  }
}
