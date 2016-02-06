#include <fstream>
#include <string>
#include <iostream>

using namespace std;


class Desk
{
private:
    int n;
    int m;
    int turn;
    int **desk;

public:
    Desk(int n, int m, int turn, int **desk)
    {
        this->n = n;
        this->m = m;
        this->turn = turn;
        this->desk = desk;
    }

    ~Desk()
    {
        cout << "Memory has been cleaned" << endl;
    }

    void show()
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


};


int set(char* temp, int i)
{
    switch(temp[i])
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
        char temp_char[n * m];
        if(in)
        {
        int tmp = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < m; j++)
                {
                    in >> temp_char[tmp];
                    desk[i][j] = set(temp_char, tmp++);
                }
            }
        }
        in.close();
        Desk *startdesk = new Desk(n, m, move, desk);
        return startdesk;
    }
}


int main()
{
    Desk *testdeck;
    testdeck = info("inp.txt");
    testdeck->show();
    delete testdeck;
}
