#include <iostream>
#include <vector>

using namespace std;
int N;
vector<int>temp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    
    for(int i=0;i<N;i++) {
        
        bool check_Flag=false;
        int q;
        cin >> q;
        temp.clear();
        
        for(int i=0;i<q;i++) {
            int data;
            cin >> data;
            temp.push_back(data);
        }
        
        int max_data=temp[0];
        int tot=temp[0];
        int max_idx=0;
        
        for(int i=1;i<temp.size();i++) {
            
            tot+=temp[i];
            
            if(max_data==temp[i]) {
                check_Flag=true;
                continue;
            }
            if(max_data<temp[i]) {
                max_data=temp[i];
                max_idx=i;
                check_Flag=false;
            }

        }
        
        if(check_Flag==true) {
            cout << "no winner" << "\n";
        }
        else {
            
            if(temp[max_idx]<=tot/2) {
                cout << "minority winner " << max_idx+1 << "\n";
            }
            else {
                cout << "majority winner " << max_idx+1 << "\n";
            }
        }
        
    }
}
