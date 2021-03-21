// g++ 30-datasPOO.cpp -o datasPOO.exe

#include <iostream>

using namespace std;

class Data
{
private:
  int dia;
  int mes;
  int ano;

public:
  Data(int, int, int);

  int getDia();
  int getMes();
  int getAno();

  void setDia(int);
  void setMes(int);
  void setAno(int);

  bool isValida();
  bool isBissexto();

  void imprime();
};

Data::Data(int d, int m, int a)
{
  this->dia = d;
  this->mes = m;
  this->ano = a;
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
  return this->ano % 4 == 0;
}

bool Data::isValida()
{
  if ((this->getDia() >= 1 && this->getDia() <= 31) && (this->getMes() >= 1 && this->getMes() <= 12))
  {
    if ((this->getDia() == 29 && this->getMes() == 2) && this->isBissexto() || (this->getDia() <= 28 && this->getMes() == 2))
      return true;

    if ((this->getDia() <= 30) && (this->getMes() == 4 || this->getMes() == 6 || this->getMes() == 9 || this->getMes() == 11))
      return true;

    if ((this->getDia() <= 31) && (this->getMes() == 1 || this->getMes() == 3 || this->getMes() == 5 || this->getMes() == 7 || this->getMes() == 8 || this->getMes() == 10 || this->getMes() == 12))
      return true;

    else
      return false;
  }
  else
    return false;
}

void Data::imprime()
{
  if (this->isValida())
    cout << "DATA VALIDA" << endl;

  else
    cout << "DATA INVALIDA" << endl;
}

int main()
{
  int testes, dia, mes, ano;

  cin >> testes;

  for (int i = 0; i < testes; i++)
  {
    cin >> dia >> mes >> ano;

    Data d(dia, mes, ano);

    d.imprime();
  }

  return 0;
}
