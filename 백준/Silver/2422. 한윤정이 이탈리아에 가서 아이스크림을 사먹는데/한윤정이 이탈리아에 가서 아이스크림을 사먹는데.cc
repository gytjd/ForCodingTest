#include <iostream>

int arr[201][201];
using namespace std;


int main()
{
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int n1, n2;
        cin >> n1 >> n2;
        arr[n1][n2] = 1;
        arr[n2][n1] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            for (int k = j + 1; k <= N; ++k) {
                if (arr[i][j] || arr[j][k] || arr[k][i]) continue;
                ans++;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
