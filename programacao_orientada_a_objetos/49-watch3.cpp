// g++ 49-watch3.cpp -o watch3.exe

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
  void incrementaSegundo();
  void incrementaMinuto();
  void incrementaHora();
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
  int h = this->getHoras();
  string si;

  if (h > 12)
  {
    this->setHoras(h % 12);
    si = "PM";
  }
  else
    si = "AM";

  if (h == 0)
    this->setHoras(12);

  cout << this->getHoras() << ":" << this->getMinutos() << ":" << this->getSegundos() << " " << si << endl;
}

void Relogio::incrementaSegundo()
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

void Relogio::incrementaMinuto()
{
  int h = this->getHoras(),
      m = this->getMinutos() + 1,
      s = this->getSegundos();

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

void Relogio::incrementaHora()
{
  int h = this->getHoras() + 1,
      m = this->getMinutos(),
      s = this->getSegundos();

  if (h >= 24)
    h = h % 24;

  this->setHoras(h);
  this->setMinutos(m);
  this->setSegundos(s);
}

int main()
{
  int h, m, s;
  string si, t;

  cin >> h >> m >> s >> si;

  if (si == "PM")
    h = h + 12;

  Relogio relogio(h, m, s);

  while (cin >> t)
  {
    if (t == "tic")
      relogio.incrementaSegundo();
    else if (t == "tac")
      relogio.incrementaMinuto();
    else if (t == "toc")
      relogio.incrementaHora();
  }

  relogio.imprime();

  return 0;
}
