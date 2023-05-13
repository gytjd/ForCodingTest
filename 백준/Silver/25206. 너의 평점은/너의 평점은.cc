#include <iostream>

using namespace std;

double check_grade(string a) {
    if(a[0]=='A' and a[1]=='+') {
        return 4.5;
    }
    else if(a[0]=='A' and a[1]=='0') {
        return 4.0;
    }
    else if(a[0]=='B' and a[1]=='+') {
        return 3.5;
    }
    else if(a[0]=='B' and a[1]=='0') {
        return 3.0;
    }
    else if(a[0]=='C' and a[1]=='+') {
        return 2.5;
    }
    else if(a[0]=='C' and a[1]=='0') {
        return 2.0;
    }
    else if(a[0]=='D' and a[1]=='+') {
        return 1.5;
    }
    else if(a[0]=='D' and a[1]=='0') {
        return 1.0;
    }
    else {
        return 0;
    }
    
    return 0;
}
int main() {
    
    double tot=0;
    double result=0;
    
    for(int i=0;i<20;i++) {
        string sub;
        double score;
        string grade;
        
        cin >> sub >> score >> grade;
        

        
        if(grade=="P") {
            continue;
        }
        
        tot+=(score*check_grade(grade));
        result+=score;
    }
    
    if(tot==0 and result==0) {
        cout << "0.000000" << "\n";
    }
    else {
        printf("%lf\n",tot/result);
    }
    
    return 0;
}
