#include <iostream>
using namespace std;

char a[3][3];

void printBoard()
{
    cout << "\n";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << a[i][j];

            if(j!=2)
                cout << " | ";
        }

        cout << "\n";

        if(i!=2)
            cout << "--|---|--\n";
    }

    cout << "\n";
}

bool winner(char ch)
{
    for(int i=0;i<3;i++)
    {
        if(a[i][0]==ch && a[i][1]==ch && a[i][2]==ch)
            return true;
    }

    for(int j=0;j<3;j++)
    {
        if(a[0][j]==ch && a[1][j]==ch && a[2][j]==ch)
            return true;
    }

    if(a[0][0]==ch && a[1][1]==ch && a[2][2]==ch)
        return true;

    if(a[0][2]==ch && a[1][1]==ch && a[2][0]==ch)
        return true;

    return false;
}

bool draw()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]!='X' && a[i][j]!='O')
                return false;
        }
    }

    return true;
}

int main()
{
    char again;

    do
    {
        char num='1';

        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                a[i][j]=num;
                num++;
            }
        }

        char player='X';

        while(true)
        {
            printBoard();

            int pos;

            cout<<"Player "<<player<<" enter position: ";
            cin>>pos;

            if(pos<1 || pos>9)
            {
                cout<<"Wrong position!\n";
                continue;
            }

            int r=(pos-1)/3;
            int c=(pos-1)%3;

            if(a[r][c]=='X' || a[r][c]=='O')
            {
                cout<<"Already filled!\n";
                continue;
            }

            a[r][c]=player;

            if(winner(player))
            {
                printBoard();
                cout<<"Player "<<player<<" wins!\n";
                break;
            }

            if(draw())
            {
                printBoard();
                cout<<"Match Draw!\n";
                break;
            }

            if(player=='X')
                player='O';
            else
                player='X';
        }

        cout<<"Play again? (y/n): ";
        cin>>again;

    }while(again=='y' || again=='Y');

    return 0;
}