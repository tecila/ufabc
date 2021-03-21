// g++ 17-diag.cpp -o diag.exe

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int size;
  float counter = 0, x = 0;
  string operation;
  int **matrix = new int *[size];

  cin >> operation;
  cin >> size;

  for (int i = 0; i < size; ++i)
  {
    matrix[i] = new int[size];
  }

  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      cin >> matrix[i][j];

  for (int i = 0; i < size; ++i)
    for (int j = 0; j < size; ++j)
      if (j < i)
      {
        counter += matrix[i][j];
        x += 1;
      }

  if (operation == "S")
  {
    cout << setprecision(2) << counter << endl;
  }

  else
  {
    cout << setprecision(2) << counter / x << endl;
  }

  for (int i = 0; i < 2; ++i)
  {
    delete[] matrix[i];
  }

  delete[] matrix;

  return 0;
}
