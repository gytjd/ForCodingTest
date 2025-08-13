#include <iostream>
#include <vector>

using namespace std;

int N,M;
int visited[5004];
vector<int> v;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    int cnt=0;
    int currIdx=M-1;
    
    while(true) {
        
        v.push_back(currIdx+1);
        visited[currIdx]=1;
        cnt+=1;
        
        if(cnt==N) {
            break;
        }
        
        int tempCnt=0;
        while(tempCnt<M) {
            currIdx=(currIdx+1)%N;
            if(visited[currIdx]==0) {
                tempCnt+=1;
            }
        }
    }
    
    cout << "<";
    for(int i=0;i<N;i++) {
        if(i!=N-1) {
            cout << v[i] << ", ";
        } else {
            cout << v[i];
        }
    }
    cout << ">" << "\n";
    
    return 0;
}
