#include<bits/stdc++.h>

using namespace std;

int Row , Col , Ans , i , j;

char Kingdom[21][21];

void DFS(int i , int j)
{
    if(i < 0 || i >= Row || j < 0 || j >= Col)
        return;

    else if(Kingdom[i][j] == '#')
        return;

    else if(Kingdom[i][j] == '.')
    {
        Kingdom[i][j] = '#';
        Ans++;
    }

    DFS(i , j+1);
    DFS(i+1 , j);
    DFS(i , j-1);
    DFS(i-1 , j);
}

int main()
{
    int Test, Case = 1;

    cin >> Test;

    while(Test--)
    {
        cin >> Col >> Row;

        for(i = 0; i < Row; i++)
            cin >> Kingdom[i];

        for(i = 0; i < Row; i++)
        {
            for(j = 0; j < Col; j++)
            {
                Ans = 0;

                if(Kingdom[i][j] == '@')
                {
                    DFS(i , j);

                    break;
                }
            }

            if(Ans != 0)
                break;
        }

        cout << "Case " << Case++ << ": " << Ans + 1 << endl;
    }

    return 0;
}
