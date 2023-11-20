#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

//1_11
void e1_11() {
	char hello[] = "Hello";
	char world[] = "World";
	printf("!!!%s, %s!!!", hello, world);
}

//1_18
void e1_18() {
	char position[10] = "  XOX XO ";
	printf("%c|%c|%c\n%c|%c|%c\n%c|%c|%c",
		   position[0], position[1], position[2], 
		position[3], position[4], position[5],
		position[6], position[7], position[8]);
}

//2_10
void e2_10() {
	double a, b, c;
	scanf_s("%lf %lf %lf", &a, &b, &c);
	double ak = a * a, bk = b * b, ck = c * c;
	double angle_A = acos((bk + ck - ak) / (2.0 * b * c));
	double angle_B = acos((ck + ak - bk) / (2.0 * c * a));
	double angle_C = acos((ak + bk - ck) / (2.0 * a * b));
	printf("In radians\nA=%lf\nB=%lf\nC=%lf\n", angle_A, angle_B, angle_C);
	angle_A = angle_A * 180.0 / M_PI;
	angle_B = angle_B * 180.0 / M_PI;
	angle_C = angle_C * 180.0 / M_PI;
	printf("In degrees\nA=%lf\nB=%lf\nC=%lf", angle_A, angle_B, angle_C);
}


//2_17d
double arctg(double x) {
	return atan(x);
}


double arctg_derivative(double x) {
	return 1 / (1 + x * x);
}

void e2_17d() {
	double x;
	scanf_s("%lf", &x);
	printf("arctg=%lf\narctg_derivative=%lf", arctg(x), arctg_derivative(x));
}
//2_17d end

int main() {
	//e1_11();
	//e1_18();
	//e2_10();
	e2_17d();
}