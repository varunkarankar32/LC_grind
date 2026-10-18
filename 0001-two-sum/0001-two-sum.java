class Solution {
    public int[] twoSum(int[] nums, int target) {
   
        int n=nums.length;
        int lo=0;
        int hi=n-1;
        int []out = new int[2];
        Map<Integer,Integer> mp = new HashMap<>();
        for(int i=0;i<n;i++){
            int req=target-nums[i];
            if(mp.containsKey(req)){
                out[0]=mp.get(req);
                out[1]=i;
                return out;
            }
            else{
                mp.put(nums[i],i);
            }
        }
        return out;

        
    }
}