#include <iostream>
using namespace std;

int A,B,C;

void is_() {
    if(A+B+C==180) {
        
        if(A==60 and B==60 and C==60) {
            cout << "Equilateral" << "\n";
        }
        else if(A==B or B==C or A==C) {
            cout << "Isosceles" << "\n";
        }
        else if(A!=B and B!=C and A!=C) {
            cout << "Scalene" << "\n";
        }
    }
    else {
        cout << "Error" << "\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> A >> B >> C;
    
    is_();
    
    return 0;
}
