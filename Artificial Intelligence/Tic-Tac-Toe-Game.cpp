#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <cmath>


using namespace std;

//getting degree
int getScore(int pos)
{
    if (pos == 0 || pos == 2 || pos == 6 || pos == 8)
        return 3;

    if (pos == 4)
        return 4;

    return 2;
}
void printGameGrid(vector<int> &gameGrid)
{
    int count=0;
    for(int i=0;i<9;i++)
    {
        count++;
        cout<<gameGrid[i]<<" ";
        if(count==3)
        {
            count=0;
            cout<<endl;
        }
    }
}
bool isEmpty(int input) 
{
    if(input == 0)
    {
        return true;
    }
    return false;
}

bool rowWon(vector<int> &gameGrid, int player)
{
    for(int i=0; i<9; i+=3) 
    {
        int firstInRow = gameGrid[i];
        int secondInRow = gameGrid[i+1];
        int thirdInRow = gameGrid[i+2];

        if (!isEmpty(firstInRow) && !isEmpty(secondInRow) && !isEmpty(thirdInRow)) 
        {
            if (firstInRow==player && secondInRow==player && thirdInRow==player) 
            {
                return true;
            }
        }
    }

    return false;
}

bool columnWon(vector<int> &gameGrid, int player) 
{
    for(int i = 0; i < 3; ++i) 
    {
        int firstInColumn = gameGrid[i];
        int secondInColumn = gameGrid[i+3];
        int thirdInColumn = gameGrid[i+6];

        if(!isEmpty(firstInColumn) && !isEmpty(secondInColumn) && !isEmpty(thirdInColumn)) 
        {
            if(firstInColumn==player && secondInColumn==player &&thirdInColumn==player)
            {
                return true;
            }
        }

    }

    return false;
}

bool diagonalWon(vector<int> &gameGrid, int player) 
{
    int center = gameGrid[4];

    if(!isEmpty(center) && !isEmpty(gameGrid[0]) && !isEmpty(gameGrid[8])) 
    {
        if(center==player && gameGrid[0]==player && gameGrid[8]==player) 
        {
            return true;
        }
    }

    else if(!isEmpty(center) && !isEmpty(gameGrid[2]) && !isEmpty(gameGrid[6])) 
    {
        if(center==player && gameGrid[2]==player && gameGrid[6]==player) 
        {
            return true;
        }
    }

    return false;
}

bool checkWon(vector<int> &gameGrid, int player) 
{
    if(rowWon(gameGrid, player))
    {
        return true;
    } 
    else if(columnWon(gameGrid, player)) 
    {
        return true;
    } 
    else if(diagonalWon(gameGrid, player)) 
    {
        return true;
    }

    return false;
}

bool winning(vector<int> &gameGrid)
{
    return checkWon(gameGrid, 2);
}

bool blocking(vector<int> &gameGrid)
{
    return checkWon(gameGrid, 1);
}


int main()
{
    vector<int> gameGrid(9);

    int pos;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the pos(0 to 9):";
        cin >> pos;

        gameGrid[pos] = 1;

        int player1 = 0;
        int player2 = 0;
        for (int i = 0; i < 9; i++)
        {
            if (gameGrid[i] == 1)
                player1++;

            if (gameGrid[i] == 2)
                player2++;
        }

        if(abs(player1 - player2) > 1)
        {
            cout << "Invalid move";
            return 0;
        }
        else
            cout << "Valid move" << endl;
        
        int ans = INT_MIN;
        bool flag1 = false, flag2 = false;

        for (int i = 0; i < 9; i++)
        {
            if (gameGrid[i] == 0)
            {
                gameGrid[i] = 2;
                if (winning(gameGrid))
                {
                    cout << "Winning move !!" << endl;
                    flag1 = true;
                    printGameGrid(gameGrid);
                    cout << endl;
                    return 0;
                }
                else
                    gameGrid[i] = 0;
            }
        }

         for (int i = 0; i < 9; i++)
        {
            if (gameGrid[i] == 0 && flag1 == false )
            {
                gameGrid[i] = 1;
                if (blocking(gameGrid))
                {
                    cout << "Player is Winning!! (Blocking the position)" << endl;
                    gameGrid[i] = 2;
                    flag2 = true;
                    printGameGrid(gameGrid);
                    cout << endl;
                }
                else
                {
                    gameGrid[i] = 0;
                    flag1 = false;
                }
            }
        }
        int position = -1;


        for (int i = 0; i < 9; i++)
        {
            if (gameGrid[i] == 0 && flag1 == false && flag2 == false)
            {
                int temp = getScore(i);
                if (temp > ans)
                {
                    ans = temp;
                    position = i;
                }
                else
                {
                    flag1 = false;
                    flag2 = false;
                }
            }
        }
        if (position != -1)
        {
            gameGrid[position] = 2;
            printGameGrid(gameGrid);
            cout<<endl;
        }
    }
    printGameGrid(gameGrid);
    cout<<endl<<endl;
    cout << "No Player Won!!" << endl;
    cout << "Better try next time" << endl;

}
    /*

    Game Grid : 

    +---+---+---+
    | 0 | 1 | 2 |
    +---+---+---+
    | 3 | 4 | 5 |
    +---+---+---+
    | 6 | 7 | 8 |
    +---+---+---+

Indicators: 

    0 - Empty Spaces
    1 - Player 1 (me)
    2 - Player 2 (computer)

blocking () <- next step la player1 jinku shakto, block karnyachi garaj ahe
winning  () <- next step la player2(computer) jinku shakto.

Think as you are computer. You have to code in such way that computer has to win
    */

