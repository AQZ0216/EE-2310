#include <stdio.h>
#include <stdlib.h>

int check(char a[][9], int x, int y)//check whether the grid follow the rule
{
    for(int i = 0; i < 9; i++)//check whether the column has the same number as the grid
    {
        if(a[i][y] == a[x][y] && i != x)
        {
            return 0;//if it has the same number, return 0
        }
    }
    for(int i = 0; i < 9; i++)//check whether the row has the same number as the grid
    {
        if(a[x][i] == a[x][y] && i != y)
        {
            return 0;//if it has the same number, return 0
        }
    }
    for(int i = x - x % 3; i < x - x % 3 +3; i++)//check whether the subgrid has the same number as the grid
    {
        for(int j = y - y % 3; j < y - y % 3 +3; j++)
        {
            if(a[i][j] == a[x][y] && (i != x  || j != y))
            {
                return 0;//if it has the same number, return 0
            }
        }
    }
    return 1;//if the grid follow the rule, return 1
}

void print(char a[][9])//to print solution
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            printf("%c ",a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    char sudoku[9][9];//declare an array to record the question
    char solution[9][9];//declare an array to record the solution

    char temp;//declare a char to read ' '(space) temporary

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            scanf("%c%c", &sudoku[i][j], &temp);//read the question
        }
    }

    for(int i = 0; i < 9; i++)//transfer question to solution
    {
        for(int j = 0; j < 9; j++)
        {
            if(sudoku[i][j] == ' ')
            {
                solution[i][j] = '0';//if the question is empty , set the solution to 0 to let the latter calculation more convenient
            }
            else
            {
                solution[i][j] = sudoku[i][j];//transfer question to solution
            }
        }
    }

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(sudoku[i][j] == ' ')//if the grid of the question is empty
            {
                do
                {
                    solution[i][j]++;//plus 1 to the grid of the solution
                }
                while(check(solution, i, j) == 0);//while the grid doesn't follow the rule, plus 1 again


            }
            if(solution[i][j] == ':')/*if the grid is 10(in ASCII the next bit of '9' is ':'),
                                        set the grid to 0, and back to the former grid*/
            {
                solution[i][j] = '0';//set the grid to 0
                if(j == 0)//back to the former grid
                {
                    j = 8;
                    i--;
                }
                else
                {
                    j--;
                }

                while(sudoku[i][j] != ' ')//while the former grid isn't empty, back to the former grid again
                {
                    if(j == 0)
                    {
                        j = 8;
                        i--;
                    }
                    else
                    {
                        j--;
                    }
                }

                if(j == 0)//because every for loop will j++, we need to  back to the former grid again
                {
                    j = 8;
                    i--;
                }
                else
                {
                    j--;
                }
            }
        }
    }

    print(solution); //print the solution

    return 0;
}
