// g++ 23-bissextoStruct.cpp -o bissextoStruct.exe

#include <iostream>

using namespace std;

int main()
{
  int ano;

  cin >> ano;

  if (ano % 400 == 0 || (ano % 100 != 0 && ano % 4 == 0))
    cout << "ANO BISSEXTO";
  else
    cout << "ANO NAO BISSEXTO";

  return 0;
}
