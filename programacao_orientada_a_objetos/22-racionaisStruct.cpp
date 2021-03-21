// g++ 22-racionaisStruct.cpp -o racionaisStruct.exe

#include <iostream>

using namespace std;

typedef struct tRacional
{
  int num, denom;
} Racional;

Racional racional(int num, int denom)
{
  Racional novo;
  novo.num = num;
  novo.denom = denom;
  return novo;
}

Racional negativo(Racional n1)
{
  return racional(-n1.num, n1.denom);
}

Racional soma(Racional n1, Racional n2)
{
  int denom = n1.denom * n2.denom;
  int num = denom / n1.denom * n1.num + denom / n2.denom * n2.num;
  return racional(num, denom);
}

Racional mult(Racional n1, Racional n2)
{
  return racional(n1.num * n2.num, n1.denom * n2.denom);
}

Racional div(Racional n1, Racional n2)
{
  return racional(n1.num * n2.denom, n1.denom * n2.num);
}

int mdc(int num, int denom)
{
  while (denom != 0)
  {
    int y = denom;
    denom = num % denom;
    num = y;
  }
  return num;
}

Racional reduz(Racional n)
{
  int denom = n.denom;
  int num = n.num;
  int mdc;

  if (num < 0)
    num = -num;
  if (denom < 0)
    denom = -denom;

  while (denom != 0)
  {
    mdc = denom;
    denom = num % denom;
    num = mdc;
  }

  return racional(n.num / num, n.denom / num);
}

void imprime(Racional n)
{
  cout << n.num << " " << n.denom << "\n";
}

int main()
{
  int a, b, c, d;
  char op;

  while (cin >> a >> b >> op >> c >> d)
  {
    Racional r1 = racional(a, b), r2 = racional(c, d), r3;

    switch (op)
    {
    case '+':
      r3 = soma(r1, r2);
      break;
    case '-':
      r3 = soma(r1, negativo(r2));
      break;
    case '*':
      r3 = mult(r1, r2);
      break;
    case '/':
      r3 = div(r1, r2);
      break;
    }

    imprime(reduz(r3));
  }

  return 0;
}
