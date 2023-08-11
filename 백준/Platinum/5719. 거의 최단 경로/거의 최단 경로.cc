#include <iostream> 
#include <queue>
#include <vector> 
#include <string.h> 
#include <limits.h>
#include <stack> 
#define MAX 501 
using namespace std; 

int N, M ; 
int source, destination ; 
int a, b, c; 
int dist[MAX] ;
vector<int> prev_v[MAX] ;
int v[MAX][MAX] ; 
vector<int> conn[MAX] ; 
void dijkstra(int start) {  
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq ; 
    // weight, vertex  
    for (int i = 0 ; i < N ; i++) dist[i] = INT_MAX ; 

    dist[start] = 0 ; 
    pq.push(make_pair(0, start)); 

    while(!pq.empty()) {
        int weight = pq.top().first ; 
        int curr_v = pq.top().second ;
        pq.pop(); 

        for (int i = 0 ; i < conn[curr_v].size() ; i++) { 
            int next_v = conn[curr_v][i]; 
            int next_w = v[curr_v][next_v] ; 

            if (v[curr_v][next_v] != 0 && dist[next_v] > next_w + weight) { 
                dist[next_v] = next_w + weight ; 
                prev_v[next_v].clear() ;
                prev_v[next_v].push_back(curr_v);  
                pq.push(make_pair(dist[next_v], next_v)) ;
            }
            else if (v[curr_v][next_v] != 0 && dist[next_v] == next_w + weight) {
                prev_v[next_v].push_back(curr_v);  
            }
        }
    }
}

void remove_trace() {
    queue<int> q ; 
    q.push(destination) ; 
    bool visited[MAX] = {false, } ; 
    visited[destination] = true; 
    while(!q.empty()) { 
        int curr = q.front(); q.pop() ;

        for (int i = 0 ; i < prev_v[curr].size(); i++) {
            int prev = prev_v[curr][i]; 
            v[prev][curr] = 0 ; 

            if(!visited[prev]) { 
                q.push(prev);  
                visited[prev] = true; 
            }
        }
    }
}

int main(void) {    
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 

    while(1) {    
        cin >> N >> M ; 
        if ( N == 0 && M == 0 ) break; 
        cin >> source >> destination ; 

        for (int i = 0 ; i < M ; i++) {
            cin >> a >> b >> c ; 
            conn[a].push_back(b); 
            v[a][b] = c ; 
        }
        
        dijkstra(source); 
        remove_trace() ;  
        dijkstra(source); 

        if (dist[destination] == INT_MAX) cout << "-1" << '\n' ;
        else cout << dist[destination] << '\n'; 

        for(int i = 0; i < MAX; i++){
            memset(v[i], 0, sizeof(int) * MAX);
            if (conn[i].size() > 0) conn[i].clear(); 
            if (prev_v[i].size() > 0) prev_v[i].clear() ; 
        }
    }
    return 0; 
}