//conway.cpp
#include <vector>
#include "Conway.h"

using namespace std;

namespace Conway{
    vector<vector<Cell>> buildGrid(int width, int height){
        vector<vector<Cell>> grid(height,vector<Cell>(width));
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                grid[i][j].x = i;
                grid[i][j].y = j;
                grid[i][j].is_alive = false;
            }
        }
        return grid;
    }
}