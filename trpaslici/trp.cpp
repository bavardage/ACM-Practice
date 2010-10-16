#include <vector>
#include <iostream>
#include <map>

using namespace std;

void here(int i) { cout << i << " doma" << endl; }
void missing(int i) { cout << i << " chyba" << endl; }
void dunno(int i) { cout << i << " nevedno" << endl; }

int how_many(int i) {
  int tot = 0;
  for(int j = 0; j < 7; j++) {
    if(i & (1 << j)) tot += 1;
  }
  return tot;
}

int main(void) {

  int weights[7]; int n; int tw;

  for(int i = 0; i < 7; i++) {
    cin >> weights[i];
  }
  cin >> n;
  cin >> tw;

  map<int,vector<int>* > wm;

  for(int i = 0; i<128; i++) {
    wm[i] = new vector<int>();
  };
  

  for(int i = 0; i < 128; i++) {
    int w = 0;
    for(int j = 0; j < 7; j++) {
      if(i & (1 << j)) { w += weights[j]; };
    }
    if(! wm[w]) {
      wm[w] = new vector<int>();
    }
    wm[w]->push_back(i);
  }

  if(!wm[tw]) {
    for(int i = 1; i <= 7; i++) {
      cout << "OMG THIS SHOULD TOTALLY NOT BE PRINTED LIKE" << endl;
    }
  } else {
    vector<int>* valid = new vector<int>();

    for(int j = 0; j < wm[tw]->size(); j++) {
      int result = wm[tw]->at(j);
      if(how_many(result) == n) { valid->push_back(result); }
    }


    for(int i = 1; i <= 7; i++) { //loop through dwarves
      bool always_here = true; bool always_absent = true;
      for(int j = 0; j < valid->size(); j++) {
	always_here = (valid->at(j) & (1 << (i-1))) && always_here;
	always_absent = !(valid->at(j) & (1 << (i-1))) && always_absent;
      }

      if(always_here) { 
	here(i);
      } else if(always_absent) {
	missing(i);
      } else {
	dunno(i);
      }
    }
  }
}
  
