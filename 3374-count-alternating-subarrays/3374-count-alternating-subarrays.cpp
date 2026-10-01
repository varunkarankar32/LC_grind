class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long sum=0;
        int curr=0;
        int n=nums.size();
        int prev=1-nums[0];
        for(int i=0;i<n;i++){
            if(nums[i]==1-prev){
                curr++;
                prev=nums[i];
            }
            else{
                sum+= (1LL*curr*(curr+1)/2);
                curr=1;
                prev=nums[i];
            }


        }
        sum+= (1LL*curr*(curr+1)/2);
        return sum;
        
    }
};