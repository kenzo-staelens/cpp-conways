//conway.h

#include <vector>
using namespace std;

namespace Conway{
    struct Cell{
        unsigned int x,y;
        bool is_alive;//int *neighbours[8];
        void init(unsigned int x, unsigned int y, bool is_alive){
            this->x = x;
            this->y = y;
            this->is_alive = is_alive;
        }
    };

    vector<vector<Cell>> buildGrid(int width, int height);
}