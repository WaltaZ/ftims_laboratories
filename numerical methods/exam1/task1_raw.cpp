#include <iostream>

using namespace std;

double f(double x)
{
    return (1.0/(1.0-x*x));
}

int main() {
    double xT[11];
    double x,p,l_jn;
    int NbStep,n;
    n=11; //number of points
    NbStep=int (20.000001/0.2); //number of steps
    //Give values to the points xj
    xT[0]=-5.0;
    for(int j=1;j<n;j++){
        xT[j]=xT[j-1]+5.0;
    }
    cout<<"Lagrange p(x):"<<endl;
    x=-5.0; //initial value of x
    for(int step=0;step<=NbStep;step++) //loop over x
    {
        p=0.0;
        for(int j=0;j<n;j++)
        {
            l_jn=0.0;
            for(int i=0;i<n;i++)
            {
                if(i==j) l_jn=l_jn*((x-xT[i])/(xT[j]-xT[i]));
            }
            p=p+l_jn*f(xT[j]);
        }
        cout<<"x= "<<x<<" p(x)= "<<p<<endl;
        x=x+0.2;
    }
    return 0;
}