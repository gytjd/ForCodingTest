#include <iostream>
using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N,K;
    cin >> N >> K;
    
    int temp[N];
    for(int i=0;i<N;i++) {
        cin >> temp[i];
    }
    
    int result=0;
    int max_result=0;
    
    for(int i=0;i<K;i++) {
        result+=temp[i];
    }
    max_result=result;
    
    for(int i=K;i<N;i++) {
        
        result=result+temp[i]-temp[i-K];
        
        if(max_result<result) {
            max_result=result;
        }
    }
    cout << max_result << "\n";
    
    return 0;
}
