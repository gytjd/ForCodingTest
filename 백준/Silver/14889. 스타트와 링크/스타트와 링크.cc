#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int arr[24][24];
int visited[14];
int N;

vector<int> v;

void make_com(int start,int depth) {
    
    if(depth==N/2) {
        
        int result=0;
        for(int i=0;i<N/2;i++) {
            for(int j=i+1;j<N/2;j++) {
                
//                cout << visited[i] << " " <<visited[j] << "\n";
                result+=arr[visited[i]][visited[j]];
                result+=arr[visited[j]][visited[i]];
            }
        }
        v.push_back(result);
        return;
    }
    for(int i=start;i<N;i++) {
        visited[depth]=i;
        make_com(i+1,depth+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }
    
    make_com(0, 0);
    
    int min_N=987654321;
    int v_Size=v.size();
    
    for(int i=0;i<v_Size/2;i++) {
        int temp=abs(v[i]-v[v_Size-1-i]);
        
        if(min_N>temp) {
            min_N=temp;
        }
    }
    
    cout << min_N << "\n";
    
    return 0;
}
