#include <iostream>
#include <algorithm>

using namespace std;

int T,K;
string W;
vector<int> v[30];
int min_Ret,max_Ret;
bool check_Flag;

void init_() {
    min_Ret=987654321;
    max_Ret=-1;
    check_Flag=false;
    
    for(int i=0;i<30;i++) {
        v[i].clear();
    }
}

void cal_() {
    
    for(int i=0;i<W.size();i++) {
        v[(W[i]-97)].push_back(i);
    }
}

void find_() {
    
    for(int i=0;i<26;i++) {
        if(v[i].size()>=K) {

            check_Flag=true;
            for(int j=K-1;j<v[i].size();j++) {
                min_Ret=min(min_Ret,v[i][j]-v[i][j-K+1]+1);
                max_Ret=max(max_Ret,v[i][j]-v[i][j-K+1]+1);
            }
        }
    }
    
    if(check_Flag==false) {
        cout << -1 << "\n";
    } else {
        cout << min_Ret << " " << max_Ret << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    
    while(T) {
        cin >> W;
        cin >> K;
        
        init_();
        cal_();
        find_();
        T--;
    }
    
    return 0;
}