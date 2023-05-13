#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> tot;

int N,M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=1;i<=N;i++) {
        tot.push_back(i);
    }
    
    for(int i=0;i<M;i++) {
        int start,end;
        cin >> start >> end;
        reverse(tot.begin()+start-1, tot.begin()+end);
    }
    
    for(int i=0;i<N;i++) {
        cout << tot[i] << " ";
    }
    cout << "\n";
    
    return 0;
    
}
