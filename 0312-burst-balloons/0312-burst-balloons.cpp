class Solution {
public:
    vector<vector<int>>dp;
    int solve(int lo,int hi,vector<int>&nums)
    {
        if(lo>=hi){
            return 0;
        }
        if(dp[lo][hi]!=-1){
            return dp[lo][hi];
        }
        int maxi=0;

        for(int k=lo+1;k<=hi-1;k++){
            maxi=max(maxi,solve(lo,k,nums)+solve(k,hi,nums)+nums[k]*nums[lo]*nums[hi]);

        }
        return dp[lo][hi]=maxi;


    }

    int maxCoins(vector<int>& nums) {
        vector<int>newnums;
        newnums.push_back(1);
        for(auto x:nums){
            newnums.push_back(x);
        }
        newnums.push_back(1);
        int n=newnums.size();
        dp.resize(n,vector<int>(n,-1));
        return solve(0,n-1,newnums);
        
    }
};