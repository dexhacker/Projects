package MedianOfTwoSortedArrays;

import java.util.Arrays;

public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int firstArrayLength = nums1.length;
        int secondArrayLength = nums2.length;

        int[] fullArray = new int[firstArrayLength + secondArrayLength];
        System.arraycopy(nums1, 0, fullArray, 0, firstArrayLength);
        System.arraycopy(nums2, 0, fullArray, firstArrayLength, secondArrayLength);
        Arrays.sort(fullArray);

        int length = fullArray.length;

        if (length % 2 == 0) {
            int firstIndex = length / 2;
            int secondIndex = firstIndex + 1;

            return (fullArray[firstIndex - 1] + fullArray[secondIndex - 1]) / 2F;
        } else {
            return fullArray[length / 2];
        }
    }
}
