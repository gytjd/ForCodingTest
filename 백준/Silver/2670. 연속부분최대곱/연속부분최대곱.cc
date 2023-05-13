#include <iostream>
#include <algorithm>
using namespace std;

double arr[10004];
double ret;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    
    ret=arr[0];
    for(int i=1;i<N;i++) {
        arr[i]=max(arr[i],arr[i]*arr[i-1]);
        ret=max(ret,arr[i]);
    }
    
    printf("%.3lf",ret);
    
    return 0;
}
