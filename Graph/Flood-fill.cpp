/*
Definition: The flood fill algorithm is a method for filling a connected region in a grid with a specific color or value. 
It is commonly used in paint bucket tools in graphics editing software.

Input: image = [[1, 1, 1, 0], [0, 1, 1, 1], [1, 0, 1, 1]], sr = 1, sc = 2, newColor = 2
*/

#include<iostream>
#include<vector>
using namespace std;

void recursiveFloodFill(vector<vector<int>> &image,int sr,int sc,int originalColor,int newColor) {
    //base condition
    if((sc<0 || sc>=image[0].size()) || sr<0 || sr>=image.size()) return;
    if(image[sr][sc]!=originalColor || image[sr][sc]==newColor) return;

    image[sr][sc]=newColor;

    recursiveFloodFill(image,sr-1,sc,originalColor,newColor); //up
    recursiveFloodFill(image,sr,sc-1,originalColor,newColor); //left
    recursiveFloodFill(image,sr,sc+1,originalColor,newColor); //right
    recursiveFloodFill(image,sr+1,sc,originalColor,newColor); //down

}

void bfsFloodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int originalColor = image[sr][sc];
    if (originalColor == newColor) return;

    int rows = image.size();
    int cols = image[0].size();
    queue<pair<int, int>> q;
    q.push({sr, sc});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        image[r][c] = newColor;

        // Check all 4 directions
        if (r > 0 && image[r - 1][c] == originalColor) q.push({r - 1, c});
        if (r < rows - 1 && image[r + 1][c] == originalColor) q.push({r + 1, c});
        if (c > 0 && image[r][c - 1] == originalColor) q.push({r, c - 1});
        if (c < cols - 1 && image[r][c + 1] == originalColor) q.push({r, c + 1});
    }
}

int main() {
    vector<vector<int>> image = {{1, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};
    int sr = 1, sc = 2, newColor = 2;

    // Get the original color
    int originalColor = image[sr][sc];

    // Perform the flood fill
    recursiveFloodFill(image, sr, sc, originalColor, newColor);

    // Print the modified image
    for (const auto &row : image) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}