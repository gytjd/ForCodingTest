#include <iostream>
#include <vector>

#define INF 987654321;

using namespace std;

vector<int> d;
int N;

int minnum(int i,int j,vector<vector<int>> &M) {
    
    int minValue=INF;
    int temp;
    
    for(int k=i;k<j;k++) {
        
        temp=M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j];

        if(temp<minValue) {
            minValue=temp;
        }
    }
    
    return minValue;
}
void minmult(vector<vector<int>> &M) {
    
    for(int i=1;i<=N;i++) {
        for(int j=i;j<=N;j++) {
            M[i][j]=0;
        }
    }
    
    for(int i=1;i<N;i++) {
        for(int j=1;j<=N-i;j++) {
            
            
            M[j][i+j]=minnum(j,i+j,M);
        }
    }
    
    cout << M[1][N] << "\n";
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int a,b;
        cin >> a >> b;
        if(i==0) {
            d.push_back(a);
            d.push_back(b);
            continue;
        }
        
        d.push_back(b);
    }
    
    vector<int> temp(N+1,-1);
    vector<vector<int>> M(N+1,temp);
    
    minmult(M);
    
    return 0;
}
