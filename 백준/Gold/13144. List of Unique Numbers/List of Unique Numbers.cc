#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long long> arr;
int visited[100004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    
    for(long long i=0;i<N;i++) {
        long long data;
        cin >> data;
        arr.push_back(data);
    }
    
    long long end=0;
    long long start=0;
    long long ret=0;
    
    while(end<N) {
        if(visited[arr[end]]==0) {
            visited[arr[end]]=1;
            end+=1;
        }
        else {
            ret+=end-start;
            visited[arr[start]]=0;
            start+=1;
        }
    }
    
    while(start<end) {
        ret+=end-start;
        start+=1;
    }
    
    cout << ret << "\n";
    
    return 0;
}
