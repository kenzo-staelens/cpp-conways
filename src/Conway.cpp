//conway.cpp
#include <vector>
#include "Conway.h"

using namespace std;

namespace Conway{
    

    vector<vector<Cell>> buildGrid(int width, int height){
        vector<vector<Cell>> grid(height,vector<Cell>(width));
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                grid[i][j].init(i,j,false);
            }
        }
        return grid;
    }
}