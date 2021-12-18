#include <iostream>
#include <cstring>
using namespace std;
#define size 4

class Board
{
private:
    int board[size][size];
    int lost = 2;

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
             << "3 for left" << endl;
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
                    lost == 0;
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

    void move_up()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (!board[j][i])
                {
                    for (int k = j + 1; k < 4; k++)
                    {
                        if (board[k][i])
                        {
                            board[j][i] = board[k][i];
                            board[k][i] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }

    void move_down()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 3; j >= 0; j--)
            {
                if (!board[j][i])
                {
                    for (int k = j - 1; k >= 0; k--)
                    {
                        if (board[k][i])
                        {
                            board[j][i] = board[k][i];
                            board[k][i] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }

    void move_left()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (!board[i][j])
                {
                    for (int k = j + 1; k < 4; k++)
                    {
                        if (board[i][k])
                        {
                            board[i][j] = board[i][k];
                            board[i][k] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }

    void move_right()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 3; j >= 0; j--)
            {
                if (!board[i][j])
                {
                    for (int k = j - 1; k >= 0; k--)
                    {
                        if (board[i][k])
                        {
                            board[i][j] = board[i][k];
                            board[i][k] = 0;
                            break;
                        }
                    }
                }
            }
        }
    }

    void sum_up()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[j][i] && board[j][i] == board[j + 1][i])
                {
                    board[j][i] = board[j][i] + board[j + 1][i];
                    board[j + 1][i] = 0;
                }
            }
        }
    }

    void sum_down()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 3; j > 0; j--)
            {
                if (board[j][i] && board[j][i] == board[j - 1][i])
                {
                    board[j][i] = board[j][i] + board[j - 1][i];
                    board[j - 1][i] = 0;
                }
            }
        }
    }

    void sum_left()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] && board[i][j] == board[i][j + 1])
                {
                    board[i][j] = board[i][j] + board[i][j + 1];
                    board[i][j + 1] = 0;
                }
            }
        }
    }

    void sum_right()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 3; j > 0; j--)
            {
                if (board[i][j] && board[i][j] == board[i][j - 1])
                {
                    board[i][j] = board[i][j] + board[i][j - 1];
                    board[i][j - 1] = 0;
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

public:
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
                move_up();
                sum_up();
                move_up();
            }
            else if (direc == 1)
            {
                // cout<<"fine";
                move_right();
                sum_right();
                move_right();
            }
            else if (direc == 2)
            {
                move_down();
                sum_down();
                move_down();
            }
            else
            {
                move_left();
                sum_left();
                move_left();
            }
            generateRandomNum();
        }
        if (lost == 1)
        {
            cout << "You loose the game";
        }
        else if (lost == 0)
        {
            cout << "Hurray,congratulations";
        }
    }
};