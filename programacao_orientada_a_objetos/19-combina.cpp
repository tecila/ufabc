// g++ 19-combina.cpp -o combina.exe

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m, i;
    int z = n + m;
    int *vector1 = new int[n];
    int *vector2 = new int[m];
    int *joinVector = new int[z];
    int *reverseVector = new int[m];

    cin >> n >> m;

    for (i = 0; i < n; ++i)
    {
        cin >> vector1[i];
    }

    for (i = 0; i < m; ++i)
    {
        cin >> vector2[i];
    }

    for (i = 0; i < m; ++i)
    {
        reverseVector[i] = vector2[m - i - 1];
    }

    for (i = 0; i < n; ++i)
    {
        joinVector[i] = vector1[i];
    }

    for (i = 0; i < m; ++i)
    {
        joinVector[i + n] = reverseVector[i];
    }

    for (i = 0; i < m + n; ++i)
    {
        cout << joinVector[i] << ' ';
    }

    delete[] vector1;
    delete[] vector2;
    delete[] joinVector;

    return 0;
}
