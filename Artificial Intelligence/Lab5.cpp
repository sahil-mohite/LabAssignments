#include <bits/stdc++.h>
using namespace std;

int signum(int net)
{
    if (net < 0)
        return -1;
    else
        return 1;
}

int main()
{
    float label[3] = {0 , 1 , 1};
    float Weights[4] = {1, -1, 0, 0.5};
    float c = 1;
    float x[3][4] = {
        {1, 2 , 3, 4},
        {1, 3 , 5, 7},
        {-1, 2, 4, 6}};

    
    for (int i = 0; i < 3; i++)
    {
        float net = 0;
        for (int j = 0; j < 4; j++)
        {
            net += Weights[j] * x[i][j];
        }
        int o;
        if (net != 0)
            o = signum(int(net));
        int y = label[i] - o;

        for (int j = 0; j < 4; j++)
        {
            Weights[j] =Weights[j] + c * y * x[i][j];
            cout <<Weights[j] << " ";
        }
        cout << endl;
    }
}

