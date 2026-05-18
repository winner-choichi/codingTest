/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long int i = n;
        long long int lower_bound = 1, upper_bound = 2147483647;
        while(1) {
            if (guess(i) == -1 ) {
                upper_bound = i;
                i = (lower_bound + upper_bound) / 2;
            }
            else if (guess(i) == 1) {
                lower_bound = i;
                i = (lower_bound + upper_bound) / 2;
            }
            else if (guess(i) == 0) return i;
        }
        
    }
};

