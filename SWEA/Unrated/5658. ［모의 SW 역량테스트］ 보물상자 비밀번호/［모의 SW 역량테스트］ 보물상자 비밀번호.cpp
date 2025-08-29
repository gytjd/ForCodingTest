#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int T,N,K;
string temp;
unordered_map<string, bool> m;
vector<string> v;

void init_() {
    
    m.clear();
    v.clear();
}

int hexToInt(const string& hex) {
    int result = 0;
    for (char c : hex) {
        result *= 16;
        if (c >= '0' && c <= '9') result += c - '0';
        else if (c >= 'A' && c <= 'F') result += c - 'A' + 10;
        else if (c >= 'a' && c <= 'f') result += c - 'a' + 10;
    }
    return result;
}



int go_() {
    
    for(int i=0;i<N/4;i++) {
        
        for(int j=0;j<N;j+=N/4) {
            string ret="";
            for(int k=j;k<j+N/4;k++) {
                ret+=temp[k];
            }
            m[ret]=true;
        }
        
        
        temp=temp[N-1]+temp;
        temp.erase(N);
    }
    
    for(pair<string,bool> tempM:m) {
//        cout << tempM.first << " " << tempM.second << "\n";
        v.push_back(tempM.first);
    }
    
    sort(v.begin(),v.end(),greater<>());
    
    return hexToInt(v[K-1]);
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    for(int test_case=1;test_case<=T;test_case++) {
        
        cin >> N >> K;
        cin >> temp;
        
        init_();
        cout << "#" << test_case << " " << go_() << "\n";
    }
    
    return 0;
}
