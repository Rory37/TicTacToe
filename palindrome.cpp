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
      
    }
    int size = strlen(in) - 1;
    char pali [80];
    for (int i = 0; i <= size; i++) {
      if (!(isspace(in[size-1]))){
	pali [i] = in [size - i];
	cout << pali [i];
      }
    }
    
  }

}
