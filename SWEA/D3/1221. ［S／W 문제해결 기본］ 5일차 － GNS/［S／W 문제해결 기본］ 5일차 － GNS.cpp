#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int N;
vector<int> v;

void display_() {
    for(int temp:v) {
        
        if(temp==0) {
            cout << "ZRO" << " ";
        }
        else if(temp==1) {
            cout << "ONE" << " ";
        }
        else if(temp==2) {
            cout << "TWO" << " ";
        }
        else if(temp==3) {
            cout << "THR" << " ";
        }
        else if(temp==4) {
            cout << "FOR" << " ";
        }
        else if(temp==5) {
            cout << "FIV" << " ";
        }
        else if(temp==6) {
            cout << "SIX" << " ";
        }
        else if(temp==7) {
            cout << "SVN" << " ";
        }
        else if(temp==8){
            cout << "EGT" << " ";
        }
        else {
            cout << "NIN" << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    
    for(int q=0;q<T;q++) {
        
        string temp;
        cin >> temp;
        cin >> N;
        v.clear();
        
        for(int i=0;i<N;i++) {
            string a;
            cin >> a;
            
            if(a[0]=='Z') {
                v.push_back(0);
            }
            else if(a[0]=='O') {
                v.push_back(1);
            }
            else if(a[0]=='T') {
                if(a[1]=='W') {
                    v.push_back(2);
                }
                else {
                    v.push_back(3);
                }
            }
            else if(a[0]=='F') {
                if(a[1]=='O') {
                    v.push_back(4);
                }
                else {
                    v.push_back(5);
                }
            }
            else if(a[0]=='S') {
                if(a[1]=='I') {
                    v.push_back(6);
                }
                else {
                    v.push_back(7);
                }
            }
            else if(a[0]=='E') {
                v.push_back(8);
            }
            else {
                v.push_back(9);
            }
        }
        
        sort(v.begin(), v.end());
        
        cout << "#" << q+1 << "\n";
        display_();
    }
    
    
    
    return 0;
}
