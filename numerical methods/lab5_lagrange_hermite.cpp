#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

void lagrange(vector<double> x, vector<double> f, double cl, double cr, double step){

    cout << "Lagrange: " << endl;
    double currentX = cl;
    for(int i = 0; i<abs((cr - cl)/step); i++){
        double sum = 0;
        for(int j = 0; j<x.size(); j++){
            double l = 1;
            for(int k = 0; k<x.size(); k++){
                if(k != j)
                    l = l * ((currentX - x[k])/(x[j] - x[k]));
            }
            sum = sum + (l * f[j]);
        }
        currentX = currentX + step;
        cout << sum << " | ";
    }
    cout << endl << endl;

}

void hermite(vector<double> x, vector<double> f, vector<double> f_d, double cl, double cr, double step){

    cout << "Hermite: " << endl;

    double currentX = cl;

    for(int i = 0; i<abs((cr - cl)/step); i++){
        double sum = 0;
        for(int j = 0; j<x.size(); j++){
            double l = 1, l_prime = 0;
            for(int k = 0; k<x.size(); k++){
                if(k != j){
                    l = l * ((currentX - x[k])/(x[j] - x[k]));
                    l_prime += 1/(x[j] - x[k]);
                }
            }
            double h = (1 - (2 * (currentX - x[j]) * l_prime)) * pow(l, 2);
            double h_bar = (currentX - x[j]) * pow(l, 2);

            sum += (h * f[j]) + (h_bar * f_d[j]);
        }

        cout << sum << " | ";
        currentX += step;
    }

    cout << endl << endl;
}

int main(){
    vector<double> x_exp = {-1, 0.5, 1.5, 2}, x_mobius = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    vector<double> f_exp = {}, f_mobius = {}, f_mobius_d = {};

    for(int i = 0; i<x_exp.size(); i++){
        f_exp.push_back(exp(x_exp[i]));
    }

    for(int i = 0; i<x_mobius.size(); i++){
        f_mobius.push_back(1/(1 + pow(x_mobius[i], 2)));
        f_mobius_d.push_back(((-2) * x_mobius[i])/pow(1 + pow(x_mobius[i], 2), 2));
    }

    double cl, cr, step;
    cout << "Specify left constraint: ";
    cin >> cl;
    cout << "Specify right constraint: ";
    cin >> cr;
    cout << "Specify step: ";
    cin >> step;

    cout << "--------------- EXP -----------------" << endl;
    lagrange(x_exp, f_exp, cl, cr, step);
    hermite(x_exp, f_exp, f_exp, cl, cr, step);

    cout << "--------------- MOBIUS -------------------" << endl;
    lagrange(x_mobius, f_mobius, cl, cr, step);
    hermite(x_mobius, f_mobius, f_mobius_d, cl, cr, step);
    
}