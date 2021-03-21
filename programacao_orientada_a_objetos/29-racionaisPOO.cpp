// g++ 29-racionaisPOO.cpp -o racionaisPOO.exe

#include <iostream>

using namespace std;

class Racional
{
private:
  int num;
  int denom;

public:
  Racional(int, int);
  void negativo();
  void reduz();
  void soma(Racional);
  void subtrai(Racional);
  void multiplica(Racional);
  void divide(Racional);

  void inverte();
  void imprime();
};

Racional::Racional(int n, int d)
{
  this->num = n;
  this->denom = d;
}

void Racional::negativo()
{
  this->num = -this->num;
}

int mdc(int a, int b)
{
  if (b == 0)
    return a;

  return mdc(b, a % b);
}

int mmc(int a, int b)
{
  return (a * b) / mdc(a, b);
}

void Racional::reduz()
{
  int a, b, md;
  a = this->num;
  b = this->denom;

  if (a < 0)
    a = -a;

  if (b < 0)
    b = -b;

  md = mdc(a, b);
  this->num /= md;
  this->denom /= md;
}

void Racional::soma(Racional r)
{
  int a, b, c, d;
  a = r.num;
  b = r.denom;
  c = this->num;
  d = this->denom;

  this->num = a * d + c * b;
  this->denom = b * d;
}

void Racional::subtrai(Racional r)
{
  this->negativo();
  this->soma(r);
}

void Racional::multiplica(Racional r)
{
  int a, b, c, d;
  a = r.num;
  b = r.denom;
  c = this->num;
  d = this->denom;

  this->num = a * c;
  this->denom = b * d;
}

void Racional::inverte()
{
  int tmp = this->num;
  this->num = this->denom;
  this->denom = tmp;
}

void Racional::divide(Racional r)
{
  this->inverte();
  this->multiplica(r);
}

void Racional::imprime()
{
  cout << this->num << " " << this->denom << "\n";
}

int main()
{
  int a, b, c, d;
  char op;

  while (cin >> a >> b >> op >> c >> d)
  {
    Racional r1(a, b),
        r2(c, d);

    switch (op)
    {
    case '+':
      r2.soma(r1);
      break;
    case '-':
      r2.subtrai(r1);
      break;
    case '*':
      r2.multiplica(r1);
      break;
    case '/':
      r2.divide(r1);
      break;
    }

    r2.reduz();
    r2.imprime();
  }
  return 0;
}
