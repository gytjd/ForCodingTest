
#include <iostream>
#include <vector>

#define INF 999999
using namespace std;

int N;
vector<int> d;

int minmum(int i,int j,int &mink,vector<vector<int>> &M) {
    int minValue=INF,value;
    
    for(int k=i;k<=j-1;k++) {
        value=M[i][k]+M[k+1][j]+d[i-1]*d[k]*d[j];
        
        if(minValue>value) {
            minValue=value;
            mink=k;
        }
    }
    
    return minValue;
}

void order(int i,int j,vector<vector<int>> &P,string &S) {
    if(i==j) {
        S+=string("(A")+to_string(i)+string(")");
    }
    else {
        int k=P[i][j];
        S+=string("(");
        order(i, k, P, S);
        order(k+1,j,P,S);
        S+=string(")");
    }
}
void minmult(vector<vector<int>> &M,vector<vector<int>> &P) {
    for(int i=1;i<=N;i++) {
        M[i][i]=0;
    }
    
    for(int diagonal=1;diagonal<=N-1;diagonal++) {
        for(int i=1;i<=N-diagonal;i++) {
            int j=i+diagonal;
            int k;
            M[i][j]=minmum(i, j,k, M);
            P[i][j]=k;
        }
    }
    
    
    for(int i=1;i<=N;i++) {
        for(int j=i;j<=N;j++) {
            if(j==N) {
                cout << M[i][j];
            }
            else {
                cout << M[i][j] << " ";
            }
        }
        cout << "\n";
    }
    
    for(int i=1;i<=N;i++) {
        for(int j=i;j<=N;j++) {
            
            if(j==N) {
                cout << P[i][j];
            }
            else {
                cout << P[i][j] << " ";
            }
        }
        cout << "\n";
    }
    
    cout << M[1][N] << "\n";
    string temp="";
    order(1, N, P, temp);
    cout << temp << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N+1;i++) {
        int a;
        cin >> a;
        d.push_back(a);
    }
    
    vector<int> temp(N+1,0);
    vector<vector<int>> M(N+1,temp);
    vector<vector<int>> P(N+1,temp);
    minmult(M,P);
    
    return 0;
}


