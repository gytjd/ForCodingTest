#include <iostream>
using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;
};

int N;
Node arr[30];

void prefix_(Node *start) {
    
    if(start!=nullptr) {
        cout << start->data;
        prefix_(start->left);
        prefix_(start->right);
    }
}

void inorder_(Node *start) {
    if(start!=nullptr) {
        inorder_(start->left);
        cout << start->data;
        inorder_(start->right);
    }
}

void postorder_(Node *start) {
    if(start!=nullptr) {
        postorder_(start->left);
        postorder_(start->right);
        cout << start->data;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N;
    for(int i=0;i<N;i++) {
        char a,b,c;
        cin >> a >> b >> c;
        arr[a-'A'].data=a;
        
        if(b!='.') {
            arr[a-'A'].left=&arr[b-'A'];
        }
        
        if(c!='.') {
            arr[a-'A'].right=&arr[c-'A'];
        }
    }
    
    prefix_(&arr[0]);
    cout << "\n";
    inorder_(&arr[0]);
    cout << "\n";
    postorder_(&arr[0]);
    cout << "\n";
    
    return 0;
}
