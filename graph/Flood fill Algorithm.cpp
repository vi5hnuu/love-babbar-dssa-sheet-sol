/*
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image.

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

Example 1:

Input: image = {{1,1,1},{1,1,0},{1,0,1}},
sr = 1, sc = 1, newColor = 2.
Output: {{2,2,2},{2,2,0},{2,0,1}}
Explanation: From the center of the image 
(with position (sr, sc) = (1, 1)), all 
pixels connected by a path of the same color
as the starting pixel are colored with the new 
color.Note the bottom corner is not colored 2, 
because it is not 4-directionally connected to 
the starting pixel.
 

Your Task:
You don't need to read or print anyhting. Your task is to complete the function floodFill() which takes image, sr, sc and newColor as input paramater and returns the image after flood filling.
 

Expected Time Compelxity: O(n*m)
Expected Space Complexity: O(n*m)
 

Constraints:
1 <= n <= m <= 100
0 <= pixel values <= 10
0 <= sr <= (n-1)
0 <= sc <= (m-1)
*/


//BFS
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> newImage=image;
        if(newColor==image[sr][sc]){
            return newImage;
        }
        int rows=image.size();
        int cols=image[0].size();
        queue<pair<int,int>> nodes;
        nodes.push({sr,sc});
        newImage[sr][sc]=newColor;
        
        int x[4]={0,0,-1,1};
        int y[4]={1,-1,0,0};
        while(!nodes.empty()){
            int sz=nodes.size();
            
            while(sz>0){
                sz--;
                auto pos=nodes.front();
                nodes.pop();
                
                for(int i=0;i<4;i++){
                    int xi=pos.first+x[i];
                    int xj=pos.second+y[i];
                    if(xi>=0 && xi<rows && xj>=0 && xj<cols && newImage[xi][xj]==image[sr][sc]){
                        newImage[xi][xj]=newColor;
                        nodes.push({xi,xj});
                    }
                }
            }
        }
        return newImage;
    }
};

////////////////////////////
// class Solution {
// private://dfs
//     void  dfs(int sr,int sc,vector<vector<int>> &newImage,int &oColor,int &newColor,int &rows,int &cols){
//         if(sr<0 || sc<0 || sr>=rows || sc>=cols || newImage[sr][sc]!=oColor){
//             return;
//         }
//         newImage[sr][sc]=newColor;
//         dfs(sr,sc+1,newImage,oColor,newColor,rows,cols);
//         dfs(sr,sc-1,newImage,oColor,newColor,rows,cols);
//         dfs(sr+1,sc,newImage,oColor,newColor,rows,cols);
//         dfs(sr-1,sc,newImage,oColor,newColor,rows,cols);
//     }
// public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
//         vector<vector<int>> newImage=image;
//         if(newColor==image[sr][sc]){
//             return newImage;
//         }
//         int rows=image.size();
//         int cols=image[0].size();
//         dfs(sr,sc,newImage,image[sr][sc],newColor,rows,cols);
//         return newImage;
//     }
// };