class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        return ceil((double)log(buckets) / (double)log(minutesToTest/minutesToDie + 1));
    }
};  