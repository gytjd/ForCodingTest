#include <iostream>
#include <cmath>

using namespace std;

int N;
int ret_Max,ret_Min;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        ret_Max+=abs(data);
    }
    for(int i=0;i<N;i++) {
        int data;
        cin >> data;
        ret_Min+=abs(data);
    }
    
    cout << ret_Max+ret_Max << "\n";
    
    return 0;
}
