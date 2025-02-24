class Solution {
public:
    vector<vector<int>> graph;
    vector<int> bobTime;

    bool findBobPath(int node, int parent, int depth, int bob, vector<int>& path) {
        if (node == bob) {
            path.push_back(node);
            return true;
        }
        
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                if (findBobPath(neighbor, node, depth + 1, bob, path)) {
                    path.push_back(node);
                    return true;
                }
            }
        }
        return false;
    }

    int dfsAlice(int node, int parent, int time, vector<int>& amount) {
        int profit = amount[node];

        if (bobTime[node] != -1) {  // Bob visits this node
            if (bobTime[node] == time) profit /= 2; // They arrive at the same time
            else if (bobTime[node] < time) profit = 0; // Bob already took the amount
        }

        int maxProfit = INT_MIN;
        for (int neighbor : graph[node]) {
            if (neighbor != parent) {
                maxProfit = max(maxProfit, dfsAlice(neighbor, node, time + 1, amount));
            }
        }

        return profit + (maxProfit == INT_MIN ? 0 : maxProfit); // Add profit to max path value
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        graph.resize(n);
        bobTime.assign(n, -1);

        // Build the graph (undirected tree)
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Find Bob's path to node 0 and mark visit times
        vector<int> bobPath;
        findBobPath(0, -1, 0, bob, bobPath);
        for (int t = 0; t < bobPath.size(); t++) {
            bobTime[bobPath[t]] = t;
        }

        // DFS for Alice to find the max profitable path
        return dfsAlice(0, -1, 0, amount);
    }
};
