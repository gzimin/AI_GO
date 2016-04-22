#include <iostream>
#include <vector>
#include <stack>

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



int free_ways(int group_number, int **allgroups, int n)
{
    int freeways = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(allgroups[i][j] == group_number)
            {
                if(i + 1 < n && allgroups[i + 1][j] == 0)
                {
                    freeways++;
                }
                if(i - 1 > 0 && allgroups[i - 1][j] == 0)
                {
                    freeways++;
                }
                if( j + 1 < n &&allgroups[i][j + 1] == 0)
                {
                    freeways++;
                }
                if( j - 1 > 0 && allgroups[i][j - 1] == 0)
                {
                    freeways++;
                }
            }
        }
    }
    return freeways;
}
void group_search_2(stack<move> &points, int **allgroups, move &startpoint,
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

void group_search(int **desk, int n, int **allgroups)
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
    while(group_number <= n * n)
    {
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
                            group_number+=2;
                    }
                    if(desk[i][j] == 2)
                    {
                        stonecolor = 2;
                        if(group_number % 2 == 1)
                            group_number++;
                        else
                            group_number+=2;
                    }

                    startpoint.x = i;
                    startpoint.y = j;
                    points.push(startpoint);
                    allgroups[i][j] = group_number;
                    group_search_2(points, allgroups, startpoint, temppoint, stonecolor, group_number, n, desk);
                }
                if(i == n - 1 && j == n - 1)
                    return;
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
    bool **viewed = new bool*[n];
    for(int i = 0; i < n; i++)
    {
        viewed[i] = new bool[n];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            viewed[i][j] = false;
    }
    group_search(desk, n, mat);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    int ways = free_ways(1, mat, n);
    cout << "free ways of first group " << ways << endl;
}
