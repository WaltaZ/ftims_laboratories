#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double function(double x){
    return cos(x) - x;
}

int main(){
    
    double xl, xr, accuracy;

    cout << "Specify accuracy (amount of digits): ";
    cin >> accuracy;
    cout << "Specify xl: ";
    cin >> xl;
    cout << "Specify xr: ";
    cin >> xr;

    double tolerance = pow(0.1, accuracy), error, x_next, x = xl;
    double false_counter = 0;

    do{
        false_counter++;
        x = x_next;
        x_next = ((xl * function(xr)) - (xr * function(xl))) / (function(xr) - function(xl));

        if(function(xl) * function(x_next) < 0){
            xr = x_next;
        } else {
            xl = x_next;
        }

        error = abs((x_next - x) / x_next);

    } while(error > tolerance);

    cout << setprecision(accuracy) << "Found root with \"False Position method\" at x = " << x_next << " in " << false_counter << " iterrations" << endl << endl;

    double x0, x1, secant_counter = 0;

    cout << "Specify x0: ";
    cin >> x0;
    cout << "Specify x1: ";
    cin >> x1;

    do {
        secant_counter++;
        x_next = ((x0 * function(x1) - x1 * function(x0)))/(function(x1) - function(x0));
        error = abs((x_next - x1) / x_next);
        x0 = x1;
        x1 = x_next;
    } while(error > tolerance);
    
    cout << setprecision(accuracy) << "Found root with \"Secant method\" at x = " << x_next << " in " << secant_counter << " iterrations" << endl << endl;

    return 0;
}