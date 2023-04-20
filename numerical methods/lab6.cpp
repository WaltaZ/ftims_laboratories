#include <iostream>
#include <vector>

using namespace std;

int main()
{

    double inputMatrix[5][5] = {{2, -1, 0, 0, 0}, {-1, 2, -1, 0, 0}, {0, -1, 2, -1, 0}, {0, 0, -1, 2, -1}, {0, 0, 0, -1, 2}};
    vector<double> inputX = {0, 1, 2, 3, 4};
    double newMatrix[5][5] = {};

    newMatrix[0] = inputMatrix[0];

    for(int i = 1; i<5; i++){
        double cancelationFactor = inputMatrix[i-1][i] / inputMatrix[i-1][i-1];
        for(int j = 0; j<5; j++){
            
        }
    }

    return 0;
}