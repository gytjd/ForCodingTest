#include <iostream>
#include <vector>

#define INF 10000001
using namespace std;

vector<int> tmp_P;
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

void path_(int i,int j,vector<vector<int>> &D)  {
    int k=D[i][j];
    if(k!=0) {
        path_(i,k, D);
        tmp_P.push_back(k);
        path_(k, j, D);
    }
}
void Floyd_(vector<vector<int>> &A,vector<vector<int>> &D) {

    vector<vector<int>> temp=A;
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            
            if(i==j) {
                temp[i][j]=0;
                D[i][j]=0;
            }
        }
    }
    
    for(int k=1;k<=N;k++) {
        for(int i=1;i<=N;i++) {
            for(int j=1;j<=N;j++) {
                if(temp[i][j]>temp[i][k]+temp[k][j]) {
                    temp[i][j]=temp[i][k]+temp[k][j];
                    D[i][j]=k;
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
    vector<vector<int>> D(N+1,vector<int>(N+1,0));
    
    for(int i=0;i<M;i++) {
        int start,end,weight;
        cin >> start >> end >> weight;
        
        if(arr[start][end]<weight) {
            continue;
        }
        arr[start][end]=weight;
    }

    Floyd_(arr,D);
    display_(arr);
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            
            if(arr[i][j]==INF or arr[i][j]==0) {
                cout << 0 << "\n";
                continue;
            }
            
            path_(i, j, D);
            cout << 2+tmp_P.size() << " ";
            cout << i << " ";
            for(int k=0;k<tmp_P.size();k++) {
                cout << tmp_P[k] << " ";
            }
            cout << j << "\n";
            tmp_P.clear();
        }
    }
    
    return 0;
}
