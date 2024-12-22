class Solution {
    private:
    vector<int> nextgreat(vector<int>& arr,int n){
        stack<int> s;
        vector<int> ans;
        s.push(-1);

        for(int i = n-1;i >= 0;i--){

            while(s.top() != -1 && arr[s.top()] <= arr[i]) s.pop();
            ans.push_back(s.top());
            s.push(i);
        }
        reverse(ans.begin(),ans.end());
        for(auto num : ans){
            cout<<num<<" ";
        }
        cout<<endl;
        return ans;
    }

public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int m = queries.size();
        vector<int> ans(m,-1);
        vector<int> next = nextgreat(heights,n);

        for(int i = 0;i < m;i++){
            int n1 = queries[i][0];
            int n2 = queries[i][1];
            int t1 = next[n1];
            int t2 = next[n2];
            if(n1 == n2) ans[i] = n2;
            else if(heights[n1] < heights[n2] && n1 < n2) ans[i] = n2;
            else if(heights[n2] < heights[n1] && n2 < n1) ans[i] = n1;
            else if(t1 != -1 && t2 != -1){
                  int temp = max(t1,t2);
                 int temp1 = max(heights[n1],heights[n2]);
                 if(temp1 <= heights[temp])
                 ans[i] = temp;
                 else{
                    if((t1 < n2) && (heights[t2] < heights[n1])){
                        int p = -1;
                        int j = n2+1;
                        while(j < n && heights[j] < temp1) j++;
                        if(j >= n) ans[i] = -1;
                        else ans[i] = j;
                    }
                    else ans[i] = -1;
                 }
            }
            else ans[i] = -1;
        }
        return ans;
    }
};
