#include <iostream>

using namespace std;


int main() {
	float x, y;

	cin >> x;
	cin >> y;

	float S = tan(x/y), R = (pow(x, 1 / 3.0) * sin(x)/(pow(exp(1.0),3 * x) + pow(exp(1.0), 3 * y)));

	float C = max(R, S);

	cout << C;
}