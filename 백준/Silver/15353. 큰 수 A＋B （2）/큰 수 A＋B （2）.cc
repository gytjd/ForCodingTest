#include <iostream>
#include <queue>
using namespace std;

deque<int> arr;

void calculate_(string a,string b) {
    
    long long i=a.size()-1;
    long long j=b.size()-1;
    int carry=0;
    int temp;
    while(i>=0 and j>=0) {
        
        temp=(a[i]-'0')+(b[j]-'0')+carry;
        carry=temp/10;
        temp=temp%10;
        arr.push_front(temp);
        i-=1;
        j-=1;
    }
    
    if(i==-1 and j==-1){
        if(carry!=0) {
            arr.push_front(carry);
        }
    }
    else if(j==-1) {
        for(long long q=i;q>=0;q--) {
            temp=a[q]-'0'+carry;
            carry=temp/10;
            temp=temp%10;
            arr.push_front(temp);
        }
        
        if(carry!=0) {
            arr.push_front(carry);
        }
    }else if(i==-1) {
        for(long long q=j;q>=0;q--) {
            temp=b[q]-'0'+carry;
            carry=temp/10;
            temp=temp%10;
            arr.push_front(temp);
        }
        if(carry!=0) {
            arr.push_front(carry);
        }
    }
    
    for(int temp:arr) {
        cout << temp;
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string a,b;
    cin >> a >> b;
    
    calculate_(a, b);
                     
    return 0;
}
