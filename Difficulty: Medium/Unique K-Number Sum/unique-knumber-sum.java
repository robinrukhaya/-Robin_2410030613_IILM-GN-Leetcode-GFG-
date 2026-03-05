import java.util.*;

class Solution {

    public ArrayList<ArrayList<Integer>> combinationSum(int n, int k) {
        
        ArrayList<ArrayList<Integer>> result = new ArrayList<>();
        
        backtrack(1, k, n, new ArrayList<>(), result);
        
        return result;
    }

    void backtrack(int start, int k, int sum,
                   ArrayList<Integer> list,
                   ArrayList<ArrayList<Integer>> result) {

        if(list.size() == k && sum == 0){
            result.add(new ArrayList<>(list));
            return;
        }

        for(int i = start; i <= 9; i++){

            if(i > sum) break;

            list.add(i);

            backtrack(i + 1, k, sum - i, list, result);

            list.remove(list.size() - 1); // backtrack
        }
    }
}