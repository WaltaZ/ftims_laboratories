#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double function(double x){
    return sin(x);
}

double trapezoid(double iterations, double range[]){
    double step = (range[1] - range[0])/iterations;
    double sum = 0, x = range[0];

    sum += function(x)/2;

    while(x < (range[1] - step)){
        x += step;
        sum += function(x);
    }

    sum += function(x + step) / 2;

    sum = sum * step;
    return sum;
}

int main(){

    double iterations[9] = {4, 8, 16, 32, 64, 128, 256, 512, 1024};
    double range[2] = {0, M_PI};

    /*for(int i=0; i<len(iterations); i++){
        cout << iterations[i] << " | ";
    }*/

    cout << "Trapezoids:" << endl;

    for(int i=0; i<size(iterations); i++){
        cout << setprecision(13) << trapezoid(iterations[i], range) << " | ";
    }

    return 0;
}