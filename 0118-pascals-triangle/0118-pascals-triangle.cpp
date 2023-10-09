class Solution {
public:
    vector<int> genrateRow(int row){
        long long ans =1;
        vector<int> arr;
        arr.push_back(1);
        for(int i=1;i<row;i++){
            ans = ans * (row-i);
            ans = ans/i;
            arr.push_back(ans);
        }
        return arr;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> arr;
        
        for(int i=1;i<=numRows;i++){
             arr.push_back(genrateRow(i));
        }
        return arr;
    }
};

    
    
    

   // for(int i = 0;i<numRows.size();i++){
   //          cout<<(generate(n -1),(c-1));
   //      }