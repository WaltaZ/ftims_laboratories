#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>

using namespace std;

double function(double x){
    return sin(x);
}

double trapezoid(double iterations, vector<double> range){
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

double simpson(double iterations, vector<double> range){
    double step = (range[1] - range[0])/(iterations);
    double sum = 0, x = range[0];

    sum += function(x);
    for(int i = 0; i < iterations - 1; i++){
        x += step;
        if(i%2 == 0){
            sum += 4.0 * function(x);
        } else {
            sum += 2.0 * function(x);
        }
    }

    sum += function(x + step);
    sum = sum * (step / 3.0);
    return sum;
}

double boole(double iterations, vector<double> range){
    double step = (range[1] - range[0])/(iterations);
    double sum = 0, x = range[0];

    for(int i = 0; i<=iterations; i++)
    {
        int i_case = (i-1) % 4;
        if(i == 0 || i == iterations){
            sum += (7.0 * function(x));
        } else if(i_case == 0 || i_case == 2){
            sum += (32.0 * function(x));
        } else if(i_case == 1) {
            sum += (12.0 * function(x));
        } else if(i_case == 3) {
            sum += (14.0 * function(x));
        }
        x += step;
    }
    
    sum = sum * (2.0 * step / 45.0);
    return sum;

    }

int main(){

    vector<double> iterations = {4, 8, 16, 32, 64, 128, 256, 512, 1024};
    vector<double> range = {0, M_PI};

    cout << "Trapezoids:" << endl;

    for(int i=0; i<iterations.size(); i++){
        cout << setprecision(13) << boole(iterations[i], range) << " | ";
    }

    return 0;
}