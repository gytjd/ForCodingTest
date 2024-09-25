#include <iostream>

using namespace std;

int N,M;
string dat;

bool is_pass(string temp) {
    
    int dat_pot=0;
    
    for(char chtmp:temp) {
        if(chtmp==dat[dat_pot]) {
            dat_pot+=1;
        }
    }
    
    return dat_pot==N?true:false;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> M;
    cin >> dat;
    
    for(int i=0;i<M;i++) {
        bool check_Flag=false;
        string temp;
        cin >> temp;
        check_Flag=is_pass(temp);
        if(!check_Flag) {
            cout << "false" << "\n";
        } else {
            cout << "true" << "\n";
        }
    }
    
    
    return 0;
}
