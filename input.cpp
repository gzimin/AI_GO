#include <iostream>
#include <fstream>
#include "input.h"


Desk::Desk(int n, int m, int turn, int **desk)
{
    this->n = n;
    this->m = m;
    this->turn = turn;
    this->desk = desk;
}


void Desk::show()
{
    cout << n << " " << m << " " << turn << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << desk[i][j] << " ";
        }
        cout << endl;
    }
}


Desk::~Desk()
{
    cout << "Memory has been cleaned" << endl;
    for(int i = 0; i < m; i++)
    {
        delete[] desk[i];
    }
    delete []desk;
}


int set(char temp)
{
    switch(temp)
    {
    case '1':
        return 1;
    case '0':
        return 0;
    case '2':
        return 2;
    default:
        cout << "Error deck input" << endl;
    }
}


Desk* info(string way2file)
{
    ifstream in(way2file.c_str());
    if (!in.is_open())
        cout << "Error openning file" << endl;
    else
    {
        int n, m, move;
        in >> n;
        in >> m;
        in >> move;
        int **desk = new int*[m];
        for(int i = 0; i < m; i++)
        {
            desk[i] = new int[n];
        }

        if(in)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    char temp_char;
                    in >> temp_char;
                    desk[i][j] = set(temp_char);
                }
            }
        }
        in.close();
        Desk *startdesk = new Desk(n, m, move, desk);
        return startdesk;
    }
}
