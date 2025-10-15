#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double xp, xk, x, dx, eps, a = 0, R = 0, S = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
        << setw(12) << "arcsin(x)" << " |"
        << setw(12) << "S" << " |"
        << setw(5) << "n" << " |"
        << endl;
    cout << "-------------------------------------------------------------" << endl;

    x = xp;
    while (x <= xk + 1e-9) // щоб враховувався останній крок
    {
        n = 0;
        a = x;    // перший член ряду
        S = a;

        if (fabs(a) >= eps) {
            cout << "error";
        }

        do {
            n++;
            // Рекурентне співвідношення для наступного члена:
            // a_n+1 = a_n * ((2n-1)^2 * x^2) / ((2n)*(2n+1))
            R = pow((2.0 * n - 1), 2) * x * x / ((2.0 * n) * (2.0 * n + 1));
            a *= R;
            S += a;
        } while (fabs(a) >= eps);

        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(12) << setprecision(6) << asin(x) << " |"
            << setw(12) << setprecision(6) << S << " |"
            << setw(5) << n << " |"
            << endl;

        x += dx;
    }

    cout << "-------------------------------------------------------------" << endl;
    return 0;
}