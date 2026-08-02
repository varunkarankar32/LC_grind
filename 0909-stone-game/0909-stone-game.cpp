class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>&piles,int lo,int hi){
        if(lo>hi){
            return 0;
        }
        if(dp[lo][hi]!=-1){
            return dp[lo][hi];
        }
        int left=piles[lo]+min(solve(piles,lo+2,hi),solve(piles,lo+1,hi-1));
        int right=piles[hi]+min(solve(piles,lo+1,hi-1),solve(piles,lo,hi-2));
        return dp[lo][hi]=max(left,right);

    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.resize(n,vector<int>(n,-1));
        int result=solve(piles,0,n-1);
        int totalsum=accumulate(piles.begin(),piles.end(),0);
        return totalsum< 2*result;

    }
};