// g++ 16-somaMat.cpp -o somaMat.exe

#include <iostream>

using namespace std;

int main()
{
  int size;
  int **matrix = new int *[size];
  int **matrix2 = new int *[size];
  int **sum = new int *[size];

  cin >> size;

  for (int i = 0; i < size; ++i)
  {
    matrix[i] = new int[size];
    matrix2[i] = new int[size];
    sum[i] = new int[size];
  }

  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      cin >> matrix[i][j];

  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      cin >> matrix2[i][j];

  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      sum[i][j] = matrix[i][j] + matrix2[i][j];

  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
      cout << sum[i][j] << " ";
    cout << endl;
  }

  for (int i = 0; i < size; ++i)
  {
    delete[] matrix[i];
    delete[] matrix2[i];
    delete[] sum[i];
  }

  delete[] matrix;
  delete[] matrix2;
  delete[] sum;

  return 0;
}
