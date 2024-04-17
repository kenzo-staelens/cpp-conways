//main.cpp
#include <unistd.h>
#include <iostream>
#include "Conway.cpp"

using namespace Conway;
using namespace std;
namespace {
    int grid_width = 10;
    int grid_height = 10;
}

void print_divider(int width){
    cout << endl;
    for(int _ = 0;_<width;_++){ cout << "+---";}
    cout << "+" << endl;
}

int num_neighbours(vector<vector<Cell>> &grid, int x, int y){
    int neighbours = 0;
    for(int i=max(0,y-1);i<=min((int)grid.size()-1,y+1);i++){
        for(int j=max(0,x-1);j<=min((int)grid[i].size()-1,x+1);j++){
            if(grid[i][j].is_alive){
                neighbours++;
            }
        }
    }
    neighbours -= grid[y][x].is_alive;
    return neighbours;
}

bool rule(vector<vector<Cell>> &grid, int x, int y){
    int _num_neighbours = num_neighbours(grid, x, y);
    if(_num_neighbours==3 || (_num_neighbours==2 && grid[y][x].is_alive)) return true;
    return false;
}

void print_array(vector<vector<Cell>> grid, unsigned int width, unsigned int height){
    print_divider(width);
    for(long long unsigned int y = 0; y < grid.size(); y++) {
        cout << "| ";
        for(long long unsigned int x = 0; x < grid[0].size(); x++) {
            Cell cell = grid[y][x];
            if(cell.is_alive){
                cout << "x" << " | ";
            }
            else{
                cout << " " << " | ";
            }
        }
        print_divider(width);
    }
}

void move_grid_top(int height){
    for(int _=0;_<(height*2+1)+1;_++){
        cout<<"\33[1A";
    }
}

void GameOfLife(vector<vector<Cell>>& grid, vector<vector<Cell>> &swapgrid){
    for(long long unsigned int y = 0; y < grid.size(); y++) {
        for(long long unsigned int x = 0; x < grid[0].size(); x++) {
            swapgrid[y][x].is_alive=rule(grid,x,y);
        }
    }
    vector<vector<Cell>> temp;
    temp = swapgrid;
    swapgrid = grid;
    grid = temp;
}


void setGlider(vector<vector<Cell>> &grid){
    if(grid.size()<3 || grid[0].size()<3){
        throw invalid_argument("grid too small (minimum 3x3)");
    }
    grid[0][1].is_alive = true;
    grid[1][2].is_alive = true;
    grid[2][0].is_alive = true;
    grid[2][1].is_alive = true;
    grid[2][2].is_alive = true;
    return;
}

int main() {
    cout << "grid width: ";
    cin >> grid_width;
    cout << "grid height: ";
    cin >> grid_height;

    vector<vector<Cell>> grid = buildGrid(grid_width, grid_height);
    vector<vector<Cell>> swap = buildGrid(grid_width, grid_height);
    
    setGlider(grid);
    print_array(grid, grid_width, grid_height);
    while(true){
        move_grid_top(grid_height);
        print_array(grid, grid_width, grid_height);
        GameOfLife(grid,swap);
        usleep(200*1000);  
    }
    grid.clear();
    swap.clear();
    return 0;
}