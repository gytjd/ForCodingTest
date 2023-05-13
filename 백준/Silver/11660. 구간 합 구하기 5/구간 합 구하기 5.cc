#include <iostream>

using namespace std;

int temp[1028][1028];


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int i,j;
    int N,M;
    
    int tempX,tempY;
    int oriX,oriY;
    cin >> N >> M;
    
    for(i=1;i<=N;i++) {
        for(j=1;j<=N;j++) {
            cin >> temp[i][j];
        }
    }
    
    for(i=1;i<=N;i++) {
        for(j=1;j<=N;j++) {
            temp[i][j]+=temp[i-1][j];
        }
    }
    
    for(i=1;i<=N;i++) {
        for(j=1;j<=N;j++) {
            temp[i][j]+=temp[i][j-1];
        }
    }
    
    for(i=0;i<M;i++) {
        cin >> tempX >> tempY >> oriX >> oriY;
        
        cout << temp[oriX][oriY]-temp[tempX-1][oriY]-temp[oriX][tempY-1]+temp[tempX-1][tempY-1] << "\n";
    }
    
    
    return 0;
    
}

