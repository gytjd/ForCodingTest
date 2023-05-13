#include <iostream>
using namespace std;

int arr[8]={15,22,13,27,12,10,25,20};

void SWAP_(int &pa,int &pb) {
    int temp;
    temp=pa;
    pa=pb;
    pb=temp;
}
void parition(int low,int high) {
    
    int pivotPoint=0;
    SWAP_(arr[low],arr[high]);
    int pivotItem=arr[low];
    int count_P=0;
    
    int j=low;
    for(int i=low+1;i<=high;i++) {
        if(arr[i]<pivotItem) {
            j++;
            SWAP_(arr[i], arr[j]);
            count_P+=1;
        }
    }
    
    pivotPoint=j;
    SWAP_(arr[low], arr[pivotPoint]);
    count_P+=1;
    cout << count_P << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    parition(0, 7);
    
    return 0;
}

