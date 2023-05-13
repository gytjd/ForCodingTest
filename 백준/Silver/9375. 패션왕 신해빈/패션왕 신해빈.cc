#include <iostream>
#include <vector>
using namespace std;

vector<pair<string, int>> temp;

void push_vec(string a) {
    
    bool find_Flag=false;
    
    for(int i=0;i<temp.size();i++) {
        
        if(temp[i].first==a) {
            temp[i].second+=1;
            find_Flag=true;
        }
    }
    
    if(find_Flag==false) {
        temp.emplace_back(make_pair(a, 1));
    }
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int M;
        cin >> M;
        
        temp.clear();
        
        for(int j=0;j<M;j++) {
            string a,b;
            cin >> a >> b;
            
            push_vec(b);
        }
    
        
        int result;
        if(temp.size()>0) {
            result=(temp[0].second+1);
        }
        else {
            result=0;
        }
        
        
        for(int i=1;i<temp.size();i++) {
            result*=(temp[i].second+1);
        }
        
        
        if(result==0) {
            cout << result << "\n";
        }
        else {
            cout << result-1 << "\n";
        }
    }
    


    return 0;
}
