// g++ 11-perfeito.cpp -o perfeito.exe

#include <iostream>

using namespace std;

int main()
{
    int number, i = 1, sum = 0;

    cin >> number;

    while (i < number)
    {
        if (number % i == 0)
            sum += i;
        i++;
    }

    if (sum == number)
        cout << "SIM" << endl;
    else
        cout << "NAO" << endl;

    return 0;
}
