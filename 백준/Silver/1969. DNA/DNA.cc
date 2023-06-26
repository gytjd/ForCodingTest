#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<string> v;
string ret_Str;
int ret;

void to_Str(int idx) {
    
    if(idx==0) {
        ret_Str+='A';
    }
    else if(idx==1) {
        ret_Str+='C';
    }
    else if(idx==2) {
        ret_Str+='G';
    }
    else if(idx==3) {
        ret_Str+='T';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    for(int i=0;i<M;i++) {
        int visited[4]={0,};
        for(int j=0;j<N;j++) {
            if(v[j][i]=='A') {
                visited[0]+=1;
            }
            else if(v[j][i]=='C') {
                visited[1]+=1;
            }
            else if(v[j][i]=='G') {
                visited[2]+=1;
            }
            else if(v[j][i]=='T') {
                visited[3]+=1;
            }
        }
        
        int max_Idx=0;
        int max_ret=visited[0];
        for(int i=1;i<4;i++) {
            if(max_ret<visited[i]) {
                max_Idx=i;
                max_ret=visited[i];
            }
        }
        
        to_Str(max_Idx);
        ret+=N-max_ret;
    }
    
    cout << ret_Str << "\n";
    cout << ret << "\n";
    
    return 0;
}

