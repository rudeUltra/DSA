class Solution {
public:
    int findTheWinner(int n, int k) {
        // Initialize queue with n friends
        queue<int> circle;
        for (int i = 1; i <= n; i++) {
            circle.push(i);
        }

        // Perform eliminations while more than 1 player remains
        while (circle.size() > 1) {
            // Process the first k-1 friends without eliminating them
            for (int i = 0; i < k - 1; i++) {
                circle.push(circle.front());
                circle.pop();
            }
            // Eliminate the k-th friend
            circle.pop();
        }

        return circle.front();
    }
};