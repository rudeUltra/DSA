class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int start = 0;

        while (start <words.size()) {
            int end = start;
            int lineLength = words[end].length();

            while (end + 1 < words.size() && lineLength + words[end + 1].length() + (end + 1 - start) <= maxWidth) {
                ++end;
                lineLength += words[end].length();
            }

            string line = words[start];
            int numWords = end - start;

            if (end == words.size() - 1 || numWords == 0) { // Left justify for last line or single word line
                for (int i = start + 1; i <= end; ++i) {
                    line += " " + words[i];
                }
                line += string(maxWidth - line.length(), ' ');
            } else {
                int totalSpaces = maxWidth - lineLength;
                int spacesBetweenWords = totalSpaces / numWords;
                int extraSpaces = totalSpaces % numWords;

                for (int i = start + 1; i <= end; ++i) {
                    int spaces = spacesBetweenWords + (extraSpaces-- > 0 ? 1 : 0);
                    line += string(spaces, ' ') + words[i];
                }
            }

            result.push_back(line);
            start = end + 1;
        }

        return result;
    }
};