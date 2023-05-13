#include <iostream>

using namespace std;


int temp[104];
int N,M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        int start,end,num;
        cin >> start >> end >> num;
        
        for(int j=start;j<=end;j++) {
            temp[j]=num;
        }
    }
    
    for(int i=1;i<=N;i++) {
        cout << temp[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
