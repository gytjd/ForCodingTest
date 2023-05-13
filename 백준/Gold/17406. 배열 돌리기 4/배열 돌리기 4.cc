#include <iostream>
#include <vector>

using namespace std;

int N,M,K;
int arr[54][54];
vector<pair<pair<int, int>, int>> v;
int visited[7];
int fin_Ret=987654321;

void display_() {
    
    cout << "\n";
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void turn_(int ret[54][54],int r,int c,int s) {
    
    int temp[54][54];
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            temp[i][j]=ret[i][j];
        }
    }
    
    int startX=r-s;
    int startY=c-s;
    
    int endX=r+s;
    int endY=c+s;
    
    int tempN=endX-startX;
    int tempM=endY-startY;
    
    while(tempN!=0 and tempM!=0) {
        
        for(int i=endY;i>startY;i--) {
            temp[startX][i]=ret[startX][i-1];
        }
        for(int i=endX;i>startX;i--) {
            temp[i][endY]=ret[i-1][endY];
        }
        for(int i=startY;i<endY;i++) {
            temp[endX][i]=ret[endX][i+1];
        }
        for(int i=startX;i<endX;i++) {
            temp[i][startY]=ret[i+1][startY];
        }
        
        
        startX+=1; startY+=1;
        endX-=1; endY-=1;
        tempN-=2;
        tempM-=2;
    }
    
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            ret[i][j]=temp[i][j];
        }
    }
    
}

int find_min_row(int ret[54][54]) {
    

    int min_N=987654321;
    
    for(int i=1;i<=N;i++) {
        int tot=0;
        for(int j=1;j<=M;j++) {
            tot+=ret[i][j];
        }
        
        if(tot<min_N) {
            min_N=tot;
        }
    }
    
    return min_N;
}

void start_(int ret[54][54],int depth) {
    
    if(depth==K) {
        
        int temp=find_min_row(ret);
        if(fin_Ret>temp) {
            fin_Ret=temp;
        }
        return;
    }
    
    int temp[54][54];
    
    for(int i=1;i<=K;i++) {
        if(visited[i]==0) {
            visited[i]=1;
            
            for(int q=1;q<=N;q++) {
                for(int w=1;w<=M;w++) {
                    temp[q][w]=ret[q][w];
                }
            }
            
            turn_(temp,v[i-1].first.first,v[i-1].first.second,v[i-1].second);
            start_(temp, depth+1);
            visited[i]=0;
        }
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M >> K;
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i=0;i<K;i++) {
        int r,c,s;
        cin >> r >> c >> s;
        pair<int, int> temp={r,c};
        v.push_back({temp,s});
    }
    
    start_(arr, 0);
    cout << fin_Ret << "\n";
    
    return 0;
}
