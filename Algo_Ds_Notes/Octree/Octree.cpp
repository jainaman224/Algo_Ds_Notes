#include<iostream>
#include<vector>

#define TLF 0    // top left front
#define TRF 1    // top right front
#define BRF 2    // bottom right front
#define BLF 3    // bottom left front
#define TLB 4    // top left back
#define TRB 5    // top right back
#define BRB 6    // bottom right back
#define BLB 7    // bottom left back

struct Point
{
    int x;
    int y;
    int z;
    Point() : x(-1), y(-1), z(-1) {}
    Point(int a, int b, int c) : x(a), y(b), z(c) {}
};

class Octree
{
    // if point == NULL, node is regional.
    // if point == (-1, -1, -1), node is empty.
    Point *point;

    // represents the space
    Point *top_left_front, *bottom_right_back;  
    std::vector<Octree *> children;
    
public:
    Octree()
    {
        // to declare empty node
        point = new Point();
    }

    Octree(int x, int y, int z)
    {
        // to declare point node
        point = new Point(x, y, z);
    }

    Octree(int x1, int y1, int z1, int x2, int y2, int z2)
    {
        if (x2 < x1 || y2 < y1 || z2 < z1)
            return;
        point = nullptr;
        top_left_front = new Point(x1, y1, z1);
        bottom_right_back = new Point(x2, y2, z2);
        children.assign(8, nullptr);
        for (int i = TLF; i <= BLB; ++i)
            children[i] = new Octree();
    }

    // Insert Function
    void insert(int x, int y, int z)
    {
        if (x < top_left_front -> x || x > bottom_right_back -> x
            || y < top_left_front -> y || y > bottom_right_back -> y
            || z < top_left_front -> z || z > bottom_right_back -> z)
            return;
        int midx = (top_left_front -> x + bottom_right_back -> x) >> 1,
            midy = (top_left_front -> y + bottom_right_back -> y) >> 1,
            midz = (top_left_front -> z + bottom_right_back -> z) >> 1;
        int pos = -1;
        if (x <= midx)
        {
            if (y <= midy)
            {
                if (z <= midz)
                    pos = TLF;
                else
                    pos = TLB;
            }
            else
            {
                if (z <= midz)
                    pos = BLF;
                else
                    pos = BLB;
            }
        }
        else
        {
            if (y <= midy)
            {
                if (z <= midz)
                    pos = TRF;
                else
                    pos = TRB;
            }
            else
            {
                if (z <= midz)
                    pos = BRF;
                else
                    pos = BRB;
            }
        }
        if (children[pos] -> point == nullptr)
        {
            // if region node
            children[pos] -> insert(x, y, z);
            return;
        }
        else if (children[pos] -> point -> x == -1)
        {
            // if empty node
            delete children[pos];
            children[pos] = new Octree(x, y, z);
            return;
        }
        else
        {
            int x_ = children[pos] -> point -> x,
                y_ = children[pos] -> point -> y,
                z_ = children[pos] -> point -> z;
            delete children[pos];
            children[pos] = nullptr;
            if (pos == TLF)
            {
                children[pos] = new Octree(top_left_front -> x, top_left_front -> y, top_left_front -> z,
                                        midx, midy, midz);
            }
            else if (pos == TRF)
            {
                children[pos] = new Octree(midx + 1, top_left_front -> y, top_left_front -> z,
                                        bottom_right_back -> x, midy, midz);
            }
            else if (pos == BRF)
            {
                children[pos] = new Octree(midx + 1, midy + 1, top_left_front -> z,
                                        bottom_right_back -> x, bottom_right_back -> y, midz);
            }
            else if (pos == BLF)
            {
                children[pos] = new Octree(top_left_front -> x, midy + 1, top_left_front -> z,
                                        midx, bottom_right_back -> y, midz);
            }
            else if (pos == TLB)
            {
                children[pos] = new Octree(top_left_front -> x, top_left_front -> y, midz + 1,
                                        midx, midy, bottom_right_back -> z);
            }
            else if (pos == TRB)
            {
                children[pos] = new Octree(midx + 1, top_left_front -> y, midz + 1,
                                        bottom_right_back -> x, midy, bottom_right_back -> z);
            }
            else if (pos == BRB)
            {
                children[pos] = new Octree(midx + 1, midy + 1, midz + 1,
                                        bottom_right_back -> x, bottom_right_back -> y, bottom_right_back -> z);
            }
            else if (pos == BLB)
            {
                children[pos] = new Octree(top_left_front -> x, midy + 1, midz + 1,
                                        midx, bottom_right_back -> y, bottom_right_back -> z);
            }
            children[pos] -> insert(x_, y_, z_);
            children[pos] -> insert(x, y, z);
        }
    }
    
    // Find Function
    bool find(int x, int y, int z)
    {
        if (x < top_left_front -> x || x > bottom_right_back -> x
            || y < top_left_front -> y || y > bottom_right_back -> y
            || z < top_left_front -> z || z > bottom_right_back -> z)
            return 0;
        int midx = (top_left_front -> x + bottom_right_back -> x) >> 1,
            midy = (top_left_front -> y + bottom_right_back -> y) >> 1,
            midz = (top_left_front -> z + bottom_right_back -> z) >> 1;
        int pos = -1;
        if (x <= midx)
        {
            if (y <= midy)
            {
                if (z <= midz)
                    pos = TLF;
                else
                    pos = TLB;
            }
            else
            {
                if (z <= midz)
                    pos = BLF;
                else
                    pos = BLB;
            }
        }
        else
        {
            if (y <= midy)
            {
                if (z <= midz)
                    pos = TRF;
                else
                    pos = TRB;
            }
            else
            {
                if (z <= midz)
                    pos = BRF;
                else
                    pos = BRB;
            }
        }
        if (children[pos] -> point == nullptr)
        {
           // if region node
            return children[pos] -> find(x, y, z);
        }
        else if (children[pos] -> point -> x == -1)
        {
            // if empty node
            return 0;
        }
        else
        {
            if (x == children[pos] -> point -> x && y == children[pos] -> point -> y
                && z == children[pos] -> point -> z)
                return 1;
        }
        return 0;
    }
};

int main() 
{
    Octree tree(1, 1, 1, 4, 4, 4);
    std::cout << "Insert (3, 3, 3)" << endl;
    tree.insert(3, 3, 3);
    std::cout << "Insert (3, 3, 4)" << endl;
    tree.insert(3, 3, 4);
    std::cout << "Find (3, 3, 3):" << endl;
    std::cout << (tree.find(3, 3, 3) ? "True\n" : "False\n");
    std::cout << "Find (3, 4, 4):" << endl;
    std::cout << (tree.find(3, 4, 4) ? "True\n" : "False\n");
    std::cout << "Insert (3, 4, 4)" << endl;
    tree.insert(3, 4, 4);
    std::cout << "Find (3, 4, 4):" << endl;
    std::cout << (tree.find(3, 4, 4) ? "True\n" : "False\n");
    return 0;
}

/* Output:

Insert (3, 3, 3)                                                                                                        
Insert (3, 3, 4)                                                                                                        
Find (3, 3, 3):                                                                                                         
True                                                                                                                    
Find (3, 4, 4):                                                                                                         
False                                                                                                                   
Insert (3, 4, 4)  
Find (3, 4, 4):                                                                                                         
True  

*/
