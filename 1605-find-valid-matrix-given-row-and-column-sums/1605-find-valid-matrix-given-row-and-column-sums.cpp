class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        int N = rowSum.size();
        int M = colSum.size();

        vector<int> currRowSum(N, 0);
        vector<int> currColSum(M, 0);

        vector<vector<int>> origMatrix(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                origMatrix[i][j] =
                    min(rowSum[i] - currRowSum[i], colSum[j] - currColSum[j]);

                currRowSum[i] += origMatrix[i][j];
                currColSum[j] += origMatrix[i][j];
            }
        }
        return origMatrix;
    }
};