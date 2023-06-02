#include <vector>
#include <iostream>
using namespace std;

bool isConsecutiveFour(const vector<vector<int> >& values) {

  bool hasConsecFours = false;
  // Tests rows //
  for (int row = 0; row < values.size(); row++) {
    for (int i = 0; i < values[row].size(); i++) {
      int count = 1;
      for (int j = i + 1; j < values[row].size(); j++) {
        if (values[row][j] == values[row][i]) {
          count++;
        } else {
          break;
        }
        if (count >= 4) return true;
      }
    }
  }

  // Tests columns //
  for (int column = 0; column < values[0].size(); column++) {
    int count = 1;
    for (int x = 1; x < values.size(); x++){
      if (values[x][column] == values[x - 1][column]) {
        count++;
      } else {
        break;
      }
      if (count >= 4) return true;
    }
  }

  // Tests diagonally //
  for (int x = 1; x < values.size(); x++) {
    int static count = 1;
    cout << values[x][x] << endl;
    if (values[x][x] == values[x - 1][x - 1]) {
      count++;
    } else {
      break;
    }
    cout << count << endl;
    if (count >= 4) return true;

  }

  return false;
}

int main() {

  int rowSize, columnSize;
  cout << "Enter row size: "; cin >> rowSize;
  cout << "Enter column size: "; cin >> columnSize;

  vector<vector<int> > matrix(rowSize);
  for (int i = 0; i < rowSize; i++)
    matrix[i] = vector<int>(columnSize);
  
  for (int i = 0; i < rowSize; i++) { 
    for (int j = 0; j < columnSize; j++)
      cin >> matrix[i][j];
  }
  
  isConsecutiveFour(matrix) == true ? (cout << "The array has consecutive fours" << endl) : (cout << "The array does not have consecutive fours" << endl);
  
}