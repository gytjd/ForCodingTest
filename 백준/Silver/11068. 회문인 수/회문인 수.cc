#include <iostream>

using namespace std;

int T;
int N;

bool is_palindrome() {

    for(int i=2;i<=64;i++) {
        
        int temp_N=N;
        string temp;
        while(temp_N) {
            temp.push_back(temp_N%i);
            temp_N/=i;
        }
        
        string rev_temp;
        
        for(int j=temp.length()-1;j>=0;j--) {
            rev_temp+=temp[j];
        }
        
        if(temp==rev_temp) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> T;
    while(T) {
        cin >> N;
        cout << is_palindrome() << "\n";
        T--;
    }
    return 0;
}
