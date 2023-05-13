#include <iostream>
#include <vector>

using namespace std;

int N,K;
vector<int> temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> K;
    
    for(int i=1;i<=N;i++) {
        temp.push_back(i);
    }
    
    int i=0;
    
    cout << "<";
    while(temp.size()) {
        
        i+=K-1;
        i%=temp.size();
        
        if(temp.size()==1) {
            cout << temp[i];
        }
        else {
            cout << temp[i] << ", ";
        }
        temp.erase(temp.begin()+i);
    }
    cout << ">" << "\n";;
    
    return 0;
}

