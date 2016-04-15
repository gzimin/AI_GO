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



vector<move> group_search(int **desk, int n, int stone, int **allgroups, int group_number)
{
    vector<move> stone_group;
    stone_group.reserve(n);
    move startpoint;
    startpoint.x = 0;
    startpoint.y = 0;
    move temppoint;
    temppoint.x = 0;
    temppoint.y = 0;
    std::stack<move> points;
    for(int i = 0; i < n; i++) // цикл для нахождения первого камня группы
   {
        for(int j = 0; j < n; j++)
        {
            if(desk[i][j] == stone && allgroups[i][j] == 0)
            {
                startpoint.x = i;
                startpoint.y = j;
                points.push(startpoint);
              stone_group.push_back(startpoint);
                allgroups[i][j] = group_number;
                goto groupsearch;
            }
        }
    }
    groupsearch:
    while(true)
    {
        int whilestop = 0;
        if(points.empty() == false)
        {
        startpoint = points.top();
            points.pop(); //извлекаем из стека
        }
        else
            break;
        if( startpoint.y + 1 < n && desk[startpoint.x][startpoint.y + 1] == stone )
        {
            whilestop++;
            if(allgroups[startpoint.x][startpoint.y + 1] == 0)
            {
                allgroups[startpoint.x][startpoint.y + 1] = group_number;
                temppoint = startpoint;
                temppoint.y++;
                points.push(temppoint);
               stone_group.push_back(temppoint);
            }

        }
        if(startpoint.x + 1 < n && desk[startpoint.x + 1][startpoint.y] == stone)
        {
            whilestop++;
            if(allgroups[startpoint.x + 1][startpoint.y] == 0)
            {
                allgroups[startpoint.x + 1][startpoint.y] = group_number;
                temppoint = startpoint;
                temppoint.x++;
                points.push(temppoint);
               stone_group.push_back(temppoint);
            }

        }
        if( startpoint.x - 1 >= 0 && desk[startpoint.x - 1][startpoint.y] == stone)
        {
            whilestop++;
            if(allgroups[startpoint.x - 1][startpoint.y] == 0)
            {
                allgroups[startpoint.x - 1][startpoint.y] = group_number;
                temppoint.x--;
                points.push(temppoint);
               stone_group.push_back(temppoint);
            }

        }
        if(startpoint.y - 1 >= 0 && desk[startpoint.x][startpoint.y - 1] == stone)
        {
            whilestop++;
            if(allgroups[startpoint.x][startpoint.y - 1] == 0)
            {
                allgroups[startpoint.x][startpoint.y - 1] = group_number;
                temppoint.y--;
                points.push(temppoint);
               stone_group.push_back(temppoint);
            }

        }
        if(whilestop == 0)
            break;
    }
    return stone_group;


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
    vector<move> group;
    int groupnum = 1;
    while(true)
    {

        group = group_search(desk, n, 1, mat, groupnum);

        if(groupnum < n * n / 2 + 1)
            groupnum++;
        else
            break;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

}
