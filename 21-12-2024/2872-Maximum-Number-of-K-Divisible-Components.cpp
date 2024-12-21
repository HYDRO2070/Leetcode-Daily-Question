class Solution {
    private:
    vector<vector<int>> adj;
    vector<bool> visit;
    int ans = 0;

    long long int dfs(int node,vector<int>& values,int k){
        visit[node] = true;
        long long int sum = values[node];
        for(int i : adj[node]){
            if(!visit[i]){
                sum += dfs(i,values,k);
            }
        }
        if(sum%(k) == 0){
            ans++;
            return 0;
        }
        else return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        adj.resize(n);
        visit.resize(n,false);
        for(auto arr : edges){
            adj[arr[0]].push_back(arr[1]);
            adj[arr[1]].push_back(arr[0]);
        }
        if(dfs(0,values,k) != 0) return 1+ans;
        return ans;
        
    }
};
