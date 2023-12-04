class Solution {
public:
    string largestGoodInteger(string num) {
        // Assign 'maxDigit' to the NUL character (smallest ASCII value character)
        char maxDigit = '\0';

        // Iterate on characters of the num string.
        for (int index = 0; index <= num.size() - 3; ++index) {
            // If 3 consecutive characters are the same,
            // store the character in 'maxDigit' if bigger than what it already stores.
            if (num[index] == num[index + 1] && num[index] == num[index + 2]) {
                maxDigit = max(maxDigit, num[index]);
            }
        }

        // If 'maxDigit' is NUL return an empty string, otherwise string of size 3 with 'maxDigit' characters.
        return maxDigit == '\0' ? "" : string(3, maxDigit);
    }
};