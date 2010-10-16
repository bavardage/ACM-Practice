#include <iostream>

using namespace std;


const int M = 3;
const int N = 4;
double sys[M][N];
double results[N-1];

void putsys() {
  for(int i = 0; i < M; i++) {
    for(int j = 0; j < N; j++) {
      cout << sys[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void scale(int row, double factor) {
  cout << "scaling " << row << " by " << factor << endl;
  for(int i = 0; i < N; i++)
    sys[row][i] *= factor;
}

void add_rows(int row, int target, float factor) {
  cout << "adding " << factor << "* " << row << " to " << target << endl;
  for(int i = 0; i < N; i++)
    sys[target][i] += factor * sys[row][i];
}
void add_rows(int row, int target) { add_rows(row, target, 1); };


void swap_rows(int i, int j) {
  cout << "swapping " << i << " " << j << endl;
  swap(sys[i], sys[j]);
}

int find_non_zero(int column, int from) {
  for(int i = from; i < M; i++) {
    if(sys[i][column] != 0) {
      return i;
    }
  }
  return -1;
}

int main(void) {
  sys = {{1,1,-1,4},{1,-2,3,-6},{2,3,1,7}};



  for(int i = 0; i < M; i++) {
    int n_z = find_non_zero(i,i);
    if(n_z != -1) { //we're good to go!
      swap_rows(i, n_z);
      scale(i, 1/sys[i][i]);
      
      for(int j = i+1; j < M; j++) {
	if(sys[j][i] != 0)
	  add_rows(i, j, -sys[j][i]/sys[i][i]);
      }
    }
  }
  
  cout << "OMG ECHELON" << endl;
  putsys();
  //omg we're now in echelon form!!! MAJOR EXCITEMENT

  
  //where to start going up?!
  int bottom;
  for(int i = 0; i < M; i++) {
    if(sys[i][N-2] != 0)
      bottom = i;
  }

  cout << "we gotta bottom of " << bottom << endl;

  for(int i = bottom; i >= 0; i--) {
    cout << "doing row " << i << endl;
    results[i] = sys[i][N-1];

    for(int j = i+1; j < N-1; j++) {
      results[i] -= sys[i][j] * results[j];
    }

  }

  cout << "RESULTS.. OH DEAR\n" << endl;
  for(int i= 0; i < N-1; i++) { cout << i << ": " << results[i] << endl; };
}
