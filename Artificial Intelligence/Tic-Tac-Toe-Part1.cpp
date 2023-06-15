#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> board = {2,0,0,1,1,0,0,1,2};

    int count1=0,count2=0;

    for(int i=0; i<board.size(); i++)
    {
        if(board[i] == 1)
            count1++;
        if(board[i] == 2)
            count2++;
    }

    if((count1 - count2) > 1 || (count2 - count1) > 1)
    {
        cout << "Invalid move";
        return 0;
    }
    else
        cout << "Valid move" << endl;


    long long score=0;
    int j=8;
    for(int i=0; i<board.size(); i++)
    {
        score+=board[i]*pow(3,j);
        j--;
    }

    cout << "Score is: "<< score;


}