class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        for(int i = 0;i < arr.size();i++){
            if(i+1 < arr.size())
            arr[i+1] += arr[i];
            if(arr[i] == (i*(i+1))/2){
                ans++;
            }
        }
        return ans;
    }
};
