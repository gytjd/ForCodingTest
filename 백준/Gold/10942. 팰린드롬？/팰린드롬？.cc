#include <iostream>
#include <vector>
using namespace std;

int N,M;
int dp[2004][2004];

vector<int> v;

void display_() {
    
    cout << "\n";
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
}
void go_() {
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=i;j++) {
            dp[i][j]=1;
        }
    }
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(j<=N and j+i<=N) {
                if(v[j]==v[j+i] and dp[j+1][j+i-1]==1) {
                    dp[j][j+i]=1;
                }
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    v.push_back(0);
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    go_();
//    display_();

    cin >> M;
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        cout << dp[start][end] << "\n";
    }
    
    return 0;
    
}

