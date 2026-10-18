class Solution {
    public int maxSubArray(int[] nums) {
        int maximum=nums[0];
        int n=nums.length;
        int curr=0;
        for(int i=0;i<n;i++){
            curr = Math.max(nums[i],curr+nums[i]);
            maximum=Math.max(maximum,curr);

        }
        return maximum;
    }
}