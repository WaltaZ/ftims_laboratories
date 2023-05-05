#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double func(double);

int main() {
    double xl, xr, accuracy;

    cout << "Specify x_l: ";
    cin >> xl;
    cout << "Specify x_r: ";
    cin >> xr;
    cout << "Specify accuracy (amount of digits): ";
    cin >> accuracy;

    if(func(xl) * func(xr) > 0){
        cout << "Given range contains no root or more than one";
        return 1;
    } else if(xr <= xl) {
        cout << "xl is bigger than xr";
        return 1;
    }

    double tolerance = pow(0.1, accuracy),
    error,
    xm;
    
    int iterCounter = 0;

    do {
        iterCounter++;

        xm = (xl + xr)/2;
        error = fabs((xr - xl) / xm);

        if(func(xl) * func(xm) < 0){
            xr = xm;
        } else {
            xl = xm;
        }

    } while(error > tolerance);

    cout << "Found root x = " << setprecision(accuracy) << xm << " in " << iterCounter << " iterations";
}

double func(double x){
    return cos(x) - x;
}