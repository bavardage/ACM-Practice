#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main(void) {
  
  string digits;
  cin >> digits;

  bool yay[1000000];
  yay[0] = true;

  int l = digits.length();
  for(int i = 0; i < l; i++) {
    for(int j = 1; j <= 6; j++) {
      int found = atoi(digits.substr(i,j).c_str());
      
      yay[found] = true;
    }
  }

  for(int i = 0; i < 1000000; i++) {
    if(!yay[i]) {
      cout << i << endl;
      break;
    }
  }
};
