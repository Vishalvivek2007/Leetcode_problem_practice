class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int max = 0;
        for (int pile : piles) {
            if (pile > max) {
                max = pile;
            }
        }

        int left = 1, right = max, ans = max;
        while (left <= right) {
            int k = left + (right - left) / 2;
            if (canEatAll(piles, h, k)) {
                ans = k;
                right = k - 1;
            } else {
                left = k + 1;
            }
        }
        return ans;
    }

    boolean canEatAll(int[] piles, int h, int k) {
        long hoursNeeded = 0;
        for (int pile : piles) {
            hoursNeeded += (pile + k - 1) / k;
        }
        return hoursNeeded <= h;
    }
}