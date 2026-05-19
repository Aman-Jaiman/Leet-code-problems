#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        int m = image.size();
        int n = image[0].size();

        int oldColor = image[sr][sc];

        // If color is already same
        if(oldColor == color) {
            return image;
        }

        vector<vector<int>> vis(m, vector<int>(n, 0));

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        queue<pair<int,int>> q;

        q.push({sr, sc});

        vis[sr][sc] = 1;

        image[sr][sc] = color;

        while(!q.empty()) {

            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;

            for(int i = 0; i < 4; i++) {

                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow >= 0 && nrow < m &&
                   ncol >= 0 && ncol < n &&
                   !vis[nrow][ncol] &&
                   image[nrow][ncol] == oldColor) {

                    vis[nrow][ncol] = 1;

                    image[nrow][ncol] = color;

                    q.push({nrow, ncol});
                }
            }
        }

        return image;
    }
};

int main() {

    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };

    int sr = 1;
    int sc = 1;
    int color = 2;

    Solution obj;

    vector<vector<int>> ans =
        obj.floodFill(image, sr, sc, color);

    for(auto row : ans) {

        for(auto val : row) {

            cout << val << " ";
        }

        cout << endl;
    }

    return 0;
}