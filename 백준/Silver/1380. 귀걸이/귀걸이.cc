#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int count_T=1;
    while(1) {
        int T;
        cin >> T;
        
        if(!T)
            break;
        
        vector<string> v;
        int visited[104]={0,};
        
        for(int i=0;i<T+1;i++) {
            string temp;
            getline(cin, temp);
            v.push_back(temp);
        }
        
        for(int i=0;i<2*T-1;i++) {
            int a;
            char b;
            cin >> a;
            cin >> b;
        

            if(visited[a]==0) {
                visited[a]=1;
            }
            else {
                visited[a]=0;
            }
        }

        for(int i=1;i<=T;i++) {
            if(visited[i]) {
                cout << count_T << " " << v[i] << "\n";
                break;
            }
        }
        count_T+=1;
    }
}
