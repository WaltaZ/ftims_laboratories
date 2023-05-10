#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<double> solve_tridiagonal(vector<double> a, vector<double> b, vector<double> c, vector<double> r){

    for(int i = 1; i<b.size(); i++){
        b[i] = b[i] - ((a[i] / b[i-1]) * c[i-1]);
        r[i] = r[i] - ((a[i] / b[i-1]) * r[i-1]);
    }

    vector<double> x;
    x.push_back(r[r.size() - 1] / b[b.size() - 1]);

    for(int i = b.size() - 2; i >= 0; i--){
        double currentX = x[x.size() - 1];
        x.push_back((r[i] - (c[i] * currentX))/b[i]);
    }

    reverse(x.begin(), x.end());

    return x;

}

double function(double x){
    return 1/(1 + pow(x, 2));
}

int main(){

    // ------------------INPUT------------------
    vector<double> points = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    double x_start = -5, x_end = 5, step = 0.1;
    // -----------------------------------------

    double h = points[1] - points[0];
    vector<double> f_points, d2_a = {0}, d2_b = {1}, d2_c = {0}, d2_r = {0};

    for(int i = 0; i<points.size(); i++){
        f_points.push_back(function(points[i]));
    }

    for(int i = 2; i<points.size(); i++){
        d2_a.push_back(h);
        d2_b.push_back(4 * h);
        d2_c.push_back(h);
        d2_r.push_back(6 * (f_points[i] - (2 * f_points[i-1]) + f_points[i-2]) / h);
    }

    d2_a[0] = 0;
    d2_c[d2_c.size() - 1] = 0;
    d2_a.push_back(0);
    d2_b.push_back(1);
    d2_c.push_back(0);
    d2_r.push_back(0);

    vector<double> d2 = solve_tridiagonal(d2_a, d2_b, d2_c, d2_r);

    double x = x_start, precision_factor = 0.0001; // This is due to c++ limitations of decimal places and detection of the floors. It often bugs at checking two doubles equality

    while(x + precision_factor < x_end){

        double rindx = floor((x - points[0] + precision_factor) / h); // range_index
        double p = f_points[rindx] + ((((f_points[rindx + 1] - f_points[rindx])/h) - ((1.0/6.0) * (h * d2[rindx + 1])) - ((1.0/3.0) * (h * d2[rindx]))) * (x - points[rindx])) + ((d2[rindx] / 2.0) * pow(x - points[rindx], 2)) + (((d2[rindx + 1] - d2[rindx]) / (6.0 * h)) * pow(x - points[rindx], 3));
        
        cout << x << " | " << p << " | " << function(x) << endl;

        x += step;
    }
    
    cout << x << " | " << function(x) << " | " << function(x) << endl; // The last value will be always equal to f(x), because of the boundaries 

    return 0;

}