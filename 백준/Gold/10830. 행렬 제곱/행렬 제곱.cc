#include <iostream>
using namespace std;

int N;
long long B;

int temp[5][5];
int init[5][5];
int arr[5][5];

void cal(int a[5][5],int b[5][5]) {
    
    int i,j,k;
    
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            
            arr[i][j]=0;
            
            for(k=0;k<N;k++) {
                arr[i][j]+=(a[i][k]*b[k][j]);
            }
            arr[i][j]%=1000;
        }
    }
    
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            a[i][j]=arr[i][j];
        }
        
    }
}



int main() {
    
    cin >> N >> B;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> temp[i][j];
        }
        init[i][i]=1;
    }
    
    while(B!=0) {
        
        if(B%2==1) {
            cal(init,temp);
        }
        cal(temp,temp);
        
        B/=2;
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << init[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
