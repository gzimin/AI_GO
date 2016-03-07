#include <iostream>

using namespace std;


struct move
{
    int x,y;
};


move aibot(int **desk, int n) // n -размерность доски
{
    move moveret;
    moveret.x = 1;
    moveret.y = 1;
    // Задача 49-кю
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

    move turn = aibot(desk, n);
    cout << turn.x << " " << turn.y << endl;
    return 0;
}

