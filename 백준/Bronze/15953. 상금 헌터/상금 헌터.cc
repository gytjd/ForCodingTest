#include <iostream>

using namespace std;

int N;

int first_T(int num) {
    if(num==1) {
        return 5000000;
    }
    else if(num>=2 and num<=3) {
        return 3000000;
    }
    else if(num>=4 and num<=6) {
        return 2000000;
    }
    else if(num>=7 and num<=10) {
        return 500000;
    }
    else if(num>=11 and num<=15) {
        return 300000;
    }
    else if(num>=16 and num<=21) {
        return 100000;
    }
    else {
        return 0;
    }
}

int second_T(int num) {
    if(num==1) {
        return 5120000;
    }
    else if(num>=2 and num<=3) {
        return 2560000;
    }
    else if(num>=4 and num<=7) {
        return 1280000;
    }
    else if(num>=8 and num<=15) {
        return 640000;
    }
    else if(num>=16 and num<=31) {
        return 320000;
    }
    else {
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        int first,second;
        cin >> first >> second;
        cout << first_T(first)+second_T(second) << "\n";
    }
    return 0;
}
