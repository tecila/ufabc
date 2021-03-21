// g++ 50-dataPrecisa24.cpp -o dataPrecisa24.exe

#include <iostream>

using namespace std;

class Relogio
{
private:
  int horas, minutos, segundos;

public:
  Relogio();
  Relogio(int, int, int);
  void setHoras(int);
  void setMinutos(int);
  void setSegundos(int);
  int getHoras();
  int getMinutos();
  int getSegundos();

  void imprime();
  void incrementa();
};

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
  void incrementa();
};

class DataPrecisa : Data,
                    Relogio
{
private:
public:
  DataPrecisa(int, int, int, int, int, int);
  void imprime();
  void incrementa();
};

Relogio::Relogio()
{
  this->setHoras(0);
  this->setMinutos(0);
  this->setSegundos(0);
}

Relogio::Relogio(int h, int m, int s)
{
  this->setHoras(h);
  this->setMinutos(m);
  this->setSegundos(s);
}

void Relogio::setHoras(int h)
{
  this->horas = h;
}

void Relogio::setMinutos(int m)
{
  this->minutos = m;
}

void Relogio::setSegundos(int s)
{
  this->segundos = s;
}

int Relogio::getHoras()
{
  return this->horas;
}

int Relogio::getMinutos()
{
  return this->minutos;
}

int Relogio::getSegundos()
{
  return this->segundos;
}

void Relogio::imprime()
{
  cout << this->getHoras() << ":" << this->getMinutos() << ":" << this->getSegundos() << endl;
}

void Relogio::incrementa()
{
  int h = this->getHoras(),
      m = this->getMinutos(),
      s = this->getSegundos() + 1;

  if (s >= 60)
  {
    s = s % 60;
    m++;
  }

  if (m >= 60)
  {
    m = m % 60;
    h++;
  }

  if (h >= 24)
    h = h % 24;

  this->setHoras(h);
  this->setMinutos(m);
  this->setSegundos(s);
}

Data::Data()
{
  this->setDia(0);
  this->setMes(0);
  this->setAno(0);
}

Data::Data(int d, int m, int a)
{
  this->setDia(d);
  this->setMes(m);
  this->setAno(a);
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

void Data::incrementa()
{
  int d = this->getDia(),
      m = this->getMes(),
      a = this->getAno();

  Data dt2(d + 1, m, a);

  if (!dt2.isValida())
  {
    dt2.setDia(1);
    dt2.setMes(m + 1);
    dt2.setAno(a);

    if (!dt2.isValida())
    {
      dt2.setDia(1);
      dt2.setMes(1);
      dt2.setAno(a + 1);
    }
  }

  this->setDia(dt2.getDia());
  this->setMes(dt2.getMes());
  this->setAno(dt2.getAno());
}

DataPrecisa::DataPrecisa(int d, int m, int a, int h, int mi, int s) : Data(d, m, a),
                                                                      Relogio(h, mi, s) {}

void DataPrecisa::imprime()
{
  cout << this->getDia() << "/" << this->getMes() << "/" << this->getAno() << " "
       << this->getHoras() << ":" << this->getMinutos() << ":" << this->getSegundos() << endl;
}

void DataPrecisa::incrementa()
{
  int h = this->getHoras();
  this->Relogio::incrementa();

  if (this->getHoras() < h)
  {
    this->Data::incrementa();
  }
}

int main()
{
  int d, m, a, h, mi, s;
  cin >> d >> m >> a >> h >> mi >> s;

  DataPrecisa dp(d, m, a, h, mi, s);
  char c;

  while (cin >> c)
  {
    dp.incrementa();
  }

  dp.imprime();

  return 0;
}
