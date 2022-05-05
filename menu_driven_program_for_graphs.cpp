#include <bits/stdc++.h>
using namespace std;

class Graph{
    int type;
    int numVertices;
    vector<vector<int>> adjLists;
  public:
    Graph(int k,int V){
        type = k;
        numVertices = V;
        adjLists.resize(V);
    }
    void print_edges(){
        for(int i = 0; i < numVertices; i++){
            cout << i << " ";
            for(int j : adjLists[i]){
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    void addEdge(int src, int dest){
        if(type == 2){
            adjLists[src].push_back(dest);
            adjLists[dest].push_back(src);
        }
        else{
            adjLists[src].push_back(dest);
        }
    }
    void dfs(int i, vector<bool>& vis){
        vis[i] = true;
        cout << i << " ";
        for(int j:adjLists[i]){
            if(!vis[j]){
                dfs( j, vis);
            }
        }
    }
    void bfs(int i, vector<bool>& vis){
        queue<int> q;
        q.push(i);
        vis[i] = true;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            cout << temp << " ";
            for(int j:adjLists[temp]){
                if(!vis[j]){
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
    }
    bool isCycleExistType1(int i, vector<int>& vis){
        vis[i] = 1;
        for(int j:adjLists[i]){
            if(vis[j] == 0 && isCycleExistType1(j, vis)){
                return true;
            }
            else if(vis[j] == 1){
                return true;
            }
        }
        vis[i] = 2;
        return false;
    }
    bool isCycleExistType2(int i, vector<bool>& vis, int par){
        vis[i] = true;
        for(int j:adjLists[i]){
            if(j == par){
                continue;
            }else if(!vis[j]){
                if(isCycleExistType2( j, vis, i)){
                    return true;
                }
            }else{
                return true;
            }
        }
        return false;
    }
};
int main(){
    cout << "Select graph type\n";
    cout << "Type 1 for Directed graph and 2 for Undirected graph: ";
    int type;
    cin >> type;
    cout << "\n";
    cout << "Please input the number of nodes: ";
    int nodes;
    cin >> nodes;
    Graph g(type, nodes);
    cout << "\n";
    cout << "Please provide the number of edges you want: ";
    int edges;
    cin >> edges;
    cout << "Please provide " << edges << " edges one by one\n";
    for(int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        g.addEdge( u, v);
    } 
    g.print_edges();
    cout << "Which type of search do you want\n";
    cout << "Please type 1 for BFS, 2 for DFS, 3 for Detecting Cycles in the graph: ";
    int search;
    cin >> search;
    cout << "\n";
    if(search == 1){
        vector<bool> vis(nodes, false);
        for(int i = 0; i < nodes; i++){
            if(!vis[i]){
                g.bfs(i, vis);
                cout << "\n";
            }
        }
    }
    else if(search == 2){
        vector<bool> vis(nodes, false);
        for(int i = 0; i < nodes; i++){
            if(!vis[i]){
                g.dfs(i, vis);
                cout << "\n";
            }  
        }
    }
    else if(search == 3){
        bool bl = false;
        if(type == 2){
            vector<bool> vis(nodes, false);
            for(int i = 0; i < nodes; i++){
                if(!vis[i]){
                    bool flag = g.isCycleExistType2( i, vis, -1);
                    if(flag){
                        bl = true;
                        break;
                    }
                }
            }
        }
        else{
            vector<int> vis(nodes, 0);
            for(int i = 0; i < nodes; i++){
                if(vis[i] == 0){
                    if(g.isCycleExistType1(i, vis)){
                        bl = true;
                        break;
                    }
                }
            }
        }
        if(bl){
            cout << "Yes! there is cycle in this graph!";
        }
        else{
            cout << "No! there is no cycle in this graph";
        }
    }
}