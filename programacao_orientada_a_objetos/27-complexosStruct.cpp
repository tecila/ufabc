// g++ 27-complexosStruct.cpp -o complexosStruct.exe

#include <iostream>

using namespace std;

typedef struct tComplex
{
  int re, im;
} Complex;

Complex complexo(int re, int im)
{
  Complex novo;
  novo.re = re;
  novo.im = im;
  return novo;
}

Complex soma(Complex c1, Complex c2)
{
  return complexo(c1.re + c2.re, c1.im + c2.im);
}

Complex sub(Complex c1, Complex c2)
{
  return complexo(c1.re - c2.re, c1.im - c2.im);
}

Complex mult(Complex c1, Complex c2)
{
  int a = c1.re, b = c1.im, c = c2.re, d = c2.im;
  return complexo(a * c - b * d, a * d + b * c);
}

Complex conjugado(Complex c)
{
  return complexo(c.re, -c.im);
}

Complex div(Complex c1, Complex c2)
{
  Complex num = mult(c1, conjugado(c2)),
          denom = mult(c2, conjugado(c2));
  return complexo(num.re / denom.re, num.im / denom.re);
}

void imprime(Complex c)
{
  cout << c.re << " " << (c.im >= 0 ? "+" : "") << c.im << "i\n";
}

int main()
{
  int a, b, c, d;
  char op, tmp;

  while (cin >> a >> b >> tmp >> op >> c >> d >> tmp)
  {
    Complex c1 = complexo(a, b), c2 = complexo(c, d), c3;

    switch (op)
    {
    case '+':
      c3 = soma(c1, c2);
      break;
    case '-':
      c3 = sub(c1, c2);
      break;
    case '*':
      c3 = mult(c1, c2);
      break;
    case '/':
      c3 = div(c1, c2);
      break;
    }

    imprime(c3);
  }

  return 0;
}
