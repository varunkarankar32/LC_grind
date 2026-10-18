class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n=nums.length;
        int []prefixsum = new int[n+1];
        int minlength=1000000;
        prefixsum[0]=0;
        prefixsum[1]=nums[0];
        for(int i=2;i<=n;i++){
            prefixsum[i]=nums[i-1]+prefixsum[i-1];
        }

        for(int i=1;i<=n;i++){
            int req=prefixsum[i]-target;
            int lo=0;
            int hi=i-1;
            int ans=-1;
            int mid;
            while(lo<=hi){
                mid = lo+ (hi-lo)/2;
                if(prefixsum[mid]<=req){
                    ans=mid;
                    lo=mid+1;
                }
                else{
                    hi=mid-1;
                }
            }
            if(ans!=-1){
                minlength = Math.min(minlength,i-ans);
            }

        }
        return (minlength==1000000)?0:minlength;
        
    }
}