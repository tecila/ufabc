// g++ 12-min.cpp -o min.exe
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int x, min;
    vector<int> numberStorage;

    while (cin >> x)
    {
        if (x >= 0)
            numberStorage.push_back(x);

        else
            break;
    }

    if (!numberStorage.empty())
    {
        for (int i = 0; i < numberStorage.size(); ++i)
        {
            if (numberStorage[i] < min)
            {
                min = numberStorage[i];
            }
        }

        cout << min << endl;
    }
    else
    {
        cout << "nenhum numero informado" << endl;
    }

    return 0;
}
