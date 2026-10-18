class Solution {
    public int pivotIndex(int[] nums) {
        int n=nums.length;
        Integer []suffixsum = new Integer[n];
        Integer sum=0;
        for(int i=n-1;i>=0;i--){
            suffixsum[i]=sum;
            sum+=nums[i];
        }
        int prefsum=0;
        for(int i=0;i<n;i++){
            if(prefsum==suffixsum[i]){
                return i;
            }
            prefsum+=nums[i];
        }
        return -1;

        
    }
}