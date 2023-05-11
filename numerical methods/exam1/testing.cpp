#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
 
using namespace std;
 
double f(double x){
    return x * exp(x);
}
 
double f_d3(double x){
    return exp(x) * (3 + x);
}
 
double central_difference(double x, double h){
    return (1.0 / (2.0 * pow(h, 3))) * (f(x + (2*h)) - (2 * f(x +h)) + (2 * f(x - h)) - f(x - (2 * h)));
}
 
int main(){
 
    int x = 3;
    vector<double> h = {0.10, 0.09, 0.08, 0.07, 0.06, 0.05, 0.04, 0.03, 0.02, 0.01};
 
    cout << "h | f''' central difference | f''' exact" << endl;
 
    for(int i = 0; i < h.size(); i++){
        cout << setprecision(8) << h[i] << " | " << central_difference(x, h[i]) << " | " << f_d3(x) << endl;
    }
 
    return 0;
}