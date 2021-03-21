// g++ 08-eq2.cpp -o eq2.exe

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    float a, b, c, x1, x2, discriminant, realPart, imaginaryPart;

    cin >> a >> b >> c;
    discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        x2 = (-b - sqrt(discriminant)) / (2 * a);

        cout << fixed << setprecision(4) << x1 << " " << setprecision(4) << x2 << endl;
    }

    else
    {
        x1 = (-b + sqrt(discriminant)) / (2 * a);
        cout << setprecision(4) << x1 << endl;
    }

    return 0;
}
