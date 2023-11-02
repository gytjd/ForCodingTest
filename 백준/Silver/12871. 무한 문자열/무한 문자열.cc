#include <iostream>
#include <cmath>
using namespace std;

int gcd(int x, int y){
    int z;
    while(y!=0){
        z=x%y;
        x=y;
        y=z;
    }
    return x;
}

int lcm(int x, int y){
    return x*y/gcd(x, y);
}

int main(){
    
    string a, b;
    
    cin >> a >> b;
    
    string atm=a;
    string btm=b;
    
    int al=a.length();
    int bl=b.length();
    
    int ablcm=lcm(al, bl);
    
    if(a==b){
        cout << 1 << "\n";
        return 0;
    }
    
    while(al!=ablcm){
        atm+=a;
        al+=a.length();
    }
    
    while(bl!=ablcm){
        btm+=b;
        bl+=b.length();
    }

    
    if(atm==btm){
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }
    
    return 0;
}
