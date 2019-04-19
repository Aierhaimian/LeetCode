#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;
// If you are familiar with image processing, this problem can be seen as edge detection. (It wouldn't work if there are laked in the middle of the island.)
// For a typical edge detection, for a given pixel central (c), we need to look at all the directly adjacent pixels, north (n), west (w), south (s), east (e), the edge is defined as
// edge = 4*central - (north+west+south+east)
// So we can run through all the 1's and calculate the total number of edges.
// One problem left: how to deal with boundaries? We set them 0.
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int len = grid.size();
        int wid = grid[0].size();
        int edge = 0, e = 0, w = 0, s = 0, n = 0;

        for (int i=0; i<len; i++)
            for (int j=0; j<wid; j++) {
                if (grid[i][j]) {
                    n = (i > 0) ? grid[i-1][j] : 0;
                    w = (j > 0) ? grid[i][j-1] : 0;
                    e = (j < wid-1) ? grid[i][j+1] : 0;
                    s = (i < len-1) ? grid[i+1][j] : 0;

                    edge += 4*grid[i][j] - (n+w+e+s);
                }
            }
        return edge;
    }
};

int main()
{
    vector<vector<int>> island = {{0,1,0,0},
                                  {1,1,1,0},
                                  {0,1,0,0},
                                  {1,1,0,0}};
    cout << Solution().islandPerimeter(island) << endl;

    return 0;
}

