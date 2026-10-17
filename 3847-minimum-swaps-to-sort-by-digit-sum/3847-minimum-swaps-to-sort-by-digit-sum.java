
class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;

        Integer[][] pairarray = new Integer[n][2];

        for (int i = 0; i < n; i++) {
            int m = nums[i];
            int sum = 0;

            while (m != 0) {
                sum += m % 10;
                m /= 10;
            }

            pairarray[i][0] = sum;
            pairarray[i][1] = nums[i];
        }

        Arrays.sort(pairarray, (a, b) -> {
            if (!a[0].equals(b[0])) {
                return Integer.compare(a[0], b[0]);
            }
            return Integer.compare(a[1], b[1]);
        });

        // Map each original element to its sorted position.
        Map<Integer, Integer> position = new HashMap<>();

        for (int i = 0; i < n; i++) {
            position.put(pairarray[i][1], i);
        }

        boolean[] visited = new boolean[n];
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || position.get(nums[i]) == i) {
                continue;
            }

            int cycleSize = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = position.get(nums[j]);
                cycleSize++;
            }

            swaps += cycleSize - 1;
        }

        return swaps;
    }
}
