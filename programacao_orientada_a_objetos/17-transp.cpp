// g++ 17-transp.cpp -o transp.exe

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int row, column;
  int **matrix = new int *[row];
  int **transpose = new int *[column];

  cin >> row >> column;

  for (int i = 0; i < row; ++i)
    matrix[i] = new int[column];

  for (int i = 0; i < column; ++i)
    transpose[i] = new int[row];

  for (int i = 0; i < row; ++i)
    for (int j = 0; j < column; ++j)
      cin >> matrix[i][j];

  for (int i = 0; i < row; ++i)
    for (int j = 0; j < column; ++j)
      transpose[j][i] = matrix[i][j];

  for (int i = 0; i < column; ++i)
  {
    for (int j = 0; j < row; ++j)
      cout << transpose[i][j] << " ";
    cout << endl;
  }

  for (int i = 0; i < row; ++i)
    delete[] matrix[i];

  for (int i = 0; i < column; ++i)
    delete[] transpose[i];

  delete[] matrix;
  delete[] transpose;

  return 0;
}
