#include <iostream>
#include <cstring>
using namespace std;
#define size 4

class Board
{
private:
    int board[size][size];
    int lost = 0;

public:
    void init()
    {
        memset(board, 0, sizeof(board));
    }
    void showBoard()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    void showInstructions()
    {
        cout << "Please choose" << endl
             << "0 for up," << endl
             << "1 for right" << endl
             << "2 for down" << endl
             << "3 for left"<<endl;
    }

    bool isGameOver()
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] == 2048)
                {
                    return true;
                }
                if (board[i][j] == 0)
                {
                    count++;
                }
            }
        }
        if (count == 0)
        {
            lost = 1;
            return true;
        }
        return false;
    }

    void setColumn(bool up)
    {
        if (up)
        {
            for (int j = 0; j < size; j++)
            {
                for (int i = 0; i < size - 1; i++)
                {
                    if (board[i][j] == board[i + 1][j] && board[i][j] != 0)
                    {
                        board[i][j] += board[i + 1][j];
                        board[i + 1][j] = 0;
                    }
                    else if (board[i][j] == 0)
                    {
                        int temp = i;
                        while (i < size && board[i][j] == 0)
                        {
                            i++;
                        }
                        if (i < size)
                        {
                            int num = board[i][j];
                            board[i][j] = 0;
                            board[temp][j] = num;
                        }
                    }
                }
            }
        }
        else
        {
            for (int j = 0; j < size; j++)
            {
                for (int i = size - 1; i > 0; i--)
                {
                    if (board[i][j] == board[i - 1][j] && board[i][j] != 0)
                    {
                        board[i][j] += board[i + 1][j];
                        board[i - 1][j] = 0;
                    }
                    else if (board[i][j] == 0)
                    {
                        int temp = i;
                        while (i >= 0 && board[i][j] == 0)
                        {
                            i--;
                        }
                        if (i >= 0)
                        {
                            int num = board[i][j];
                            board[i][j] = 0;
                            board[temp][j] = num;
                        }
                    }
                }
            }
        }
    }

    void setRow(bool left)
    {
        if (left)
        {
            for (int j = 0; j < size; j++)
            {
                for (int i = 0; i < size - 1; i++)
                {
                    if (board[j][i] == board[j][i + 1] && board[j][i] != 0)
                    {
                        board[j][i] += board[j][i + 1];
                        board[j][i + 1] = 0;
                    }
                    else if (board[j][i] == 0)
                    {
                        int temp = i;
                        while (i < size && board[j][i] == 0)
                        {
                            i++;
                        }
                        if (i < size)
                        {
                            int num = board[j][i];
                            board[j][i] = 0;
                            board[j][temp] = num;
                        }
                    }
                }
            }
        }
        else
        {
            for (int j = 0; j < size; j++)
            {
                for (int i = size - 1; i > 0; i--)
                {
                    if (board[j][i] == board[j][i - 1] && board[j][i] != 0)
                    {
                        board[j][i] += board[j][i - 1];
                        board[j][i - 1] = 0;
                    }
                    else if (board[j][i] == 0)
                    {
                        int temp = i;
                        while (i >= 0 && board[j][i] == 0)
                        {
                            i--;
                        }
                        if (i >= 0)
                        {
                            int num = board[j][i];
                            board[j][i] = 0;
                            board[j][temp] = num;
                        }
                    }
                }
            }
        }
    }

    void generateRandomNum()
    {
        int flag = 1;
        while (flag)
        {
            int i = rand() % 4 + 0;
            ;
            int j = rand() % 4 + 0;
            if (board[i][j] == 0)
            {
                int y = rand() % 10 + 0;
                if (y < 6)
                {
                    board[i][j] = 2;
                }
                else
                {
                    board[i][j] = 4;
                }
                flag = 0;
            }
        }
    }

    void startGame()
    {
        showInstructions();
        init();
        int direc;
        generateRandomNum();
        while (!isGameOver())
        {
            showBoard();
            cout << "Please select your directional move" << endl;
            while (1)
            {
                cin >> direc;
                if (direc >= 0 && direc <= 3)
                {
                    break;
                }
                else
                {
                    cout << "Invalid move ,choose 0,1,2 or 3" << endl;
                }
            }
            if (direc == 0)
            {
                setColumn(1);
            }
            else if (direc == 1)
            {
                // cout<<"fine";
                setRow(false);
            }
            else if (direc == 2)
            {
                setColumn(0);
            }
            else
            {
                setRow(1);
            }
            generateRandomNum();
        }
        if (lost == 1)
        {
            cout << "You loose the game";
        }
        else
        {
            cout << "Hurray,congratulations";
        }
    }
};