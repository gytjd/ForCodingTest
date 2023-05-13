#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    
    int tempN;
    tempN=num;
    
    int count=0;
    
    while(1) {
        int a,b,c;
        int temp;
        
        a=num/10;
        b=num%10;
        c=a+b;
        
        temp=b*10+c%10;
        

        
        if(tempN==temp) {
            break;
        }
        else {
            num=temp;
        }
        
        count++;
    }
    
    cout << count+1 << "\n";
    
    return 0;
}
