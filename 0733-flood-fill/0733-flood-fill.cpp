class Solution {
public:
    void dfs(vector<vector<int>>& image,int row, int col, int originalColor, int newColor){
        if(row <0 || row >= image.size() || col < 0 || col >= image[0].size()){
            return;
        } 
        if(image[row][col] != originalColor){
            return;
        }
        image[row][col] = newColor;
        dfs(image, row - 1, col, originalColor, newColor); 
        dfs(image, row + 1, col, originalColor, newColor); 
        dfs(image, row, col - 1, originalColor, newColor); 
        dfs(image, row, col + 1, originalColor, newColor); 
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if(originalColor == color){
            return image;
        }
        dfs(image, sr,sc, originalColor, color); 
        return image;    
    }
    
};