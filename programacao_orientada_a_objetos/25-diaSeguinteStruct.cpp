// g++ 25-diaSeguinteStruct.cpp -o diaSeguinteStruct.exe

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

Data diaSeguinte(Data d)
{
  if (d.dia == 31 && d.mes == 12)
    return data(1, 1, d.ano + 1);

  if ((d.dia == 29 && d.mes == 2) && ((d.ano % 4) == 0) || (d.dia == 28 && d.mes == 2 && ((d.ano % 4) != 0)) || ((d.dia == 30) && (d.mes == 4 || d.mes == 6 || d.mes == 9 || d.mes == 11)) || ((d.dia == 31) && (d.mes == 1 || d.mes == 3 || d.mes == 5 || d.mes == 7 || d.mes == 8 || d.mes == 10 || d.mes == 12)))
    return data(1, d.mes + 1, d.ano);

  else
    return data(d.dia + 1, d.mes, d.ano);
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

  Data seguinte = diaSeguinte(d);

  imprime(seguinte);

  return 0;
}
