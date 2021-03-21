// g++ 13-contar.cpp -o contar.exe

#include <iostream>

using namespace std;

int main()
{
    int vectorSize, number, counter = 0;
    int *vector = new int[vectorSize];

    cin >> vectorSize;

    for (int i = 0; i < vectorSize; ++i)
    {
        cin >> vector[i];
    }

    cin >> number;

    for (int i = 0; i <= vectorSize; ++i)
    {
        if (vector[i] >= number)
        {
            counter += 1;
        }
    }

    cout << counter << endl;

    return 0;
}
