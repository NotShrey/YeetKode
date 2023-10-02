class Solution {
    
private:
    int bs(vector<int>& row, int target){
        int low = 0, high = row.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (row[mid] == target) {
                return mid;
            } else if (row[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return -1; // Return -1 to indicate that the target was not found
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        
        for (int i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] <= target && target <= matrix[i][matrix[i].size() - 1]) {
                int result = bs(matrix[i], target);
                if (result != -1) {
                    return true;
                }
            }
        }
        
        return false;
    }
};








// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         for(int i  = 0; i<matrix.size(); ++i)
//         {
//             for(int j = 0; j<matrix[0].size(); ++j)
//             {
//                 if(matrix[i][j] == target)
//                     return true;
//             }
//         }
//         return false;
//     }
	
// };