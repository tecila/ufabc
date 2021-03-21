// g++ 10-divisoresPares.cpp -o divisoresPares.exe

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long int number, i;
    vector<int> array;

    cin >> number;

    for (i = 1; i <= number; ++i)
    {
        if (number % i == 0)
            if (i % 2 == 0)
                array.push_back(i);
    }

    cout << array.size() << endl;

    return 0;
}
