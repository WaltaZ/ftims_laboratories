#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<double> a_static = {0, -1, -1, -1, -1};
    vector<double> b_static = {2, 2, 2, 2, 2};
    vector<double> c_static = {-1, -1, -1, -1, 0};

    vector<double> a = a_static, b = b_static, c = c_static;

    vector<double> r = {0, 1, 2, 3, 4};

    vector<double> x;

    for(int i = 1; i<b.size(); i++){
        b[i] = b[i] - ((a[i] / b[i-1]) * c[i-1]);
        r[i] = r[i] - ((a[i] / b[i-1]) * r[i-1]);
    }

    x.push_back(r[r.size() - 1] / b[b.size() - 1]);
    for(int i = b.size() - 2; i >= 0; i--){
        double currentX = x[x.size() - 1];
        x.push_back((r[i] - (c[i] * currentX))/b[i]);
    }

    reverse(x.begin(), x.end());

    for(int i = 0; i < x.size(); i++){
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    cout << endl << "Checking: " << endl;
    vector<double> r_checked;

    r_checked.push_back((b_static[0] * x[0]) + (c_static[0] * x[1]));
    cout << "r1 = " << r_checked[0] << endl;
    for(int i = 1; i<x.size() - 1; i++){
        r_checked.push_back((x[i - 1] * a_static[i]) + (x[i] * b_static[i]) + (x[i + 1] * c_static[i]));
        cout << "r" << i+1 << " = " << r_checked[r_checked.size() - 1] << endl;
    }
    r_checked.push_back((x[x.size() - 2] * a_static[x.size() - 1]) + (x[x.size() - 1] * b_static[x.size() - 1]));
    cout << "r" << r_checked.size() << " = " << r_checked[r_checked.size() - 1] << endl;

    return 0;
}