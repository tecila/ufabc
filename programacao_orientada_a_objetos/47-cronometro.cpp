// g++ 47-cronometro.cpp -o cronometro.exe

#include <iostream>
#include <string>

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

int main()
{
  Relogio cron;
  string c;

  while (cin >> c)
  {
    cron.incrementa();
  }

  cron.imprime();

  return 0;
}
