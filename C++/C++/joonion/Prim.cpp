#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define INF 0xffff
typedef vector<vector<int>> matrix_t;
typedef vector<pair<int, int>> set_of_edges;
typedef pair<int, int> edge_t;


void prim(int n, matrix_t& W, set_of_edges& F)
{
    int vnear, min;
    vector<int> nearest(n + 1), distance(n + 1);
    F.clear(); // 𝐹 = ∅;
    // Init
    for (int i = 2; i <= n; i++)
    {
        nearest[i] = 1;
        distance[i] = W[1][i];
    }

    for (int i = 2; i <= n; i++)
    {
        if (i != n)
            cout << nearest[i] << " ";
        else
            cout << nearest[i] << "\n";
    }

    // 최소결정
    for(int k = 0; k < n -1; k++)
    {
        min = INF;
        for (int i = 2; i <= n; i++)
            if (0 <= distance[i] && distance[i] < min)
            {
                min = distance[i];
                vnear = i;
            }
        // e = edge connecting vertices indexed by vnear and nearest[vnear];
        // add e to F;
        F.push_back(make_pair(vnear, nearest[vnear]));
        distance[vnear] = -1;

        // 집합 Y에서 최소 계산 -> list up
        for (int i = 2; i <= n; i++)
            if (distance[i] > W[vnear][i])
            {
                distance[i] = W[vnear][i];
                nearest[i] = vnear;
            }

        // Print nearest Array
        for (int i = 2; i <= n; i++)
        {
            if(i != n)
                cout << nearest[i] << " ";
            else
            cout << nearest[i] << "\n";
        }
    }
}

int main()
{
    int n, m;// n is number of Vertex, m is number of Edge
    int u, v, w;
    matrix_t W; set_of_edges F;
    cin >> n >> m;
    W.resize(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        W[u][v] = w;
        W[v][u] = w;
    }

    for (int i = 1; i <= n; i++)
    {
        W[i][i] = 0;
    }
    
    prim(n, W, F);
    for (edge_t e : F)
    {
        u = e.first; v = e.second;
        cout << u << " " << v << " " << W[u][v] << endl;
    }
}

