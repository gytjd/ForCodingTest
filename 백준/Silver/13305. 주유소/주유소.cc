#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> v;
vector<int> litter;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N-1;i++) {
        int data;
        cin >> data;
        v.push_back(data);
    }
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        litter.push_back(data);
    }
    
    int ret=0;
    int temp=1000000000;
    for(int i=0;i<N-1;i++) {
        if(litter[i]<temp) {
            temp=litter[i];
        }
        ret+=(temp*v[i]);
    }
    
    cout << ret << "\n";
    
    return 0;
}
