class Solution {
public:
    int minOperations(vector<string>& logs) {
        int folderDepth = 0;

        // Iterate through each log operation
        for (const auto& currentOperation : logs) {
            // Go up one directory if "../" is encountered, but don't go above
            // the root
            if (currentOperation == "../") {
                folderDepth = max(0, folderDepth - 1);
            }
            // Increase depth if the log is not 'stay in the current directory
            else if (currentOperation != "./") {
                // Go down one directory
                ++folderDepth;
            }
            // Ignore "./" operations as they don't change the current folder
        }

        return folderDepth;
    }
};