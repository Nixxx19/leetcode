class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orig=image[sr][sc];
        if(orig==color) return image;
        int m=image.size(), n=image[0].size();
        stack<pair<int,int>> st;
        st.push({sr,sc});
        image[sr][sc]=color;
        int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
        while(!st.empty()){
            auto [x,y]=st.top(); st.pop();
            for(auto& k:d){
                int nx=x+k[0], ny=y+k[1];
                if(nx>=0&&ny>=0&&nx<m&&ny<n&&image[nx][ny]==orig){
                    image[nx][ny]=color;
                    st.push({nx,ny});
                }
            }
        }
        return image;
    }
};
