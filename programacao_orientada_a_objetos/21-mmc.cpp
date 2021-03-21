// g++ 21-mmc.cpp -o mmc.exe

#include <iostream>

using namespace std;

int main()
{
    int a, b, mmc;

    cin >> a >> b;

    if (a > b)
        mmc = a;
    else
        mmc = b;
    while (1)
    {
        if (mmc % a == 0 && mmc % b == 0)
        {
            cout << mmc;
            break;
        }
        mmc++;
    }
    return 0;
}
