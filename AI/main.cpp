#include <iostream>
#include <fstream>

using namespace std;

int desk[19][19];
struct move
{
    int x,y;


};

move aibot(int **desk, int n) // n -размерность доски
{
    move move1;
    int mas[4];// массив, в котором хранятся значения соседних пересечений
    for(int i = 0; i < 4; i++)
    {
        mas[i] = 0;
    }
    for(int i = 0; i < n; i++) // первый цикл - поиск тех групп, которым грозит снятие с доски
        for(int j = 0; j < n; j++)
        {
            if(desk[i][j] == 1)
            {
                if(desk[i + 1][j] != 1)
                {
                    if(desk[i + 1][j] == 2)
                    {
                        mas[0] = 1;
                    }
                    else
                    {
                        move1.x = i + 1;
                        move1.y = j;
                        return move1;

                    }
                }
                if(desk[i - 1][j] != 1)
                {
                    if(desk[i - 1][j] == 2)
                    {
                        mas[1] = 1;
                    }
                    else
                    {
                        move1.x = i - 1;
                        move1.y = j;
                        return move1;

                    }
                }
                if(desk[i][j + 1] != 1)
                {
                    if(desk[i][j + 1] == 2)
                    {
                        mas[2] = 1;
                    }
                    else
                    {
                        move1.x = i ;
                        move1.y = j + 1;
                        return move1;
                    }
                }
                if(desk[i][j - 1] != 1)
                {
                    if(desk[i][j - 1] == 2)
                    {
                        mas[3] = 1;
                    }
                    else
                    {
                        move1.x = i;
                        move1.y = j - 1;
                        return move1;
                    }
                }

            }
        }
    int group[81];
    for(int i = 0; i < n; i++) // второй цикл - поиск тех групп, которые можно захватить
        for(int j = 0; j < n; j++)
        {


        }
}
int main()
{

}
