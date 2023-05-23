#include <iostream>
#include <string>
#define INF 987654321
using namespace std;

int N;
string minDp[104];
string maxDp[104];

string min_Str(string a,string b) {
    if(stoll(a)<stoll(b)) {
        return a;
    }
    else {
        return b;
    }
}

string max_Str(string a,string b) {
    
    long long aSize=a.size();
    long long bSize=b.size();
    
    if(aSize<bSize) {
        return b;
    }
    else if(aSize>bSize) {
        return a;
    }
    else {
        for(int i=0;i<a.size();i++) {
            if(a[i]<b[i]) {
                return b;
            }
            else if(a[i]>b[i]) {
                return a;
            }
        }
    }
    return a;
}

void min_p() {
    fill(minDp, minDp+104, "");
    
    minDp[2]="1";
    minDp[3]="7";
    minDp[4]="4";
    minDp[5]="2";
    minDp[6]="0";
    minDp[7]="8";
    
    for(int i=8;i<=101;i++) {
//        cout << "#" << " " << i << "\n";
        for(int j=2;j<i;j++) {
            
            if(minDp[j]=="" or minDp[i-j]=="") {
                continue;
            }
            
            string temp=minDp[j]+minDp[i-j];
            if(temp[0]!='0')
                minDp[i]=(minDp[i]=="")?temp:min_Str(minDp[i], temp);
            
//            cout << j << " " << i-j << " " << temp << "\n";
//
            if(j==6) {
                temp="6"+minDp[i-j];
                minDp[i]=(minDp[i]=="")?temp:min_Str(minDp[i], temp);
            }
            else if(i-j==6) {
                
                if(minDp[j]=="0") {
                    continue;
                }
                temp=minDp[j]+"6";
                minDp[i]=(minDp[i]=="")?temp:min_Str(minDp[i], temp);
            }
            
//            cout << j << " " << i-j << " " << temp << "\n";

        }
//        cout << "###" << i << " " <<  minDp[i] << "\n";
    }
}

void max_p() {
    fill(maxDp, maxDp+104, "");
    
    maxDp[2]="1";
    maxDp[3]="7";
//    maxDp[4]="4";
//    maxDp[5]="5";
//    maxDp[6]="9";
//    maxDp[7]="8";
    
    for(int i=4;i<=101;i++) {
        for(int j=2;j<i;j++) {
            if(maxDp[j]=="0" or maxDp[j]=="" or maxDp[i-j]=="") {
                continue;
            }
            
            string temp=maxDp[j]+maxDp[i-j];
//            cout << temp << "\n";
            maxDp[i]=(maxDp[i]=="")?temp:max_Str(maxDp[i], temp);
        }
        
//        cout << "##" << i << " " <<maxDp[i] << "\n";
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    min_p();
    max_p();
    
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        if(data==6) {
            cout << 6 << " " << maxDp[data] << "\n";
        }
        else {
            cout << minDp[data] << " " << maxDp[data] << "\n";
        }
    }
    
    return 0;
}
