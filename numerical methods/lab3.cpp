#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double func1(double x){
    return (6435 * pow(x, 8) - 12012 * pow(x, 6) + 6930 * pow(x, 4) - 1260 * pow(x, 2) + 35) / 128;
}

double func1D(double x){
    return (51480 * pow(x, 7) - 72072 * pow(x, 5) + 27720 * pow(x, 3) - 2520 * x) / 128;
}

double func2(double x){
    return pow(x, 2) - (2 * x) - 2;
}

double func2D(double x){
    return (2 * x) - 2;
}

void hybridMethod(double xl, double xr, double accuracy)
{
    double tolerance = pow(0.1, accuracy), error, x_next;
    double x, xnr, LT, RT; // X newton Raphson
    int iterCounter=0, NRCounter=0, BisectionCounter=0;

    x_next = xl;

    do { 
        iterCounter++;
        x = x_next;
        LT = (x - xl) * func2D(x) - func2(x);
        RT = (x - xr) * func2D(x) - func2(x);

        if(LT * RT < 0)
        {
            x_next = x - (func2(x) / func2D(x));
            NRCounter++;
        } else {
            x_next = (xl + xr)/2;
            BisectionCounter++;
        }

        if(func2(xl) * func2(x_next) < 0){
                xr = x_next;
            } else {
                xl = x_next;
            }

        error = fabs((x_next - x) / x_next);
    } while(error > tolerance);

    cout << "Found root x = " << setprecision(accuracy) << x_next << " in " << iterCounter << " iterations: " << BisectionCounter << " for bisection and " << NRCounter << " for Newton-Raphson";
}

int main(){
    double xl, xr, accuracy;
    cout << "Specify accuracy (amount of digits): ";
    cin >> accuracy;
    cout << "Specify xl: ";
    cin >> xl;
    cout << "Specify xr: ";
    cin >> xr;

    hybridMethod(xl, xr, accuracy);
    
    return 0;
}