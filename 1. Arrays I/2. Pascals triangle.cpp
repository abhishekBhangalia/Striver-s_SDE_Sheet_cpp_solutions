class Solution {
public:

    //TC-O(n!), SC-O(n!)
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back({1});
        if(numRows == 1){
            return triangle;
        }
        triangle.push_back({1,1});
        if(numRows == 2){
            return triangle;
        }

        int columns = 2;
        for(int row=2; row<numRows; row++){
            columns++;
            vector<int> arr(columns);
            arr[0] = arr[columns-1] = 1;
            for(int col=1; col<columns-1; col++){
                arr[col] = triangle[row-1][col-1]+triangle[row-1][col];
            }
            triangle.push_back(arr);
        }
        return triangle;
    }
};
