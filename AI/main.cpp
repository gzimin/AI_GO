#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct move
{
    int x,y;
};
bool **free_ways_desk(int group_number, int **groups, int n)
{
    bool **tempdesk = new bool*[n];
    for(int i = 0; i < n; i++)
    {
        tempdesk[i] = new bool[n];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            tempdesk[i][j] = false;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(groups[i][j] == group_number)
            {
                if(i - 1 >= 0 && groups[i - 1][j] == 0)
                {
                    tempdesk[i - 1][j] = true;
                }
                if(j - 1 >= 0 && groups[i][j - 1] == 0)
                {
                    tempdesk[i][j - 1] = true;
                }
                if( i + 1 < n && groups[i + 1][j] == 0)
                {
                    tempdesk[i + 1][j] = true;
                }
                if( j + 1 < n && groups[i][j + 1] == 0)
                {
                    tempdesk[i][j + 1] = true;
                }
            }
        }
    }
    return
            tempdesk;
}

int free_ways_count(int **groups, int group_number, int n)
{
    int ret = 0;
    bool **tempdesk = new bool*[n];
    for(int i = 0; i < n; i++)
    {
        tempdesk[i] = new bool[n];
    }
    tempdesk = free_ways_desk(group_number, groups, n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(tempdesk[i][j] == true)
                ret++;
        }
    }
    return
            ret;
}

move increase_group_power(int **groups, int group_number, int n)
{

    move moveret;
    moveret.x = -1;
    moveret.y = -1;
    int tempways = 0;
    bool **tempdesk = new bool*[n];
    for(int i = 0; i < n; i++)
    {
        tempdesk[i] = new bool[n];
    }
    tempdesk = free_ways_desk(group_number, groups, n);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(groups[i][j] == group_number)
            {
                if(i - 1 >= 0 && groups[i - 1][j] == 0)
                {
                    if(tempdesk[i - 1][j] != true)
                    {
                        if(tempdesk[i - 2][j] != true)
                        {
                            tempways++;
                        }
                        if(tempdesk[i - 1][j - 1] != true)
                        {
                            tempways++;
                        }
                        if(tempdesk[i - 1][j + 1] != true)
                        {
                            tempways++;
                        }
                    }
                    if(tempways >= 2)
                    {
                        moveret.x = i - 1;
                        moveret.y = j;
                        return
                                moveret;
                    }
                    tempways = 0;
                }
                if(j - 1 >= 0 && groups[i][j - 1] == 0)
                {
                    if(tempdesk[i][j - 1] == true)
                    {
                        if(i - 1 >= 0 && tempdesk[i - 1][j - 1] != true)
                        {
                            tempways++;
                        }
                        if(j - 2 >= 0 && tempdesk[i][j - 2] != true)
                        {
                            tempways++;
                        }
                        if(i + 1 < n && tempdesk[i + 1][j - 1] != true)
                        {
                            tempways++;
                        }
                    }
                    if(tempways >= 2)
                    {
                        moveret.x = i;
                        moveret.y = j - 1;
                        return
                                moveret;
                    }
                }
                if( i + 1 < n && groups[i + 1][j] == 0)
                {
                    if(tempdesk[i + 1][j] == true)
                    {
                        if(j - 1 >= 0 && tempdesk[i + 1][j - 1] != true)
                        {
                            tempways++;
                        }
                        if(j + 2 < n &&tempdesk[i + 2][j] != true)
                        {
                            tempways++;
                        }
                        if(j + 1 < n && tempdesk[i + 1][j + 1] != true)
                        {
                            tempways++;
                        }
                    }
                    if(tempways >= 2)
                    {
                        moveret.x = i + 1;
                        moveret.y = j;
                        return
                                moveret;
                    }
                    tempways = 0;
                }
                if( j + 1 < n && groups[i][j + 1] == 0)
                {
                    if(tempdesk[i][j + 1] == true)
                    {
                        if(i + 1 < n && tempdesk[i + 1][j + 1] != true)
                        {
                            tempways++;
                        }
                        if(j + 2 < n && tempdesk[i][j + 2] != true)
                        {
                            tempways++;
                        }
                        if(i - 1 >= 0 && tempdesk[i - 1][j + 1] != true)
                        {
                            tempways++;
                        }
                    }
                    if(tempways >= 2)
                    {
                        moveret.x = i;
                        moveret.y = j + 1;
                        return
                                moveret;
                    }
                    tempways = 0;
                }
            }
        }
    }
    tempways = free_ways_count(groups, group_number, n);
    if(tempways == 1)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(tempdesk[i][j] == true)
                   {
                    moveret.x = i;
                    moveret.y = j;
                    return
                            moveret;
                   }
            }
        }
    }
    return
            moveret;

}

void search_one_group(stack<move> &points, int **allgroups, move &startpoint,
                      move &temppoint, int &stonecolor, int &group_number, int &n, int **desk)
{
    while(points.empty() == false)
    {
        startpoint = points.top();
        points.pop(); //извлекаем из стека
        if( startpoint.y + 1 < n && desk[startpoint.x][startpoint.y + 1] == stonecolor )
        {
            if(allgroups[startpoint.x][startpoint.y + 1] == 0)
            {
                allgroups[startpoint.x][startpoint.y + 1] = group_number;
                temppoint = startpoint;
                temppoint.y++;
                points.push(temppoint);
            }

        }
        if(startpoint.x + 1 < n && desk[startpoint.x + 1][startpoint.y] == stonecolor)
        {
            if(allgroups[startpoint.x + 1][startpoint.y] == 0)
            {
                allgroups[startpoint.x + 1][startpoint.y] = group_number;
                temppoint = startpoint;
                temppoint.x++;
                points.push(temppoint);
            }

        }
        if( startpoint.x - 1 >= 0 && desk[startpoint.x - 1][startpoint.y] == stonecolor)
        {
            if(allgroups[startpoint.x - 1][startpoint.y] == 0)
            {
                allgroups[startpoint.x - 1][startpoint.y] = group_number;
                temppoint.x--;
                points.push(temppoint);
            }

        }
        if(startpoint.y - 1 >= 0 && desk[startpoint.x][startpoint.y - 1] == stonecolor)
        {
            if(allgroups[startpoint.x][startpoint.y - 1] == 0)
            {
                allgroups[startpoint.x][startpoint.y - 1] = group_number;
                temppoint.y--;
                points.push(temppoint);
            }

        }
    }
}

void groups_search(int **desk, int n, int **allgroups)
{
    move startpoint;
    startpoint.x = 0;
    startpoint.y = 0;
    move temppoint;
    temppoint.x = 0;
    temppoint.y = 0;
    int stonecolor = 0;
    std::stack<move> points;
    int group_number = 0;
    for(int i = 0; i < n; i++) // цикл для нахождения первого камня группы
    {
        for(int j = 0; j < n; j++)
        {
            if(desk[i][j] != 0  && allgroups[i][j] == 0)
            {
                if(desk[i][j] == 1)
                {
                    stonecolor = 1;
                    if(group_number % 2 == 0)
                        group_number++;
                    else
                        group_number+= 2;
                }
                if(desk[i][j] == 2)
                {
                    stonecolor = 2;
                    if(group_number % 2 == 1)
                        group_number++;
                    else
                        group_number+= 2;
                }
                startpoint.x = i;
                startpoint.y = j;
                points.push(startpoint);
                allgroups[i][j] = group_number;
                search_one_group(points, allgroups, startpoint, temppoint,
                                 stonecolor, group_number, n, desk);
            }
        }
    }
}

int main()
{
    int n;
    move tempmove;
    tempmove.x = -1;
    tempmove.y = -1;
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
    int **mat = new int*[n];
    for(int i = 0; i < n; i++)
    {
        mat[i] = new int[n];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mat[i][j] = 0;
        }
    }

    groups_search(desk, n, mat);
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    int stonetype = 0;
    int tempvar = 0;
    int tempgroup = 0;
    cout << "Bot stone color - ";
    cin >> stonetype;
    /* Приоритеты -
     * 1.Защитить свои группы
     * 2. Захватить группу вражески камней
     */
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n ;j++)
        {
            if(mat[i][j] > tempvar)
            {
                tempvar = mat[i][j];
            }
        }
    }
    /* Проверяем сколько путей дыхания у каждой группы бота */
    for(int i = stonetype; i <= tempvar; i+= 2)
    {
        tempgroup = free_ways_count(mat, i, n);
        if(tempgroup == 1)
        {
            tempmove = increase_group_power(mat, i, n);
            cout << "Defend move - " << tempmove.x << " " << tempmove.y << endl;
        }
    }
    /* Проверяем группы вражеских камней, которые можно захватить за один ход */
    for(int i = stonetype + 1; i <= tempvar; i+= 2)
    {
        tempgroup = free_ways_count(mat, i, n);
        if(tempgroup == 1)
        {
            tempmove = increase_group_power(mat, i , n);
            cout << "Attack move - " << tempmove.x << " " << tempmove.y << endl;
        }
    }

}
