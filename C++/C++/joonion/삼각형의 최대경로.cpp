#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    vector<vector<int>> T;
    vector<vector<int>> C;
    vector<vector<int>> P;

    T.resize(n, vector<int>(n, 0));
    C.resize(n, vector<int>(n, 0));
    P.resize(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = 0;
            cin >> x;
            T[i][j] = x;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            C[i][j] = T[i][j];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            int x = C[1 + i][j];
            int y = C[1 + i][1 + j];

            if (x <= y)
            {
                C[i][j] += y;
                P[i][j] = 1;
            }
            else
            {
                C[i][j] += x;
                P[i][j] = 0;
            }
        }
    }


    cout << C[0][0] << endl;
    
    cout << "\n";
    for(int i=0;i<n;i++) {
        for(int j=0;j<=i;j++) {
            printf("%3d ",C[i][j]);
        }
        cout << "\n";
    }
    
    
    int x = 0;
    int y = 0;
    
    cout << "\n";
    
    while (P[x][y] != -1)
    {
        if (P[x][y] == 0)
        {
            cout << T[x][y] << " ";
            x++;

        }
        else if(P[x][y] == 1)
        {
            cout << T[x][y] << " ";
            x++;
            y++;
        }
    }
    cout << T[x][y];
        



    return 0;
}

