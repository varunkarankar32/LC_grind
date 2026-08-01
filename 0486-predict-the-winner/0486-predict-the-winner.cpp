class Solution {
public:
   long long solve(int lo,int hi,vector<int>&nums){
        if(lo>hi){
            return 0;
        }
       long long takelo=nums[lo]+min(solve(lo+2,hi,nums),solve(lo+1,hi-1,nums));
    long long takehi=nums[hi]+min(solve(lo+1,hi-1,nums),solve(lo,hi-2,nums));
        return max(takelo,takehi);

    }
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        return sum<=2*solve(0,n-1,nums);
        
    }
};