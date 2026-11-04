class Solution {
    public List<List<Integer>> powerSet(int[] nums) {
        int n = nums.length;
        List<List<Integer>> ans = new ArrayList<>();


        int count = (1 << n);

        for(int val =0 ; val < count ; val++){
            List<Integer> subset= new ArrayList<>();
            for (int i = 0; i < n; i++) {
                if ((val & (1 << i)) != 0) {
                    subset.add(nums[i]);
                }
            }
            ans.add(subset);
        }
        return ans;
    }

    public static void main(String[] args){
        int[] nums = {1,2,3};
        Solution sol = new Solution();
        List<List<Integer>> ans = sol.powerSet(nums);
        ans.sort(Comparator.comparingInt(List :: size));

        System.out.println("The power set for the given array is: ");

        for(List<Integer> subset : ans){
            for(int num : subset){
                System.out.print(num + " ");
            }
            System.out.println();
        }
    }
}