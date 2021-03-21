// g++ 52-vetorSeguro.cpp -o vetorSeguro.exe

#include <iostream>

using namespace std;

class IndiceInvalidoException : public runtime_error
{
public:
  IndiceInvalidoException() : runtime_error("runtime error: indice fora dos limites do vetor.")
  {
  }
};

void imprime(int *v, int n, int i)
{
  if (i < 0 || i >= n)
  {
    throw IndiceInvalidoException();
  }
  cout << v[i] << endl;
}

int main()
{
  int n, *v, i;
  cin >> n;
  v = new int[n];

  for (i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  while (cin >> i)
  {
    try
    {
      imprime(v, n, i);
    }
    catch (IndiceInvalidoException e)
    {
      cout << e.what() << endl;
    }
  }

  delete[] v;
  return 0;
}
