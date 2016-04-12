#include <iostream>
#include <vector>
#include <stack.h>

using namespace std;

struct move
{
    int x,y;
};
struct neardots
{
  int x;
  int y;
  int stone;
};



void group_search(int **desk, int n, int stone)
{
    vector<move> stone_group;
    stone_group.reserve(n);
    int top = 0;
    move startpoint;
    startpoint.x = 0;
    startpoint.y = 0;
    move temppoint;
    temppoint.x = 0;
    temppoint.y = 0;
    Stack<move> points(n);
    int mat[20][20];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mat[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++) // цикл для нахождения первого камня группы
   {
        for(int j = 0; j < n; j++)
        {
            if(desk[i][j] == stone)
            {
                startpoint.x = i;
                startpoint.y = j;
                points.push(startpoint);
              stone_group.push_back(startpoint);
                mat[i][j] = 1;
                goto groupsearch;
            }
        }
    }
    groupsearch:
    while(true)
    {
        int whilestop = 0;
        startpoint = points.Peek(points.getTop());
        cout << startpoint.x << " " << startpoint.y << endl;
        if(points.getTop() != 0)
            points.pop(); //извлекаем из стека
        else
            break;
        if( startpoint.y + 1 < n && desk[startpoint.x][startpoint.y + 1] == stone )
        {
            whilestop++;
            if(mat[startpoint.x][startpoint.y + 1] != 1)
            {
                mat[startpoint.x][startpoint.y + 1] = 1;
                temppoint = startpoint;
                temppoint.y++;
                points.push(temppoint);
               stone_group.push_back(temppoint);
            }

        }
        if(startpoint.x + 1 < n && desk[startpoint.x + 1][startpoint.y] == stone)
        {
            whilestop++;
            if(mat[startpoint.x + 1][startpoint.y] != 1)
            {
                mat[startpoint.x + 1][startpoint.y] = 1;
                temppoint = startpoint;
                temppoint.x++;
                points.push(temppoint);
               stone_group.push_back(temppoint);
            }

        }
        if( startpoint.x - 1 > 0 && desk[startpoint.x - 1][startpoint.y] == stone)
        {
            whilestop++;
            if(mat[startpoint.x - 1][startpoint.y] != 1)
            {
                mat[startpoint.x - 1][startpoint.y] = 1;
                temppoint.x--;
                points.push(temppoint);
               stone_group.push_back(temppoint);
            }

        }
        if(startpoint.y - 1 > 0 && desk[startpoint.x][startpoint.y - 1] == stone)
        {
            whilestop++;
            if(mat[startpoint.x][startpoint.y - 1] != 1)
            {
                mat[startpoint.x][startpoint.y - 1] = 1;
                temppoint.y--;
                points.push(temppoint);
               stone_group.push_back(temppoint);
            }

        }
        if(whilestop == 0)
            break;
    }
    int vsize = stone_group.size();
    cout << vsize << endl;


}
move aibot(int **desk, int n) // n -размерность доски

{
    move moveret;
    moveret.x = 1;
    moveret.y = 1;
    // Задача 49-кю
        if(desk[0][0] == 1) // левый верхний камень
        {
            if(desk[0][1] != 1 && desk[1][0] != 1)
            {
                if(desk[0][1] == 0 && desk[1][0] == 2)
                {
                    moveret.x = 1;
                    moveret.y = 0;
                    return
                            moveret;
                }
                else if(desk[0][1] == 2 && desk[1][0] == 0)
                {
                    moveret.x = 0;
                    moveret.y = 1;
                    return
                            moveret;
                }

            }
        }
        if(desk[n - 1][0] == 1) // левый нижний камень
        {
            if(desk[n- 1][1] != 1 && desk[n - 2][0] != 1)
            {
                if(desk[n - 1][1] == 0 && desk[n - 2][0] == 2)
                {
                    moveret.x = n - 1;
                    moveret.y = 1;
                    return
                            moveret;
                }
                else if(desk[n - 1][1] == 2 && desk[n - 2][0] == 0)
                {
                    moveret.x = 0;
                    moveret.y = n - 2;
                    return
                            moveret;
                }

            }
        }
        if(desk[0][n - 1] == 1) // правый верхний камень
        {
            if(desk[1][n- 1] != 1 && desk[0][n - 2] != 1)
            {
                if(desk[1][n - 1] == 0 && desk[0][n - 2] == 2)
                {
                    moveret.x = n - 1;
                    moveret.y = 1;
                    return
                            moveret;
                }
                else if(desk[1][n - 1] == 2 && desk[0][n - 2] == 0)
                {
                    moveret.x = 0;
                    moveret.y = n - 2;
                    return
                            moveret;
                }

            }
        }

        if(desk[n - 1][n - 1] == 1) // правый нижний камень
        {

            if(desk[n - 2][n- 1] != 1 && desk[n - 1][n - 2] != 1)
            {
                if(desk[n - 2][n - 1] == 0 && desk[n - 1][n - 2] == 2)
                {
                    moveret.x = n - 2;
                    moveret.y = n - 1;
                    return
                            moveret;
                }
                else if(desk[1][n - 1] == 2 && desk[0][n - 2] == 0)
                {
                    moveret.x = n - 1;
                    moveret.y = n - 2;
                    return
                            moveret;
                }

            }
        }
    for(int i = 1; i < n; i++) // 1-ый цикл( верхняя стенка)
    {
        if(desk[0][i] == 1)
        {
            int count = 1;
            for(int j = i + 1; j < n; j++) // находим длину ряда камней оппонента
                if(desk[0][j] == 1)
                {
                    count++;
                }
                else
                {
                    break;
                }
            int tempmas[10];                            // первые i + count - 1 ячеек отвечают за камни,
            for(int j = 0; j < i + count + 2; j++)  // которые находятся снизу камней оппонента
            {
                tempmas[j] = 0;
            }
            int num = 0;
            for(int j = i; j < i + count; j++)
            {
                if(desk[1][j] == 2)
                {
                    tempmas[num] = 2;
                }
                num++;
            }
            if(desk[0][i - 1] == 2)
            {
                tempmas[num] = 2;

            }
            num++;
            if(desk[0][i + count] == 2)
            {
                tempmas[num] = 2;
            }
            int stonecount = 0;
            for(int j = 0; j < i + count + 2; j++)
            {
                if(tempmas[j] == 2)
                    stonecount++;
            }
            if(stonecount == i + count)
            {
                for(int j = 0; j < i + count + 2; j++)
                {
                    if(tempmas[j] != 2)
                        if(j == i + count + 1)
                        {
                            moveret.y = i + count;
                            moveret.x = 0;
                            return
                                    moveret;
                        }
                        else if(j == i + count - 1)
                        {
                            moveret.y = i - 1;
                            moveret.x = 0;
                            return
                                    moveret;
                        }
                        else
                        {
                            moveret.y = i + j;
                            moveret.x = 1;
                            return
                                    moveret;
                        }
                }
            }
        }

    }

    for(int i = 1; i < n; i++) // 2-ой цикл(левая стенка)
    {

        if(desk[i][0] == 1)
        {
            int count = 1;
            for(int j = i + 1; j < n; j++) // находим длину ряда камней оппонента
                if(desk[j][0] == 1)
                {
                    count++;
                }
                else
                {
                    break;
                }
            int tempmas[10];                            // первые i + count - 1 ячеек отвечают за камни,
            for(int j = 0; j < i + count + 2; j++)  // которые находятся снизу камней оппонента
            {
                tempmas[j] = 0;
            }
            int num = 0;
            for(int j = i; j < i + count; j++)
            {
                if(desk[j][1] == 2)
                {
                    tempmas[num] = 2;
                }
                num++;
            }
            if(desk[i - 1][0] == 2)
            {
                tempmas[num] = 2;

            }
            num++;
            if(desk[i + count][0] == 2)
            {
                tempmas[num] = 2;
            }
            int stonecount = 0;
            for(int j = 0; j < i + count + 2; j++)
            {
                if(tempmas[j] == 2)
                    stonecount++;
            }
            if(stonecount == i + count)
            {
                for(int j = 0; j < i + count + 2; j++)
                {
                    if(tempmas[j] != 2)
                        if(j == i + count + 1)
                        {
                            moveret.y = 0;
                            moveret.x = i + count;
                            return
                                    moveret;
                        }
                        else if(j == i + count - 1)
                        {
                            moveret.y = 0;
                            moveret.x = i - 1;
                            return
                                    moveret;
                        }
                        else
                        {
                            moveret.y = 0;
                            moveret.x = i + j - 1;
                            return
                                    moveret;
                        }
                }
            }
        }

    }
    for(int i = 1; i < n; i++) // 3-ий цикл(правая стенка)
    {

        if(desk[i][n - 1] == 1)
        {
            int count = 1;
            for(int j = i + 1; j < n; j++) // находим длину ряда камней оппонента
                if(desk[j][n - 1] == 1)
                {
                    count++;
                }
                else
                {
                    break;
                }
            int tempmas[10];                            // первые i + count - 1 ячеек отвечают за камни,
            for(int j = 0; j < i + count + 2; j++)  // которые находятся снизу камней оппонента
            {
                tempmas[j] = 0;
            }
            int num = 0;
            for(int j = i; j < i + count; j++)
            {
                if(desk[j][n - 2] == 2)
                {
                    tempmas[num] = 2;
                }
                num++;
            }
            if(desk[i - 1][n - 1] == 2)
            {
                tempmas[num] = 2;

            }
            num++;
            if(desk[i + count][n - 1] == 2)
            {
                tempmas[num] = 2;
            }
            int stonecount = 0;
            for(int j = 0; j < i + count + 2; j++)
            {
                if(tempmas[j] == 2)
                    stonecount++;
            }
            if(stonecount == i + count)
            {
                for(int j = 0; j < i + count + 2; j++)
                {
                    if(tempmas[j] != 2)
                        if(j == i + count + 1)
                        {
                            moveret.y = n - 1;
                            moveret.x = i + count;
                            return
                                    moveret;
                        }
                        else if(j == i + count - 1)
                        {
                            moveret.y = n - 1;
                            moveret.x = i - 1;
                            return
                                    moveret;
                        }
                        else
                        {
                            moveret.y = n - 1;
                            moveret.x = i + j - 1;
                            return
                                    moveret;
                        }
                }
            }
        }

    }
    for(int i = 1; i < n; i++) // 4-ый цикл( нижняя стенка)
    {
        if(desk[n - 1][i] == 1)
        {
            int count = 1;
            for(int j = i + 1; j < n; j++) // находим длину ряда камней оппонента
                if(desk[n - 1][j] == 1)
                {
                    count++;
                }
                else
                {
                    break;
                }
            int tempmas[10];                            // первые i + count - 1 ячеек отвечают за камни,
            for(int j = 0; j < i + count + 2; j++)  // которые находятся снизу камней оппонента
            {
                tempmas[j] = 0;
            }
            int num = 0;
            for(int j = i; j < i + count; j++)
            {
                if(desk[n - 2][j] == 2)
                {
                    tempmas[num] = 2;
                }
                num++;
            }
            if(desk[n - 1][i - 1] == 2)
            {
                tempmas[num] = 2;

            }
            num++;
            if(desk[n - 1][i + count] == 2)
            {
                tempmas[num] = 2;
            }
            int stonecount = 0;
            for(int j = 0; j < i + count + 2; j++)
            {
                if(tempmas[j] == 2)
                    stonecount++;
            }
            if(stonecount == i + count)
            {
                for(int j = 0; j < i + count + 2; j++)
                {
                    if(tempmas[j] != 2)
                        if(j == i + count + 1)
                        {
                            moveret.y = i + count;
                            moveret.x = n - 1;
                            return
                                    moveret;
                        }
                        else if(j == i + count - 1)
                        {
                            moveret.y = i + 1;
                            moveret.x = n - 1;
                            return
                                    moveret;
                        }
                        else
                        {
                            moveret.y = i + j - 1;
                            moveret.x = n - 1;
                            return
                                    moveret;
                        }
                }
            }
        }

    }



}


int main()
{
    int n;
    cin >> n;
    int **desk = new int*[n];
    for(int i = 0; i < n; i++)
    {
        desk[i] = new int[n];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> desk[i][j];
        }
    }
    group_search(desk, n, 1);

}

