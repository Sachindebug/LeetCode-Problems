class Solution {
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        
        // build the graph
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // use DFS to collect information for each node
        vector<Node> nodes(n);
        dfs(graph, nodes, cost, 0, -1);
        
        // get coin for each node
        vector<long long> coin(n);
        for (int i = 0; i < n; i++) coin[i] = getCoin(nodes[i]);
        return coin;
    }
private:
    struct Node {
        int size;
        multiset<int> pos;
        multiset<int> neg;
    };
    void dfs(vector<vector<int>>& graph, vector<Node>& nodes, vector<int>& cost, int curr, int prev) {
        // update the current node
        nodes[curr].size = 1;
        if (cost[curr] > 0) nodes[curr].pos.insert(cost[curr]);
        if (cost[curr] < 0) nodes[curr].neg.insert(cost[curr]);
        
        // collect the information from the next nodes
        for (auto& next : graph[curr]) {
            // skip the parent node
            if (next == prev) continue;

            // go to the next child node
            dfs(graph, nodes, cost, next, curr);
            nodes[curr].size += nodes[next].size;
            nodes[curr].pos.insert(nodes[next].pos.begin(), nodes[next].pos.end());
            nodes[curr].neg.insert(nodes[next].neg.begin(), nodes[next].neg.end());
        
            // keep the maximum 3 positive integers 
            while (nodes[curr].pos.size() > 3) nodes[curr].pos.erase(nodes[curr].pos.begin());
            // keep the minimum 2 negative integers
            while (nodes[curr].neg.size() > 2) nodes[curr].neg.erase(--nodes[curr].neg.end());
        }
    }
    long long getCoin(Node& node) {
        // base case
        if (node.size < 3) return 1;

        // collect coins
        vector<int> coins;
        for (auto& c : node.pos) coins.push_back(c);
        for (auto& c : node.neg) coins.push_back(c);

        // find the maximum product
        long long best = LONG_LONG_MIN;
        for (int a = 0; a < coins.size(); a++) {
            for (int b = a + 1; b < coins.size(); b++) {
                for (int c = b + 1; c < coins.size(); c++) {
                    long long product = 1LL * coins[a] * coins[b] * coins[c];
                    best = max(best, product);
                }
            }
        }
        
        // if the maximum product is negative, replace with `0`
        if (best < 0) return 0;
        return best;
    }
};