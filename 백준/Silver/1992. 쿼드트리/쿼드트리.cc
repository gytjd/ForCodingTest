#include <iostream>
using namespace std;

int temp[64][64];

int is_check(int x,int y,int N) {
    
    int i,j;
    int temp_result=temp[x][y];
    
    for(i=x;i<x+N;i++) {
        for(j=y;j<y+N;j++) {
            if(temp[i][j]!=temp_result) {
                return 1;
            }
        }
    }
    
    return 0;
}

void extract_graph(int x,int y,int N) {
    
    
    
    if(N==1) {
        cout << temp[x][y];
        return;
    }
    
    if(is_check(x, y, N)==1) {
        cout << "(";
        extract_graph(x, y, N/2);
        extract_graph(x, y+N/2, N/2);
        extract_graph(x+N/2, y, N/2);
        extract_graph(x+N/2, y+N/2, N/2);
        cout << ")";
    }
    else {
        cout << temp[x][y];
    }
    
    
}
int main() {
    
    int i,j;
    int N;
    cin >> N;

    for(i=0;i<N;i++) {
        string a;
        cin >> a;
        
        for(j=0;j<N;j++) {
            temp[i][j]=a[j]-'0';
        }
    }
    
    extract_graph(0, 0, N);
    cout << "\n";
    return 0;
}

