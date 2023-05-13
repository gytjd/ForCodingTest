#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int N;
unordered_map<string, int> tot;
vector<string> ret;
vector<string> fin;

bool cmp(string a,string b) {
    return a>b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        string a,b;
        cin >> a >> b;
        ret.push_back(a);
        
        if(b=="enter") {
            tot[a]++;
        }
        else if(b=="leave") {
            tot[a]--;
        }
    }
    
    for(int i=0;i<ret.size();i++) {
        if(tot[ret[i]]==1) {
            fin.push_back(ret[i]);
            tot[ret[i]]--;
        }
    }
    
    sort(fin.begin(),fin.end(),cmp);
    
    for(string tmp:fin) {
        cout << tmp << "\n";
    }
    
    return 0;
}
