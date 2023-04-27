#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

#define X 2
#define D_EXACT 22.1671682968
#define D2_EXACT 29.5562243957

double function(double x){
    return x * exp(x);
}

double calculateN(double YValues[], double XValues[], int size){
    double sum_xy = 0, sum_x = 0, sum_y = 0, sum_x2 = 0;
    for(int i=0; i<size; i++){
        sum_xy += log(XValues[i]) * log(YValues[i]);
        sum_x += log(XValues[i]);
        sum_y += log(YValues[i]);
        sum_x2 += pow(log(XValues[i]), 2);
    }
    double a = ((size * sum_xy) - (sum_x * sum_y)) / ((size * sum_x2) - pow(sum_x, 2));
    return a;
}

int main(){
    double h[10] = {0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5};
    double h_d_for[10], h_d_central[10], h_d2_for[10], h_d2_central[10], h_d_for_error[10],  h_d_central_error[10], h_d2_for_error[10], h_d2_central_error[10];

    for(int i = 0; i<size(h); i++){
        h_d_for[i] = (function(X + h[i]) - function(X)) / h[i];
        h_d_central[i] = (function(X + h[i]) - function(X - h[i])) / (2*h[i]);

        h_d2_for[i] = (function(X) - (2 * function(X + h[i])) + function(X + (2 * h[i]))) / pow(h[i], 2);
        h_d2_central[i] = (function(X + h[i]) - (2 * function(X)) + function(X - h[i])) / pow(h[i], 2);

        h_d_for_error[i] = abs(h_d_for[i] - D_EXACT);
        h_d_central_error[i] = abs(h_d_central[i] - D_EXACT);
        h_d2_for_error[i] = abs(h_d2_for[i] - D2_EXACT);
        h_d2_central_error[i] = abs(h_d2_central[i] - D2_EXACT);

        cout << h[i] << " | " << h_d_for[i] << " | " << h_d_central[i] << " | " << h_d2_for[i] << " | " << h_d2_central[i] << " | " << h_d2_for_error[i] << " | " << h_d2_central_error[i] << endl;
    }

    cout << endl << calculateN(h_d_for_error, h, 10) << " | " << calculateN(h_d_central_error, h, 10) << " | " << calculateN(h_d2_for_error, h, 10) << " | " << calculateN(h_d2_central_error, h, 10);
    
}