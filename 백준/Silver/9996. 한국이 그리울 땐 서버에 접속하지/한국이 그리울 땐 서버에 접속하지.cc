#include <iostream>
#include <string>

using namespace std;

int is_dir(string a,string b) {
    
    int i=0;
    int j=a.size()-1;
    
    while(a[i]!='*') {
        if(a[i]!=b[i]) {
            return 0;
        }
        i++;
    }

    
    int k=b.size()-1;
    
    while(a[j]!='*') {
        
        if(k<i) {
            return 0;
        }
        
        if(a[j]!=b[k]) {
            return 0;
        }
        
        j--;
        k--;
        
    }
    
    return 1;
}
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    string a;
    cin >> a;
    
    for(int i=0;i<N;i++) {
        string b;
        cin >> b;
        
        if(is_dir(a, b)==1) {
            cout << "DA" << "\n";
        }
        else {
            cout << "NE" << "\n";
        }
    }
    
    return 0;
}
