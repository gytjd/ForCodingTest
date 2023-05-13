#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N,M;
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        int num;
        cin >> num;
        temp.emplace_back(num);
    }
    
    int max_num=0;
    
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            for(int k=j+1;k<N;k++) {
                int result=temp[i]+temp[j]+temp[k];
                
                if(result<=M and max_num<result) {
                    max_num=result;
                }
            }
        }
    }
    
    cout << max_num << "\n";
    
    return 0;
}
