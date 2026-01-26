class Solution {
public:
    int m,n,orig,c;
    vector<vector<int>>* img;
    void dfs(int i,int j){
        if(i<0||j<0||i>=m||j>=n||(*img)[i][j]!=orig) return;
        (*img)[i][j]=c;
        dfs(i+1,j); dfs(i-1,j); dfs(i,j+1); dfs(i,j-1);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        orig=image[sr][sc];
        if(orig==color) return image;
        m=image.size(); n=image[0].size(); c=color; img=&image;
        dfs(sr,sc);
        return image;
    }
};
