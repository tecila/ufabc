// g++ 46-subtraiDias.cpp -o subtraiDias.exe

#include <iostream>

using namespace std;

class Data
{
private:
  int dia, mes, ano;

public:
  Data();
  Data(int, int, int);
  void setDia(int);
  void setMes(int);
  void setAno(int);
  int getDia();
  int getMes();
  int getAno();
  bool isValida();
  bool isBissexto();
  int ultimoDiaDoMes();
  void printData();

  Data diaAnterior();
  Data operator-(int);
};

Data Data::diaAnterior()
{
  int d = this->getDia(),
      m = this->getMes(),
      a = this->getAno();

  Data dt2(d - 1, m, a);

  if (!dt2.isValida())
  {
    dt2.setMes(m - 1);
    dt2.setDia(dt2.ultimoDiaDoMes());
    dt2.setAno(a);
    if (!dt2.isValida())
    {
      dt2.setDia(31);
      dt2.setMes(12);
      dt2.setAno(a - 1);
    }
  }
  this->setDia(dt2.getDia());
  this->setMes(dt2.getMes());
  this->setAno(dt2.getAno());
}

Data Data::operator-(int d)
{
  int i;
  Data dt = *this;
  for (i = 0; i < d; i++)
  {
    dt.diaAnterior();
  }
  return dt;
}

Data::Data()
{
  this->setDia(0);
  this->setMes(0);
  this->setAno(0);
}

Data::Data(int dia, int mes, int ano)
{
  this->setDia(dia);
  this->setMes(mes);
  this->setAno(ano);
}

int Data::getDia()
{
  return this->dia;
}

int Data::getMes()
{
  return this->mes;
}

int Data::getAno()
{
  return this->ano;
}

void Data::setDia(int d)
{
  this->dia = d;
}

void Data::setMes(int m)
{
  this->mes = m;
}

void Data::setAno(int a)
{
  this->ano = a;
}

bool Data::isBissexto()
{
  int ano = this->getAno();
  return (ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0);
}

int Data::ultimoDiaDoMes()
{
  int m = this->getMes();
  int diasDoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (m == 2 && this->isBissexto())
  {
    diasDoMes[2]++;
  }
  return diasDoMes[m];
}

bool Data::isValida()
{
  int d = this->getDia(),
      m = this->getMes(),
      a = this->getAno();

  if (d >= 1 && d <= this->ultimoDiaDoMes() && m >= 1 && m <= 12)
  {
    return 1;
  }
  return 0;
}

int main()
{
  int d, m, a, q, i;
  Data dt;
  while (cin >> d >> m >> a >> q)
  {
    dt.setDia(d);
    dt.setMes(m);
    dt.setAno(a);
    dt = dt - q;

    cout << dt.getDia() << " " << dt.getMes() << " " << dt.getAno() << endl;
  }

  return 0;
}
