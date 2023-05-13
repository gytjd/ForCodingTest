#include <iostream>
#include <vector>

#define INF 999999
using namespace std;

int N;

vector<int> keys;
vector<int> p;

vector<int> pre_v;
vector<int> inor_v;

struct Node {
    int key;
    Node *left;
    Node *right;
};

int minnum(vector<vector<int>> &A,int i,int j,int &minK) {
    int minValue=INF;
    int value;
    
    for(int k=i;k<=j;k++) {
        value=A[i][k-1]+A[k+1][j];
        
        for(int m=i;m<=j;m++) {
            value+=p[m];
        }
        
        if(minValue>value) {
            minValue=value;
            minK=k;
        }
    }
    
    return minValue;
}


Node *tree(int i,int j,vector<vector<int>> &R) {
    int k=R[i][j];
    if(k==0) {
        return nullptr;
    }
    else {
        Node *new_node=new Node;
        new_node->key=keys[k];
        new_node->left=tree(i, k-1, R);
        new_node->right=tree(k+1,j,R);
        return new_node;
    }
}

void preorder_(Node *root) {
    if(root) {
        pre_v.push_back(root->key);
        preorder_(root->left);
        preorder_(root->right);
    }
}

void inorder_(Node *root) {
    if(root) {
        inorder_(root->left);
        inor_v.push_back(root->key);
        inorder_(root->right);
    }
}

void optsearchTree(vector<vector<int>> &A,vector<vector<int>> &R) {
    for(int i=1;i<=N;i++) {
        A[i][i-1]=0;
        A[i][i]=p[i];
        
        R[i][i-1]=0;
        R[i][i]=i;
    }
    
    A[N+1][N]=0;
    R[N+1][N]=0;
    
    for(int i=1;i<=N-1;i++) {
        for(int j=1;j<=N-i;j++) {
            int k;
            A[j][j+i]=minnum(A, j, j+i,k);
            R[j][j+i]=k;
        }
    }
    
    for(int i=1;i<=N+1;i++) {
        for(int j=i-1;j<=N;j++) {
            
            if(j==N) {
                cout << A[i][j];
            }
            else {
                cout << A[i][j] << " ";
            }
        }
        cout << "\n";
    }
    
    
    for(int i=1;i<=N+1;i++) {
        for(int j=i-1;j<=N;j++) {
            if(j==N) {
                cout << R[i][j];
            }
            else {
                cout << R[i][j] << " ";
            }
        }
        cout << "\n";
    }
    cout << A[1][N] << "\n";
    
    Node *root=tree(1, N, R);
    
    preorder_(root);
    inorder_(root);
    
    for(int i=0;i<pre_v.size();i++) {
        if(i==pre_v.size()-1) {
            cout << pre_v[i];
        }
        else {
            cout << pre_v[i] << " ";
        }
    }
    cout << "\n";
    for(int i=0;i<inor_v.size();i++) {
        if(i==inor_v.size()-1) {
            cout << inor_v[i];
        }
        else {
            cout << inor_v[i] << " ";
        }
    }
    cout << "\n";

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    
    keys.push_back(0);
    p.push_back(0);
    
    for(int i=0;i<N;i++) {
        int key;
        cin >> key;
        keys.push_back(key);
    }
    
    for(int i=0;i<N;i++) {
        int temp;
        cin >> temp;
        p.push_back(temp);
    }
    
    vector<int> temp(N+1,0);
    vector<vector<int>> A(N+2,temp);
    vector<vector<int>> R(N+2,temp);
    
    optsearchTree(A, R);
    
    return 0;
    
}
