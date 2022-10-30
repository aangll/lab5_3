#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double h(const double x);
int main()
{
	double gp, gk, z;
	int n;

	cout << "gp = "; cin >> gp;
	cout << "gk = "; cin >> gk;
	cout << "n = "; cin >> n;

	cout << fixed;
	cout << "-------------------------" << endl;
	cout << "|" << setw(10) << setprecision(4) << "g" << "|" <<
		setw(12) << "z" << "|" << endl;
	cout << "-------------------------" << endl;

	double dg = (gk - gp) / n;

	double g = gp;

	while (g <= gk)
	{
		z = h(g * g + 1) + h(g + h(1)) + 1;
		cout <<"|" << setw(10) << setprecision(4) <<  g << "|" << setw(12) << z << "|" << endl;
		cout << "-------------------------" << endl;
		g += dg;
	}

	return 0;
}

double h(const double x)
{
	if (abs(x) >= 1)
		return (sin(x) + 1) / (1 + cos(x));
	else
	{
		double S = 0;
		int i = 0;
		double a = 1;
		S = a;
		do
		{
			i++;
			double R = x / (2 * i * (2 * i - 1));
			a *= R;
			S += a;
		} while (i < 5);
		return S;
	}

}