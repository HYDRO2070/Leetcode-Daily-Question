class Solution {
public:
    vector<int> minOperations(string boxes) {
        // brute froce
        // int n = boxes.size();
        // vector<int> res(n,0);
        // for(int i = 0;i < n;i++){
        //     int ans = 0;
        //     for(int j = 0;j < n;j++){
        //         if(i == j || boxes[j] == '0') continue;
        //         if(i < j){
        //             ans += j - i;
        //         }
        //         else{
        //             ans += i - j;
        //         }
        //     }
        //     res[i] = ans;
        // }
        // return res;

        // optimize way
        // int n = boxes.size();
        // vector<int> left(n,0);
        // int count = 0;

        // for(int i = 1;i < n;i++){
        //     if(boxes[i-1] == '1') count += 1;
        //     left[i] += left[i-1] + count;
        // }

        // count = 0;
        // int prev = 0;

        // for(int i = n-2;i >= 0;i--){
        //     if(boxes[i+1] == '1') count += 1;
        //     int curr = prev + count;
        //     left[i] += curr;
        //     prev = curr;
        // }
        // return left;

        // space optimize way
        vector<int> left(boxes.size(), 0);
        int count = 0;
        int temp = 0;
        for (int i = 0; i < boxes.size(); i++) {
            left[i] += temp;
            if (boxes[i] == '1')
                count += 1;
            temp += count;
        }

        count = 0;
        temp = 0;

        for (int i = boxes.size() - 1; i >= 0; i--) {
            left[i] += temp;
            if (boxes[i] == '1')
                count += 1;
            temp += count;
        }
        return left;
    }
};
