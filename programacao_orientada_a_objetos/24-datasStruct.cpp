// g++ 24-datasStruct.cpp -o datasStruct.exe

#include <iostream>

using namespace std;

typedef struct tData
{
  int dia, mes, ano;
} Data;

Data data(int dia, int mes, int ano)
{
  Data novo;
  novo.dia = dia;
  novo.mes = mes;
  novo.ano = ano;
  return novo;
}

int valid(Data d)
{
  if ((d.dia >= 1 && d.dia <= 31) && (d.mes >= 1 && d.mes <= 12))
  {
    if ((d.dia == 29 && d.mes == 2) && ((d.ano % 4) == 0) || (d.dia <= 28 && d.mes == 2))
      return 1;

    if ((d.dia <= 30) && (d.mes == 4 || d.mes == 6 || d.mes == 9 || d.mes == 11))
      return 1;

    if ((d.dia <= 31) && (d.mes == 1 || d.mes == 3 || d.mes == 5 || d.mes == 7 || d.mes == 8 || d.mes == 10 || d.mes == 12))
      return 1;

    else
      return 0;
  }
  else
    return 0;
}

int main()
{
  int testes, dia, mes, ano;

  cin >> testes;

  for (int i = 0; i < testes; i++)
  {
    cin >> dia >> mes >> ano;

    Data d = data(dia, mes, ano);

    if (valid(d) == 0)
      cout << "DATA INVALIDA" << endl;
    else
      cout << "DATA VALIDA" << endl;
  }

  return 0;
}
