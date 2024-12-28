// typedef tuple<int, int, int> State;
// class Solution {
// private:
//     string stateToString(const State& state) {
//         return to_string(get<0>(state)) + "," + to_string(get<1>(state)) + "," +
//                to_string(get<2>(state));
//     }

//     void solveMemo(vector<int>& nums, vector<int>& res, int& k, int pos,
//                    vector<int> ans, int sum, int& maxi,
//                    unordered_map<string, int>& memo) {
//         int n = nums.size();
//         if (pos > n - k || ans.size() == 3) {
//             if (sum > maxi && ans.size() == 3) {
//                 res = ans;
//                 maxi = sum;
//             }
//             return;
//         }

//         State currentState = make_tuple(pos, ans.size(), sum);
//         string stateKey = stateToString(currentState);

        
//         if (memo.find(stateKey) != memo.end() && memo[stateKey] >= sum) {
//             return;
//         }

        
//         memo[stateKey] = sum;

//         for (int index = pos; index <= n - k; index++) {
//             int temp = 0;
//             for (int j = index; j < index + k; j++)
//                 temp += nums[j];
//             if (index + k == n) {
//                 ans.push_back(index);
//                 solveMemo(nums, res, k, index + k, ans, sum + temp, maxi, memo);
//                 ans.pop_back();
//             } else {
//                 for (int i = index + k; i < n; i++) {
//                     ans.push_back(index);
//                     solveMemo(nums, res, k, i, ans, sum + temp, maxi, memo);
//                     ans.pop_back();
//                 }
//             }
//         }
//     }

// public:
//     vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
//         int maxi = INT_MIN;
//         vector<int> res;
//         unordered_map<string, int> memo;
//         solveMemo(nums, res, k, 0, {}, 0, maxi, memo);
//         return res;
//     }
// };



// typedef tuple<int, int, int> State;

// class Solution {
// private:
//     // Optimized memoization using unordered_map with tuple as key
//     struct TupleHash {
//         template <class T1, class T2, class T3>
//         size_t operator()(const tuple<T1, T2, T3>& t) const {
//             auto h1 = hash<T1>{}(get<0>(t));
//             auto h2 = hash<T2>{}(get<1>(t));
//             auto h3 = hash<T3>{}(get<2>(t));
//             return h1 ^ (h2 << 1) ^ (h3 << 2);
//         }
//     };

//     void solveMemo(vector<int>& nums, vector<int>& res, int& k, int pos,
//                    vector<int>& ans, int sum, int& maxi,
//                    unordered_map<State, int, TupleHash>& memo) {
//         int n = nums.size();
//         if (pos > n - k || ans.size() == 3) {
//             if (sum > maxi && ans.size() == 3) {
//                 res = ans;
//                 maxi = sum;
//             }
//             return;
//         }

//         State currentState = make_tuple(pos, ans.size(), sum);

//         if (memo.find(currentState) != memo.end() && memo[currentState] >= sum) {
//             return;
//         }

//         memo[currentState] = sum;

//         for (int index = pos; index <= n - k; index++) {
//             int temp = 0;
//             for (int j = index; j < index + k; j++)
//                 temp += nums[j];

//             ans.push_back(index);
//             solveMemo(nums, res, k, index + k, ans, sum + temp, maxi, memo);
//             ans.pop_back();
//         }
//     }

// public:
//     vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
//         int maxi = INT_MIN;
//         vector<int> res;
//         unordered_map<State, int, TupleHash> memo;
//         vector<int> ans;
//         solveMemo(nums, res, k, 0, ans, 0, maxi, memo);
//         return res;
//     }
// };


class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> kSum(n - k + 1, 0);
        int currentSum = 0;
        for (int i = 0; i < n; ++i) {
            currentSum += nums[i];
            if (i >= k - 1) {
                kSum[i - k + 1] = currentSum;
                currentSum -= nums[i - k + 1];
            }
        }

        vector<int> leftBest(n - k + 1, 0);
        vector<int> rightBest(n - k + 1, n - k);

        for (int i = 1; i <= n - k; ++i) {
            leftBest[i] = (kSum[i] > kSum[leftBest[i - 1]]) ? i : leftBest[i - 1];
        }

        for (int i = n - k - 1; i >= 0; --i) {
            rightBest[i] = (kSum[i] >= kSum[rightBest[i + 1]]) ? i : rightBest[i + 1];
        }

        vector<int> result(3, 0);
        int maxSum = INT_MIN;
        for (int mid = k; mid <= n - 2 * k; ++mid) {
            int left = leftBest[mid - k];
            int right = rightBest[mid + k];
            int totalSum = kSum[left] + kSum[mid] + kSum[right];
            if (totalSum > maxSum) {
                maxSum = totalSum;
                result = {left, mid, right};
            }
        }

        return result;
    }
};
