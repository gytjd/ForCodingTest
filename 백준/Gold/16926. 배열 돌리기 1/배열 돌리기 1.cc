#include <iostream>

using namespace std;

int N,M,R;
int arr[304][304];

void display_() {
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void rotate_(int startX,int startY,int endX,int endY) {
    
    int temp=arr[startX][startY];
    
    for(int i=startY;i<endY-1;i++) {
        arr[startX][i]=arr[startX][i+1];
    }
    
    for(int i=startX;i<endX-1;i++) {
        arr[i][endY-1]=arr[i+1][endY-1];
    }
    
    for(int i=endY-1;i>startY;i--) {
        arr[endX-1][i]=arr[endX-1][i-1];
    }
    
    for(int i=endX-1;i>startX;i--) {
        arr[i][startY]=arr[i-1][startY];
    }
    arr[startX+1][startY]=temp;
}

void go_() {
    
    int startX=0; int startY=0;
    int endX=N; int endY=M;
    
    while(startX<endX and startY<endY) {
        
        int cal=((endX-startX)*2+(endY-startY)*2)-4;
        
        for(int i=0;i<R%cal;i++) {
            rotate_(startX, startY, endX, endY);
        }
        
        startX+=1; startY+=1;
        endX-=1; endY-=1;
    }
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> R;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> arr[i][j];
        }
    }
    
    go_();
    display_();
    
    return 0;
}
