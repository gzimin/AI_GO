#ifndef INPUT_H
#define INPUT_H

using namespace std;

class Desk
{
private:
    int n;
    int m;
    int turn;
    int **desk;

public:
    Desk(int n, int m, int turn, int **desk);
    ~Desk();
    void show();
};


int set(char temp);


Desk* info(string way2file);


#endif // INPUT_H
