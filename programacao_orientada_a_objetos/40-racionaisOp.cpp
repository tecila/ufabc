// g++ 40-racionaisOp.cpp -o racionaisOp.exe

#include <iostream>

using namespace std;

class Racional
{
private:
  int num;
  int denom;

public:
  Racional();
  Racional(int, int);
  void setNum(int);
  void setDenom(int);
  int getNum();
  int getDenom();
  void negativo();
  void reduz();
  void inverte();
  void imprime();

  Racional operator+(Racional);
  Racional operator-(Racional);
  Racional operator*(Racional);
  Racional operator/(Racional);
};

Racional::Racional()
{
  this->setNum(1);
  this->setDenom(1);
}

Racional::Racional(int n, int d)
{
  this->setNum(n);
  this->setDenom(d);
}

void Racional::setNum(int n)
{
  this->num = n;
}

void Racional::setDenom(int d)
{
  this->denom = d;
}

int Racional::getNum()
{
  return this->num;
}

int Racional::getDenom()
{
  return this->denom;
}

void Racional::negativo()
{
  this->setNum(-this->getNum());
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
  a = this->getNum();
  b = this->getDenom();

  if (a < 0)
    a = -a;

  if (b < 0)
    b = -b;

  md = mdc(a, b);
  this->num /= md;
  this->denom /= md;
}

Racional Racional::operator+(Racional r)
{
  int a, b, c, d;
  a = r.num;
  b = r.denom;
  c = this->getNum();
  d = this->getDenom();

  this->setNum(a * d + c * b);
  this->setDenom(b * d);
}

Racional Racional::operator-(Racional r)
{
  this->negativo();
  this->operator+(r);
}

Racional Racional::operator*(Racional r)
{
  int a, b, c, d;
  a = r.num;
  b = r.denom;
  c = this->getNum();
  d = this->getDenom();

  this->setNum(a * c);
  this->setDenom(b * d);
}

Racional Racional::operator/(Racional r)
{
  this->inverte();
  this->operator*(r);
}

void Racional::inverte()
{
  int tmp = this->getNum();
  this->setNum(this->getDenom());
  this->setDenom(tmp);
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
      r2.operator+(r1);
      break;
    case '-':
      r2.operator-(r1);
      break;
    case '*':
      r2.operator*(r1);
      break;
    case '/':
      r2.operator/(r1);
      break;
    }

    r2.reduz();
    r2.imprime();
  }
  return 0;
}
