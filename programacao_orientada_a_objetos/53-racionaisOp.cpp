// g++ 53-racionaisOp.cpp -o racionaisOp.exe

#include <iostream>

using namespace std;

class DenominadorZeroException : public runtime_error
{
public:
  DenominadorZeroException() : runtime_error("Denominador igual a zero.")
  {
  }
};

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
  if (d == 0)
    throw DenominadorZeroException();

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
  if (this->denom == 0)
    throw DenominadorZeroException();

  cout << this->num << " " << this->denom << "\n";
}

int main()
{
  int a, b, c, d;
  char op;

  while (cin >> a >> b >> op >> c >> d)
  {
    try
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
      try
      {
        r2.imprime();
      }
      catch (DenominadorZeroException e)
      {
        cout << e.what() << endl;
      }
    }
    catch (DenominadorZeroException e)
    {
      cout << e.what() << endl;
    }
  }
  return 0;
}
