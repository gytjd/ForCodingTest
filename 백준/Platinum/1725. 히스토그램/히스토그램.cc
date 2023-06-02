#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int H;
long long treeSize;
vector<long long> v;

void display_(vector<long long> &tree) {
    for(int i=1;i<treeSize;i++) {
        cout << tree[i] << " ";
    }
    cout << "\n";
}

void init_(vector<long long> &tree,long long node,long long start,long long end) {
    
    if(start==end) {
        tree[node]=start;
    }
    else {
        init_(tree, node*2, start, (start+end)/2);
        init_(tree,node*2+1,(start+end)/2+1,end);
        tree[node]=v[tree[node*2]]<v[tree[node*2+1]]?tree[node*2]:tree[node*2+1];
    }
}

long long find_Min(vector<long long> &tree,long long node,long long start,long long end,long long left,long long right) {
    
//    cout << start << " " << end << "\n";
    
    if(left>end or right<start) {
        return -1;
    }
    
    if(left<=start and right>=end) {
        return tree[node];
    }
    
    long long tempA=find_Min(tree, node*2, start, (start+end)/2, left, right);
    long long tempB=find_Min(tree,node*2+1,(start+end)/2+1,end,left,right);
    
    if(tempA==-1 or tempB==-1) {
        if(tempA==-1 and tempB==-1) {
            return -1;
        }
        else if(tempA==-1) {
            return tempB;
        }
        else {
            return tempA;
        }
    }
    else {
        return v[tempA]<v[tempB]?tempA:tempB;
    }
}

long long go_(vector<long long> &tree,long long node,long long start,long long end,long long left,long long right) {
    
    long long min_Idx=find_Min(tree, node, start, end, left, right);
    long long ret=v[min_Idx]*(right-left+1);
//    cout << min_Idx << '\n';
    
    if(left<=min_Idx-1) {
        long long temp=go_(tree, node, start, end, left, min_Idx-1);
        ret=max(ret,temp);
    }
    
    if(min_Idx+1<=right) {
        long long temp=go_(tree, node, start, end, min_Idx+1, right);
        ret=max(ret,temp);
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;
    
    if(!T) {
        cout << 0 << "\n";
    }
    else {
        for(int i=0;i<T;i++) {
            long long data;
            cin >> data;
            v.push_back(data);
        }
        
        H=ceil(log2(T));
        treeSize=(1<<(H+1));
        vector<long long> tree(treeSize);
        
        init_(tree, 1, 0, T-1);
        cout << go_(tree, 1, 0, T-1, 0,T-1) << "\n";
    }
    
    return 0;
}
