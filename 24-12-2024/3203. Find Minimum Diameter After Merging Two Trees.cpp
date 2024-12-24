class Solution {
    vector<vector<int>> buildAdjList(vector<vector<int>>& edges) {
        vector<vector<int>> adjList(edges.size() + 1);

        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        } 

        return adjList;
    }

    int getTreeDiameter(vector<vector<int>>& adjList, int node, int parent, int& diameter) {
        int max1 = 0, max2 = 0;

        for(int neighbor : adjList[node]) {
            if(neighbor != parent) {
                int subtreeHeight = getTreeDiameter(adjList, neighbor, node, diameter);
                if(subtreeHeight > max1) {
                    max2 = max1;
                    max1 = subtreeHeight;
                } else if(subtreeHeight > max2) {
                    max2 = subtreeHeight;
                }
            }
        }

        diameter = max(diameter, max1 + max2);
        return 1 + max(max1, max2);
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> adjList1 = buildAdjList(edges1);
        vector<vector<int>> adjList2 = buildAdjList(edges2);

        int diameter1 = 0; getTreeDiameter(adjList1, 0, -1, diameter1);
        int diameter2 = 0; getTreeDiameter(adjList2, 0, -1, diameter2);
        int diameterCombined = ceil((double)diameter1/2) + ceil((double)diameter2/2) + 1;

        return max({diameter1, diameter2, diameterCombined});
    }
};
