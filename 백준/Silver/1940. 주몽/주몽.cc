#include <iostream>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N,M;
    cin >> N;
    cin >> M;
    int temp[N];
    
    for(int i=0;i<N;i++) {
        cin >> temp[i];
    }
    
    int count=0;
    for(int i=0;i<N-1;i++) {
        for(int j=i+1;j<N;j++) {
            if(temp[i]+temp[j]==M) {
                count+=1;
            }
        }
    }
    
    cout << count << "\n";
    
    return 0;
}
