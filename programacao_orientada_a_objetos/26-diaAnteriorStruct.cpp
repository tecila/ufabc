// g++ 26-diaAnteriorStruct.cpp -o diaAnteriorStruct.exe

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

Data diaAnterior(Data d)
{
  if (d.dia == 1 && d.mes == 1)
    return data(31, 12, d.ano - 1);

  if (d.dia == 1 && d.mes == 3)
  {
    if (d.ano % 4 == 0)
      return data(29, d.mes - 1, d.ano);
    else
      return data(28, d.mes - 1, d.ano);
  }

  if (d.dia == 1)
  {
    if (d.mes == 4 || d.mes == 6 || d.mes == 9 || d.mes == 11)
      return data(31, d.mes - 1, d.ano);
    else
      return data(30, d.mes - 1, d.ano);
  }
  else
    return data(d.dia - 1, d.mes, d.ano);
}

void imprime(Data d)
{
  cout << d.dia << " " << d.mes << " " << d.ano << "\n";
}

int main()
{
  int dia, mes, ano;

  cin >> dia >> mes >> ano;

  Data d = data(dia, mes, ano);

  Data anterior = diaAnterior(d);

  imprime(anterior);

  return 0;
}
