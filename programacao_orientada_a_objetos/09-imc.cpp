// g++ 09-imc.cpp -o imc.exe

#include <iostream>
using namespace std;

int main()
{
    float height, weight, imc;

    cin >> height >> weight;

    imc = weight / (height * height);

    if (imc < 16.0)
    {
        cout << "Magreza grave";
    }
    else if (imc < 17.0)
    {
        cout << "Magreza moderada";
    }
    else if (imc < 18.5)
    {
        cout << "Magreza leve";
    }
    else if (imc < 25.0)
    {
        cout << "Saudavel";
    }
    else if (imc < 30.0)
    {
        cout << "Sobrepeso";
    }
    else if (imc < 35.0)
    {
        cout << "Obesidade Grau I";
    }
    else if (imc < 40.0)
    {
        cout << "Obesidade Grau II (severa)";
    }
    else
    {
        cout << "Obesidade Grau III (morbida)";
    }

    return 0;
}
