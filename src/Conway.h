//conway.h

#include <vector>
using namespace std;

namespace Conway{
    struct Cell{
        unsigned int x,y;
        bool is_alive;//int *neighbours[8];
        Cell(){}
    };

    vector<vector<Cell>> buildGrid(int width, int height);
}