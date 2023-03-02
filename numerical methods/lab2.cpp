#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double func1(double x){
    return cos(x) - x;
}
double func1D(double x){
    return (-1) * sin(x) - 1;
}

double func2(double x){
    return (6435 * pow(x, 8) - 12012 * pow(x, 6) + 6930 * pow(x, 4) - 1260 * pow(x, 2) + 35) / 128;
}

double func2D(double x){
    return (51480 * pow(x, 7) - 72072 * pow(x, 5) + 27720 * pow(x, 3) - 2520 * x) / 128;
}

double func3(double x){
    return pow(x, 3) - 169;
}

double func3D(double x){
    return 3 * pow(x, 2);
}

int main(){
    double x, accuracy;
    cout << "Specify accuracy (amount of digits): ";
    cin >> accuracy;
    cout << "Specify x0: ";
    cin >> x;

    double tolerance = pow(0.1, accuracy), error, x_next;
    int iterCounter;

    do {
        iterCounter++;
        x_next = x - (func3(x) / func3D(x));
        error = fabs((x_next - x) / x_next);
        x = x_next;
    } while(error > tolerance);

    cout << "Found root x = " << setprecision(accuracy) << x << " in " << iterCounter << " iterations";
}