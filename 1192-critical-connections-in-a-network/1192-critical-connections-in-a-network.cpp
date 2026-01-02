class Solution {
public:
    void DFS(int node, int parent, vector<vector<int>> &adj, vector<int> &low, vector<int> &disc, vector<bool> &vis, int &count, vector<vector<int>> &bridges){
        low[node] = disc[node] = count;
        vis[node] = 1;

        for(int i = 0; i < adj[node].size(); i++){
            int neigh = adj[node][i];

            if(neigh == parent)
            continue;
            else if(vis[neigh]){
                low[node] = min(low[node], disc[neigh]);
            }else{
                count++;
                DFS(neigh,node,adj,low,disc,vis,count,bridges);

                low[node] = min(low[node], low[neigh]);

                if(low[neigh] > disc[node]){
                    vector<int> temp;
                    temp.push_back(node);
                    temp.push_back(neigh);
                    bridges.push_back(temp);
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        for(int i = 0; i < connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> bridges;

        vector<int> low(n);
        vector<int> disc(n);
        vector<bool> vis(n,0);

        int count = 0;

        DFS(0,-1,adj,low,disc,vis,count,bridges);

        return bridges;

    }
};