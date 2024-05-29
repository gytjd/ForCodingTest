#include <iostream>
#include <vector>

using namespace std;

int N,M;
int arr[104];

void display_() {
    for(int i=1;i<=N;i++) {
        cout << arr[i] << " ";
        if(i%20==0) cout << "\n";
    }
    cout << "\n";
}

void man_go(int temp) {
    
    for(int i=temp;i<=N;i+=temp) {
        arr[i]=!arr[i];
    }
}

void girl_go(int temp) {
    int low=temp;
    int high=temp;
    
    while(low>0 and high<=N) {
        if(arr[low]!=arr[high]) {
            break;
        }
        low-=1;
        high+=1;
    }
    
//    cout << low << " " << high << "\n";
    for(int i=low+1;i<high;i++) {
        arr[i]=!arr[i];
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=1;i<=N;i++) {
        cin >> arr[i];
    }
    
    cin >> M;
    for(int i=0;i<M;i++) {
        int com,num;
        cin >> com >> num;
        
        if(com==1) {
            man_go(num);
        }
        else {
            girl_go(num);
        }
    }
    display_();
    
    return 0;
}
