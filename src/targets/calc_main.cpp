
//------------------------------------------------------------------------
// Main
//------------------------------------------------------------------------
// Valid inputs: Basic math (+, -, *, /), Constructing matrices
// Formatting: no spacing between digits (ex: "12" can't be typed as "1 2")
// Will print nothing if input is bad

#include <iostream>
#include <string>
#include "CalcInput.h"
using namespace std;

bool check_msg(string input) {
  // Returns true if user input is valid, false otherwise
  // Valid inputs require spaces (ex: 5 + 5 vs 5+5)

  // non-serial
  string::size_type input_s = input.find(" ");
  return input_s < input.length();


  // serial


}


// print_msg() function

void print_msg(string output) {
  // Prints out the output for both platforms

  // non-serial
  cout << "> " << output << "\n";

  // serial

}


int main() {
  // Main loop

  while (true) {
    cout << "> "; // Enter calculation
    string input;
    getline(cin, input);
    if (check_msg(input)) {
      string output = calculateInput(input);
      print_msg(output);
    }
  }
  return 0;
}