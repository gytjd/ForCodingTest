#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int N;
vector<string> v;
vector<string> temp(1004,"");

unordered_map<string, int> q;

bool check_Flag=false;

void go_() {
    
    long long ret=1;
    long long size_N=v[0].size();
    
    
    for(long long i=size_N-1;i>=0;i--) {
        check_Flag=false;
        for(int j=0;j<N;j++) {
            temp[j]=v[j][i]+temp[j];
            
//            cout << temp[j] << "\n";
            
            if(q[temp[j]]==1) {
                check_Flag=true;
            }
            
            q[temp[j]]+=1;
        }
        
        if(!check_Flag) {
            cout << ret << "\n";
            break;
        }
        ret+=1;
    }
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        string data;
        cin >> data;
        v.push_back(data);
    }
    
    go_();
    
    return 0;
}
