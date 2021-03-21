// g++ 20-mdc.cpp -o mdc.exe

#include <iostream>

using namespace std;

int main()
{
    int a, b, mdc;

    cin >> a >> b;

    while (b != 0)
    {
        int y = b;
        b = a % b;
        a = y;
    }
    cout << a;

    return 0;
}
