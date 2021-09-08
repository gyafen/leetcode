public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int first = 0;
        int second = 0;
        boolean flag = false;


        while (first < numbers.length){
            second = first+1;
            int halfTarget = target-numbers[first];

            int left = second;
            int right = numbers.length-1;
            int middle = 0;

            while (left <= right){
                middle = (left+right)/2;
                if(numbers[middle] == halfTarget){
                    flag = true;
                    break;
                }
                else if(numbers[middle] < halfTarget){
                    left = middle+1;
                }
                else if(numbers[middle] > halfTarget){
                    right = middle-1;
                }
            }

            if(flag == true){
                second = middle;
                break;
            }
            first++;
        }

        return new int[]{first+1, second+1};
    }
}
