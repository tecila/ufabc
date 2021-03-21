// g++ 15-buscaSegura.cpp -o buscaSegura.exe

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int vectorSize, x;
    vector<int> search;
    int *baseVector = new int[vectorSize];
    string message;

    cin >> vectorSize;

    for (int i = 0; i < vectorSize; ++i)
    {
        cin >> baseVector[i];
    }

    while (cin >> x)
    {
        search.push_back(x);
    }

    for (int i = 0; i < search.size(); ++i)
    {
        for (int j = 0; j < vectorSize; ++j)
        {
            if (search[i] == baseVector[j])
            {
                message = "SIM";
                break;
            }
            else
                message = "CHAVE NAO ENCONTRADA";
        }

        cout << message << endl;
    }

    return 0;
}
