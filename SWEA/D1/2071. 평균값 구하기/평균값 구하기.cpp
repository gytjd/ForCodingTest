#include <iostream>
#include <cmath>

using namespace std;

int avg(int *temp) {
    int i;
    float result=0;
    
    for(i=0;i<10;i++) {
        result+=temp[i];
    }
    
    return round(result/10);
}
int main() {
    int n;
    cin >> n;
    
    for(int i=0;i<n;i++) {
        int *temp=new int(10);
        for(int j=0;j<10;j++) {
            cin >> temp[j];
        }
        
        cout << "#" << i+1 << " " << avg(temp) << "\n";
        
    }
    
    return 0;
}
