class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, deque<int>> graph;
        unordered_map<int, int> outDegree, inDegree;

        // Build the graph and degree counts
        for (auto& pair : pairs) {
            int u = pair[0], v = pair[1];
            graph[u].push_back(v);
            outDegree[u]++;
            inDegree[v]++;
        }

        // Find the start vertex
        int start = pairs[0][0];
        for (auto& [node, _] : graph) {
            if (outDegree[node] > inDegree[node]) {
                start = node;
                break;
            }
        }

        // Hierholzer's algorithm for Eulerian path
        vector<int> eulerPath;
        stack<int> stk;
        stk.push(start);

        while (!stk.empty()) {
            int curr = stk.top();
            if (!graph[curr].empty()) {
                int next = graph[curr].front();
                graph[curr].pop_front();
                stk.push(next);
            } else {
                eulerPath.push_back(curr);
                stk.pop();
            }
        }

        // Construct the result
        reverse(eulerPath.begin(), eulerPath.end());
        vector<vector<int>> result;
        for (int i = 0; i < eulerPath.size() - 1; i++) {
            result.push_back({eulerPath[i], eulerPath[i + 1]});
        }

        return result;
    }
};
