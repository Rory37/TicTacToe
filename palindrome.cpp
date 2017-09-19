#include <iostream>
#include <cstdlib>
#include <cstring>


using namespace std;

int main() {
  cout << "Welcome to Palindrome verifier, where a line is verified either to be or to not be a Palindrome" << endl;
  while(true) {
    cout << "Please enter a line that you want to verify palindromism (if it is a palindrome)" << endl;
    char in [80];
    cin.getline(in, 80);
    for (int i = 0; i < strlen(in); i++){
      in[i] = tolower(in[i]);
    }
    int size = strlen(in) - 1;
    char pali [80];
    char spaceless [80];
    int count = 0;
    int scount = 0;
    for (int i = 0; i <= size; i++) {
      if (!isspace(in[size-i]) && !ispunct(in[size-i])){
	pali [i - count] = in [size - i];
      }
      else{
	count++;
      }
      if (!isspace(in[i]) && !ispunct(in[i])){
	spaceless [i - scount] = in [i];
      }
      else {
	scount ++;
      }
    }
    pali [size - count + 1] = '\0';
    spaceless [size - count + 1] = '\0';
    cout << (size - count + 1) << endl;
    cout << pali << endl;
    cout << spaceless << endl;
    if (strcmp(pali,spaceless) == 0) {
      cout << "This is a palindrome" << endl;
    }
    else {
      cout << "This is not a palindrome" << endl;
    }
  }
}
