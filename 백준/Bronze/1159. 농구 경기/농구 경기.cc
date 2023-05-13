#include <iostream>
#include <string>

using namespace std;

int result[26];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++) {
        string a;
        cin >> a;
        
        result[a[0]-97]+=1;
    }
    
    bool Flag=false;
    for(int i=0;i<26;i++) {
        if(result[i]>=5) {
            printf("%c",i+97);
            Flag=true;
        }
    }
    
    if(Flag==false) {
        cout << "PREDAJA" << "\n";
    }
    
    return 0;
    
}
