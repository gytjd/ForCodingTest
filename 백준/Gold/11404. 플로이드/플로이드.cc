#include <iostream>
#include <vector>

#define INF 10000001
using namespace std;

int N,M;


void display_(vector<vector<int>> &A) {
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            
            if(A[i][j]==INF) {
                cout << 0 << " ";
            }
            else {
                cout << A[i][j] << " ";
            }
        }
        cout << "\n";
    }
}

void Floyd_(vector<vector<int>> &A) {

    vector<vector<int>> temp=A;
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(i==j) {
                temp[i][j]=0;
            }
        }
    }
    
    for(int k=1;k<=N;k++) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                if(temp[i][j]>temp[i][k]+temp[k][j]) {
                    temp[i][j]=temp[i][k]+temp[k][j];
                }
            }
        }
    }
    
    A=temp;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    cin >> M;
    
    vector<vector<int>> arr(N+1,vector<int>(N+1,INF));
    
    for(int i=0;i<M;i++) {
        int start,end,weight;
        cin >> start >> end >> weight;
        
        if(arr[start][end]<weight) {
            continue;
        }
        arr[start][end]=weight;
    }

    Floyd_(arr);
    display_(arr);
    
    return 0;
}
