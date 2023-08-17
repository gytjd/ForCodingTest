#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 500004

using namespace std;

struct Node {
    int x,y,w;
};

struct cmp {
    bool operator()(Node &a,Node &b) {
        if(a.y==b.y) {
            return a.x<b.x;
        }
        return a.y<b.y;
    }
};

long long N,C;
vector<Node> v;
pair<long long,long long> tree[MAX_SIZE*4]; //first 는 weight , second 는 count

void update_(int node,int start,int end,int idx,int num) {
    
//    cout << start << " " << end << " " << idx << " " << num << "\n";
    if(idx<start or idx>end) {
        return;
    }
    
    if(start==end) {
        tree[node].first+=num;
        tree[node].second+=1;
        return;
    }
    
    update_(node*2,start,(start+end)/2,idx,num);
    update_(node*2+1,(start+end)/2+1,end,idx,num);
    tree[node].first=tree[node*2].first+tree[node*2+1].first;
    tree[node].second=tree[node*2].second+tree[node*2+1].second;
}

long long count_(int node,int start,int end,long long cnt) {
    
//    cout << start << " " << end << " " << tree[node*2].second << " " << cnt << "\n";
    
    if(start==end) {
        return start;
    }
    
    if(tree[node*2].second>=cnt) {
        return count_(node*2, start, (start+end)/2, cnt);
    }
    else {
        return count_(node*2+1,(start+end)/2+1,end,cnt-tree[node*2].second);
    }
}

long long sum_(int node,int start,int end,int left,int right) {
    if(left>end or right<start) {
        return 0;
    }
    
    if(left<=start and right>=end) {
        return tree[node].first;
    }
    
    long long tempA=sum_(node*2, start, (start+end)/2, left, right);
    long long tempB=sum_(node*2+1,(start+end)/2+1,end,left,right);
    return tempA+tempB;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> N >> C;
    for(int i=0;i<N;i++) {
        int x,y,w;
        cin >> x >> y >> w;
        v.push_back({x,y,w});
    }
    
    sort(v.begin(), v.end(), cmp());
    
    long long ret=0;
    
    for(int i=0;i<N;i++) {
        update_(1, 0, MAX_SIZE, v[i].x,v[i].w);
        
        if(i!=N-1 and v[i].y==v[i+1].y) {
            continue;
        }
        long long temp_Idx=count_(1, 0, MAX_SIZE, C);
        if(temp_Idx!=MAX_SIZE) {
            ret=max(ret,sum_(1, 0, MAX_SIZE, 0, temp_Idx));
        }
    }
    
    cout << ret << "\n";
    
    return 0;
}
