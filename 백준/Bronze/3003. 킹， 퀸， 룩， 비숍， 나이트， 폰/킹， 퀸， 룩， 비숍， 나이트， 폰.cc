#include <iostream>

using namespace std;

int main() {
    
    int ori[6]={1,1,2,2,2,8};
    int temp[6];
    
    for(int i=0;i<6;i++) {
        cin >> temp[i];
    }
    
    for(int i=0;i<6;i++) {
        cout << ori[i]-temp[i] << " ";
    }
    cout << endl;
    
    

    return 0;
}
