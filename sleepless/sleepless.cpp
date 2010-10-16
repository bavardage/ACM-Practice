#include <iostream>
#include <sstream>

using namespace std;


int sub_minutes(int b, int e) {
  int guess = e - b;

  guess = guess % 720; //not really neaded?
  while(guess < 0) { guess += 720; };
  return guess;
}

int hm2m(int h, int m) {
  return (h * 60) + m;
}

int m2hm(int m, int& ho, int& mo) {
  mo = m % 60;
  ho = (m - mo)/60;
}

string plural(int n) {
  if(n == 1)
    return "";
  else
    return "s";
}

string sleepy(int h, int m) {
  stringstream ss;
  if(h && m) {
    ss << h << " hour" << plural(h) << " and " << m << " minute" << plural(m);
  } else if(h) {
    ss << h << " hour" << plural(h);
  } else if(m){
    ss << m << " minute" << plural(m);
  } else {
    ss << "12 hours";
  }

  return ss.str();
}

int main(void) {

  char colon;
  int bh, bm, eh, em;

  cin >> bh >> colon >> bm >> eh >> colon >> em;

  int b = hm2m(bh,bm);
  int e = hm2m(eh,em);

  int mo, ho; m2hm(sub_minutes(b,e), ho, mo);

  string sl = sleepy(ho, mo);

  cout << "Misof slept for " << sl << "." << endl;
}
