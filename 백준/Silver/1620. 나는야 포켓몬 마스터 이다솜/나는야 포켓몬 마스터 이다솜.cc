#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<string, int>> tempA;
vector<string> tempB;

void find_poket(string a,int N) {
    int start=0;
    int end=N;
    
    while(start<=end) {
        int mid=(start+end)/2;
        
        if(tempA[mid].first==a) {
            cout << tempA[mid].second << "\n";
            break;
        }
        else if(tempA[mid].first<a) {
            start=mid+1;
        }
        else if(tempA[mid].first>a) {
            end=mid-1;
        }
    }
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N,M;
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;

        tempA.emplace_back(make_pair(a, i+1));
        tempB.emplace_back(a);
    }
    
    
    sort(tempA.begin(), tempA.end());
    
    for(int i=0;i<M;i++) {
        string a;
        cin >> a;
        
        if(a[0]>='1' and a[0]<='9') {
            cout << tempB.at(atoi(a.c_str())-1) << "\n";
        }
        else {
            find_poket(a, tempA.size());
        }
    }
    

    return 0;
    
}
