#include <iostream>
#include <unordered_map>
using namespace std;

string a;
unordered_map<string, int> tot;

void DFS_recur() {
    
    int tot_Cnt=0;
    for(int i=0;i<a.size();i++) {
        string temp="";
        for(int j=i;j<a.size();j++) {
            temp+=a[j];
            tot[temp]++;
            if(tot[temp]==1) {
    
                tot_Cnt+=1;
            }
        }
    }
    
    cout << tot_Cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> a;

    DFS_recur();

    return 0;
}
