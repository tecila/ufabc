// g++ 14-somaVet.cpp -o somaVet.exe

#include <iostream>

using namespace std;

int main()
{
    int vectorSize, counter = 0;
    int *vector = new int[vectorSize];

    cin >> vectorSize;

    for (int i = 0; i < vectorSize; ++i)
    {
        cin >> vector[i];
    }

    for (int i(vectorSize); i > 0; i--)
    {
        counter += vector[i - 1];
    }

    cout << counter << endl;

    return 0;
}
