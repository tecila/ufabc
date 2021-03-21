// g++ 43-julianToGregorian.cpp -o julianToGregorian.exe

#include <iostream>

using namespace std;

class DataJuliana
{
private:
  int diaJuliano;

public:
  DataJuliana();
  DataJuliana(int);
  void setDiaJuliano(int);
  int getDiaJuliano();
};

DataJuliana::DataJuliana()
{
  this->setDiaJuliano(0);
}

DataJuliana::DataJuliana(int dia)
{
  this->setDiaJuliano(dia);
}

void DataJuliana::setDiaJuliano(int dia)
{
  this->diaJuliano = dia;
}

int DataJuliana::getDiaJuliano()
{
  return this->diaJuliano;
}

class DataGregoriana
{
private:
  int dia, mes, ano;

public:
  DataGregoriana();
  DataGregoriana(int, int, int);
  DataGregoriana(DataJuliana);
  void setDia(int);
  void setMes(int);
  void setAno(int);
  int getDia();
  int getMes();
  int getAno();
  operator DataJuliana();
};

DataGregoriana::DataGregoriana()
{
  this->setDia(0);
  this->setMes(0);
  this->setAno(0);
}

DataGregoriana::DataGregoriana(int dia, int mes, int ano)
{
  this->setDia(dia);
  this->setMes(mes);
  this->setAno(ano);
}

DataGregoriana::DataGregoriana(DataJuliana dj)
{
  int jd, q, z, w, x, a, b, c, d, e, f, dia, mes, ano;
  jd = dj.getDiaJuliano();
  q = jd + 0.5;
  z = q;
  w = (z - 1867216.25) / 36524.25;
  x = w / 4;
  a = z + 1 + w - x;
  b = a + 1524;
  c = (b - 122.1) / 365.25;
  d = 365.25 * c;
  e = (b - d) / 30.6001;
  f = 30.6001 * e;
  dia = b - d - f + (q - z);
  mes = e < 14 ? e - 1 : e - 13;
  ano = mes < 3 ? c - 4715 : c - 4716;
  this->setDia(dia);
  this->setMes(mes);
  this->setAno(ano);
}

int DataGregoriana::getDia()
{
  return this->dia;
}

int DataGregoriana::getMes()
{
  return this->mes;
}

int DataGregoriana::getAno()
{
  return this->ano;
}

void DataGregoriana::setDia(int d)
{
  this->dia = d;
}

void DataGregoriana::setMes(int m)
{
  this->mes = m;
}

void DataGregoriana::setAno(int a)
{
  this->ano = a;
}

DataGregoriana::operator DataJuliana()
{
  int dia, mes, ano, a, b, c, d, e, dj;
  dia = this->getDia();
  mes = this->getMes();
  ano = this->getAno();
  if (mes < 3)
  {
    ano--;
    mes += 12;
  }
  a = ano / 100;
  b = a / 4;
  c = 2 - a + b;
  d = 365.25 * (ano + 4716);
  e = 30.6001 * (mes + 1);
  dj = d + e + dia + 0.5 + c - 1524.5;
  return DataJuliana(dj);
}

int main()
{
  int d;
  DataJuliana dj;
  while (cin >> d)
  {
    dj.setDiaJuliano(d);

    DataGregoriana dg;
    dg = dj;
    cout << dg.getDia() << " " << dg.getMes() << " " << dg.getAno() << endl;
  }

  return 0;
}
