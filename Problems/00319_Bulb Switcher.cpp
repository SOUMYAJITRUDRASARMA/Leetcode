class Solution {
public:
    int bulbSwitch(int n) {
        /* after all iterations we observe that bulbs which are still on are perfect squares,
        this implies no. of bulbs still on at end will be no. of perfect squares present in n, i.e sqrt of n
        this is because -> ONLY PERFECT SQUARES HAVE ODD NUMBER OF FACTORS (for num n^2 -> (n, n) is a unique pair with only 1 factor 'n' contributing)
        ALL OTHER NUMBERS HAVE EVEN NUMBER OF FACTORS OCCURRING IN PAIRS (eq :- for num p1*p2 -> (p1, p2) contributes p1 & p2 - 2 factors) */

        return sqrt(n);
    }
};
