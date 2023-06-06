#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;

//first simple recursion method fails for large test cases.
// int util(vector<int>& nums, int ind){
//     if(ind == 0)
//         return nums[0];
//     if(ind == 1)
//         return max(nums[0],nums[1]);
//     int first = util(nums,ind-1);
//     int second = INT_MIN;
//     if(ind > 1)
//         second = nums[ind] + util(nums,ind-2);
    
//     return max(first,second);
// }
// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     return util(nums,n-1);
// }

//aplying memoization
// int util(vector<int>& nums, int ind,vector<int>& dp){
//     if(ind == 0)
//         return dp[ind] = nums[0];
//     if(ind == 1)
//         return dp[ind] = max(nums[0],nums[1]);
//     if(dp[ind] != -1)
//         return dp[ind];
        
//     int first = util(nums,ind-1,dp);
//     int second = INT_MIN;
//     if(ind > 1)
//         second = nums[ind] + util(nums,ind-2,dp);
    
//     return dp[ind] = max(first,second);
// }
// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     vector<int> dp(n,-1);
//     util(nums,n-1,dp);
//     return dp[n-1];
// }

//using the dp top down approach
//int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     vector<int> dp(n,-1);
//     dp[0] = nums[0];
//     dp[1] = max(nums[0],nums[1]);
//     for(int i=2;i<n;i++){
//         dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
//     }
//     return dp[n-1];
// }


//space opotimization in this
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n,-1);
    int incl = nums[0];
    int excl = 0;
    if(n == 1)
        return incl;
    int ans;
    for(int i=1;i<n;i++){
        ans = max(incl,excl+nums[i]);
        excl = incl;
        incl = ans;
    }
    return ans;
}
