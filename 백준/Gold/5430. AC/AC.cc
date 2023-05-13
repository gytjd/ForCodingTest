#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

deque<string> arr;
int N;


void enqueue(string com) {
    
    com.erase(com.begin());
    com.erase(com.end()-1);
    stringstream temp(com);
    string n;
    
    while(getline(temp,n,',')) {
        arr.push_back(n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int T=0;T<N;T++) {
        
        arr.clear();
        int num;
        string com;
        string temp;
        
        cin >> com;
        cin >> num;
        cin >> temp;
        
        enqueue(temp);
        
        bool check_Flag=false;
        bool left_Flag=true;
        
        for(char a:com) {
            
            if(a=='R') {
                
                if(left_Flag) {
                    left_Flag=false;
                }
                else {
                    left_Flag=true;
                }
            }
            else {
                
                if(arr.size()==0) {
                    cout << "error" << "\n";
                    check_Flag=true;
                    break;
                }
                else {
                    if(left_Flag) {
                        arr.pop_front();
                    }
                    else {
                        arr.pop_back();
                    }
                }
            }
        }
        
    
        
        if(check_Flag) {
            continue;
        }
        
        cout << '[';
        if(left_Flag) {
            for(int i=0;i<arr.size();i++) {
                if(i==arr.size()-1) {
                    cout << arr[i];
                }
                else {
                    cout << arr[i] << ',';
                }
            }
        }
        else {
            for(int i=arr.size()-1;i>=0;i--) {
                if(i==0) {
                    cout << arr[i];
                }else {
                    cout << arr[i] << ',';
                }
            }
        }
        cout << "]\n";
        
    }
    return 0;
}
