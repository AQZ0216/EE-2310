#include <iostream>

using namespace std;

struct Cell//define a Cell structure to record a cell
{
    int door[4];//declare an 4 integer array to record the door N,E,S,W respectively
};

class Maze//define a class Maze to record the whole maze
{
private:
    int m, n;//declare two integer to record the length and width
    int *path;//declare a pointer to record the path
public:
    Cell *c;//declare a Cell structure to record the maze's cells
    int min = 0;//declare an integer to record the shortest path's length
    int *min_path;//declare a pointer to record the shortest path
    Maze(int M, int N);//class Maze's constuctor
    int inconsistent();//to check whether the maze is inconsistent
    void find_path(int x, int y, int length);//to find the path
};

Maze::Maze(int M, int N)//class Maze's constuctor
{
    m = M;//set class member "m" as input "M"
    n = N;//set class member "n" as input "N"
    path = new int[m*n];//allocate "path" to record an m*n 2D array
    for(int i = 0; i < m*n; i++)//reset "path"
    {
        *(path+i) = 0;
    }
    min_path = new int[m*n];//allocate "path" to record an m*n 2D array
    c = new Cell[m*n];//allocate "c" to record an m*n 2D array
}

int Maze::inconsistent()//to check whether the maze is inconsistent
{
    for(int i = 0; i < m*n-n; i++)
    {
        if( (c+i)->door[2] != (c+i+n)->door[0] )//if the upper cell's South door is consist with the lower cell's North door
        {
            cout << "Input Error! (" << i/n+1 << "," << i%n+1 << ") and (" << i/n+2 << "," << i%n+1 << ") are inconsistent." << endl;
            //print "Input Error! ( , ) and ( , ) are inconsistent."
            return 1;//return 1 to represent inconsistent
        }
    }
    for(int i = 0; i < m*n; i++)
    {
        if( (i+1)%n == 0)//if the cell is at the end of the row, continue
        {
            continue;
        }
        if( (c+i)->door[1] != (c+i+1)->door[3] )//if the left cell's East door is consist with the right cell's West door
        {
            cout << "Input Error! (" << i/n+1 << "," << i%n+1 << ") and (" << i/n+1 << "," << i%n+2 << ") are inconsistent." << endl;
            //print "Input Error! ( , ) and ( , ) are inconsistent."
            return 1;//return 1 to represent inconsistent
        }
    }
    return 0;//return 0 to represent consistent
}

void Maze::find_path(int x, int y, int length)//to find the path
{
    length++;//to record steps so far
    *(path+x*n+y) = length;//set the present position as "length"

    if(x == m-1 && y == n-1 && ( min > length || min == 0 ))
    //if enter the exit and present length is smaller than the shortest path's length
    {
        for(int i = 0; i < m*n; i++)//set the shortest path as the present path
        {
            *(min_path+i) = *(path+i);
        }
        min = length;//set the the shortest path's length as the present length
        *(path+x*n+y) = 0;//reset set the present position"
        return;
    }
    if( (c+x*n+y)->door[0] == 0 && *(path+(x-1)*n+y) == 0 )//if the upper cell is able to enter
    {
        find_path(x-1, y, length);//call function and set x = x-1
    }
    if( (c+x*n+y)->door[1] == 0 && *(path+x*n+y+1) == 0 )//if the right cell is able to enter
    {
        find_path(x, y+1, length);//call function and set y = y+1
    }
    if( (c+x*n+y)->door[2] == 0 && *(path+(x+1)*n+y) == 0 )//if the lower cell is able to enter
    {
        find_path(x+1, y, length);//call function and set x = x+1
    }
    if( (c+x*n+y)->door[3] == 0 && *(path+x*n+y-1) == 0 && (x!=0 || y!=0) )//if the left cell is able to enter
    {
        find_path(x, y-1, length);//call function and set y = y-1
    }

    *(path+x*n+y) = 0;//reset set the present position"

    return;
}

int main()
{
    int m, n;//declare two integer to record the length and width
    cin >> m >> n;//read the length and width

    Maze maze(m, n);//declare a new maze,and its length is "m" and width is "n"

    for(int i = 0; i < m*n; i++)
    {
        int value;//declare an integer to record a decimal value
        cin >> value;//read a decimal value
        (maze.c+i)->door[0] = value / 8;//transfer a decimal value to binary
        (maze.c+i)->door[1] = (value%8) / 4;
        (maze.c+i)->door[2] = (value%4) / 2;
        (maze.c+i)->door[3] = value%2;
    }

    if(maze.inconsistent() == 0)//call the function "maze.inconsistent", if the maze doesn't inconsistent
    {
        maze.find_path(0, 0, 0);//call the initial function

        if(maze.min == 0)//if there is no path
        {
            cout << "There is no path." << endl;
        }
        else
        {
            for(int i = 1; i <= maze.min; i++)//print the position in the numeral order
            {
                for(int j = 0; j < m*n; j++)//for the shortest path
                {
                    if(*(maze.min_path+j) == i)
                    {
                        cout << "(" << j/n+1 << "," << j%n+1 << ")";//print the position
                        if(i != maze.min)//if the cell isn't the exit
                        {
                            cout << "->";
                        }
                    }
                }
            }
            cout << endl;
        }
    }
    return 0;
}
