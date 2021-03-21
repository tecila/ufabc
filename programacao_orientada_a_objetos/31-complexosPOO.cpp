// g++ 31-complexosPOO.cpp -o complexosPOO.exe

#include <iostream>

using namespace std;

class Complexo
{
private:
  int re;
  int im;

public:
  Complexo(int, int);
  void soma(Complexo);
  void subtrai(Complexo);
  void multiplica(Complexo);
  void divide(Complexo);
  void negativo();
  void imprime();
};

Complexo::Complexo(int a, int b)
{
  this->re = a;
  this->im = b;
}

void Complexo::negativo()
{
  this->re = -this->re;
  this->im = -this->im;
}

void Complexo::soma(Complexo z)
{
  int a, b, c, d;
  a = z.re;
  b = z.im;
  c = this->re;
  d = this->im;

  this->re = a + c,
  this->im = b + d;
}

void Complexo::subtrai(Complexo z)
{
  this->negativo();
  this->soma(z);
}

void Complexo::multiplica(Complexo z)
{
  int a, b, c, d;
  a = z.re;
  b = z.im;
  c = this->re;
  d = this->im;

  this->re = a * c - b * d;
  this->im = a * d + b * c;
}

void Complexo::divide(Complexo z)
{
  int a, b, c, d;
  a = z.re;
  b = z.im;
  c = this->re;
  d = this->im;

  this->re = (a * c + b * d) / (c * c + d * d);
  this->im = (b * c - a * d) / (c * c + d * d);
}

void Complexo::imprime()
{
  cout << this->re << " " << (this->im >= 0 ? "+" : "") << this->im << "i\n";
}

int main()
{
  int a, b, c, d;
  char op, tmp;

  while (cin >> a >> b >> tmp >> op >> c >> d >> tmp)
  {
    Complexo z1(a, b),
        z2(c, d);

    switch (op)
    {
    case '+':
      z2.soma(z1);
      break;
    case '-':
      z2.subtrai(z1);
      break;
    case '*':
      z2.multiplica(z1);
      break;
    case '/':
      z2.divide(z1);
      break;
    }

    z2.imprime();
  }

  return 0;
}
