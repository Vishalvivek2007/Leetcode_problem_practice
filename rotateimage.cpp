class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len = matrix.size(), temp1, temp2;
        int index = 0;
        while (len > 1) {
            for (int i = index; i < index + len - 1; i++) {
                int offset = i - index; // <-- key fix

                // right
                temp1 = matrix[i][index + len - 1];
                matrix[i][index + len - 1] = matrix[index][i];

                // bottom
                temp2 = matrix[index + len - 1][index + len - 1 - offset];
                matrix[index + len - 1][index + len - 1 - offset] = temp1;

                // left
                temp1 = matrix[index + len - 1 - offset][index];
                matrix[index + len - 1 - offset][index] = temp2;

                // top
                matrix[index][i] = temp1;
            }
            index++;
            len = len - 2;
        }
    }
};