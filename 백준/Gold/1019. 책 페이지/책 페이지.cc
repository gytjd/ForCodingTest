#include <iostream>

using namespace std;

long long N;
long long visited[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    long long temp=0;
    long long curr=1;
    
    while(N!=0) {
        visited[0]-=curr;
        for(long long i=0;i<10;i++) {
            if(i<(N%10)) visited[i]+=((N/10)+1)*curr;
            if(i==N%10) {
                visited[i]+=(N/10)*curr;
                visited[i]+=temp+1;
            }
            if(i>N%10) visited[i]+=(N/10)*curr;
        }
        temp=(N%10)*curr+temp;
        N/=10;
        curr*=10;
    }
    
    for(long long i=0;i<10;i++) {
        cout << visited[i] << " ";
    }
    cout << "\n";
    
    return 0;
}
