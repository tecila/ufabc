// g++ 41-complexosOp.cpp -o complexosOp.exe

#include <iostream>

using namespace std;

class Complexo
{
private:
  int real;
  int imag;

public:
  Complexo();
  Complexo(int, int);
  void setReal(int);
  void setImag(int);
  int getReal();
  int getImag();
  void negativo();
  void imprime();

  Complexo operator+(Complexo);
  Complexo operator-(Complexo);
  Complexo operator*(Complexo);
  Complexo operator/(Complexo);
};

Complexo::Complexo()
{
  this->setReal(0);
  this->setImag(0);
}

Complexo::Complexo(int a, int b)
{
  this->setReal(a);
  this->setImag(b);
}

void Complexo::setReal(int r)
{
  this->real = r;
}

void Complexo::setImag(int i)
{
  this->imag = i;
}

int Complexo::getReal()
{
  return this->real;
}

int Complexo::getImag()
{
  return this->imag;
}

void Complexo::negativo()
{
  this->setReal(-this->getReal());
  this->setImag(-this->getImag());
}

void Complexo::imprime()
{
  cout << this->getReal() << " " << (this->getImag() >= 0 ? "+" : "") << this->getImag() << "i\n";
}

Complexo Complexo::operator+(Complexo z)
{
  int a, b, c, d;
  a = z.getReal();
  b = z.getImag();
  c = this->getReal();
  d = this->getImag();

  this->setReal(a + c);
  this->setImag(b + d);
}

Complexo Complexo::operator-(Complexo z)
{
  this->negativo();
  this->operator+(z);
}

Complexo Complexo::operator*(Complexo z)
{
  int a, b, c, d;
  a = z.getReal();
  b = z.getImag();
  c = this->getReal();
  d = this->getImag();

  this->setReal(a * c - b * d);
  this->setImag(a * d + b * c);
}

Complexo Complexo::operator/(Complexo z)
{
  int a, b, c, d;
  a = z.getReal();
  b = z.getImag();
  c = this->getReal();
  d = this->getImag();

  this->setReal((a * c + b * d) / (c * c + d * d));
  this->setImag((b * c - a * d) / (c * c + d * d));
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
      z2.operator+(z1);
      break;
    case '-':
      z2.operator-(z1);
      break;
    case '*':
      z2.operator*(z1);
      break;
    case '/':
      z2.operator/(z1);
      break;
    }

    z2.imprime();
  }

  return 0;
}
