#include <stdio.h>

double e2_4c(double x) {
	double x1 = x + 1;
	double x2 = x1 * x1;
	return x2 * x2 * x1;
}

int main() {
	double x;
	scanf_s("%lf", &x);
	printf("%lf", e2_4c(x));
}