#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> result;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    for(int i=0;i<9;i++) {
        int temp;
        cin >> temp;
        result.emplace_back(temp);
    }
    
    sort(result.begin(), result.end());
    
    do {
        int total=0;
        
        for(int i=0;i<7;i++) {
            total+=result[i];
        }
        
        if(total==100) {
            for(int i=0;i<7;i++) {
                cout << result[i] << "\n";
            }
            break;
        }
        
    }while(next_permutation(result.begin(), result.end()));

    
    
    return 0;
}
