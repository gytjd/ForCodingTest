#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> temp;

void find_succ(int N)  {
    
    int i;
    for(i=1;i<=N;i++) {
        
        int result=0;
        string a=to_string(i);
        
        for(char b:a) {
            result+=(b-'0');
        }
        result+=i;
    
        
        if(result==N) {
            temp.emplace_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    find_succ(N);
    
    if(temp.size()==0) {
        cout << 0 << "\n";
    }
    else {
        int i;
        int min_Value=temp[0];
        for(i=1;i<temp.size();i++) {
            if(temp[i]<min_Value) {
                min_Value=temp[i];
            }
        }
        
        cout << min_Value << "\n";
    }
}
