#include <iostream>
#include <string>

using namespace std;

void lr(string text, string sub, long long pos, long long& l, long long& r) {

  long long left;
  long long right;

  //we claim sub is always of length at least one!! OOPS ?!?! actually it loosely is ok
    
  
  left = text.find_first_of(sub[0], pos);
  if(left == string::npos) {
    l = -1; r = -1; return;
  }

  //now we have a left, find teh right!

  right = left;
  for(long long i = 1; i < sub.length(); i++) {
    right = text.find_first_of(sub[i], right+1);
    if(right == string::npos) {
      l = -1; r = -1; return;
    }
  }

  l = left; r = right; return;
}


int main(void) {
  string t; string m;


  cin >> t; cin >> m;


  if(t.length() == m.length()) {
    cout << "1" << endl;
    return 0;
  }


  long long l; long long r;
  long long total = 0;


  lr(t,m,0,l,r);
  
  while(l != -1) {
    total += ((l+1)*(t.length() - r) - 1);
    lr(t,m,l+1,l,r);
  }
  
  cout << total << endl;

}
