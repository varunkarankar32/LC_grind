class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer,Integer> mp = new HashMap<>();

        mp.put(0,1);
        int n=nums.length;
        int out=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int req= sum-k;
            if(mp.containsKey(req)){
                out += mp.get(req);

            }
            if(mp.containsKey(sum)){
                int freq=mp.get(sum);
                mp.put(sum,freq+1);
            }
            else{
                mp.put(sum,1);
            }

        }
        return out;
    }
}