#include <iostream>
#include <vector>
using namespace std;

int N,K;
bool visited[26];
vector<string> arr;

int max_tot=-987654321;

int find_digit() {
    
    int tmp_Cnt=arr.size();
    
    for(int i=0;i<arr.size();i++) {
        
        for(int j=0;j<arr[i].size();j++) {
            
            if(visited[arr[i][j]-97]==false) {
                tmp_Cnt-=1;
                break;
            }
        }
    }
    
    return tmp_Cnt;
}

void go_(int start,int depth) {
    
    if(K-5==depth) {
        
        int tmp=find_digit();
        if(max_tot<tmp) {
            max_tot=tmp;
        }
        
        return;
    }
    
    for(int i=start;i<26;i++) {
        
        if(visited[i]==false) {
            visited[i]=true;
            go_(i,depth+1);
            visited[i]=false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> N >> K;
    
    if(K<5) {
        cout << 0 << "\n";
    }
    else {
        visited['a'-97]=true;
        visited['c'-97]=true;
        visited['i'-97]=true;
        visited['n'-97]=true;
        visited['t'-97]=true;
        
        for(int i=0;i<N;i++) {
            string a;
            cin >> a;
            arr.push_back(a);
        }
        
        go_(0,0);
        
        cout << max_tot << "\n";
    }
    
    return 0;
}
