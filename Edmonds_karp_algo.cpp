#include <bits/stdc++.h>

using namespace std;
int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;
#define INF 100000000
int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;
    while (new_flow = bfs(s, t, parent)) {
        // cout << new_flow
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            cout << cur << " ";
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
        cout << cur << "\n";
    }

    return flow;
}
int main(){
    int m;
    cin >> n;
    cin >> m;
    int a,b;
    adj.resize(n);
    capacity.resize(n);
    for(int i = 0; i < n; i++){
        capacity[i].resize(n);
    }
    int c;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back(b);
        capacity[a][b] = c;
    }
    cout << maxflow(0, 4);
}