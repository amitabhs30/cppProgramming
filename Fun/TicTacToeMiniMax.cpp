#include <iostream>
#include <vector>

using namespace std;

vector<vector<char> > board;

struct moov
{
    int x;
    int y;

    moov(int a, int b)
    {
        x = a;
        y = b;
    }
};

void printBoard()
{
    cout << endl
         << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << "\t";
        }
        cout << endl
             << endl;
    }
}
bool isFinished()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == '_')
                return false;
        }
    }
    return true;
}
int findResult()

{
    if ((board[0][0] == 'X' && (board[0][1] == 'X' && board[0][2] == 'X')) ||
        ((board[1][0] == 'X' && (board[1][1] == 'X' && board[1][2] == 'X')) ||
         (board[2][0] == 'X' && (board[2][1] == 'X' && board[2][2] == 'X'))))
        return 10;

    if ((board[0][0] == 'O' && (board[0][1] == 'O' && board[0][2] == 'O')) ||
        ((board[1][0] == 'O' && (board[1][1] == 'O' && board[1][2] == 'O')) ||
         (board[2][0] == 'O' && (board[2][1] == 'O' && board[2][2] == 'O'))))
        return -10;

    if ((board[0][0] == 'X' && (board[1][0] == 'X' && board[2][0] == 'X')) ||
        ((board[0][1] == 'X' && (board[1][1] == 'X' && board[2][1] == 'X')) ||
         (board[0][2] == 'X' && (board[1][2] == 'X' && board[2][2] == 'X'))))
        return 10;

    if ((board[0][0] == 'O' && (board[1][0] == 'O' && board[2][0] == 'O')) ||
        ((board[0][1] == 'O' && (board[1][1] == 'O' && board[2][1] == 'O')) ||
         (board[0][2] == 'O' && (board[1][2] == 'O' && board[2][2] == 'O'))))
        return -10;

    if ((board[0][0] == 'X' && (board[1][1] == 'X' && board[2][2] == 'X')) ||
        (board[0][2] == 'X' && (board[1][1] == 'X' && board[2][0] == 'X')))
        return 10;

    if ((board[0][0] == 'O' && (board[1][1] == 'O' && board[2][2] == 'O')) ||
        (board[0][2] == 'O' && (board[1][1] == 'O' && board[2][0] == 'O')))
        return -10;
    return 0;
}

int minimax(int depth, bool ismaxi)
{
    int score = findResult();
    if (score == 10)
        return 10 - depth;
    if (score == -10)
        return -10 + depth;
    if (isFinished())
        return 0;
    if (ismaxi)
    {
        int best = INT16_MIN;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '_')
                {
                    board[i][j] = 'X';
                    best = max(best, minimax(depth + 1, false));
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
    else
    {
        int best = __INT16_MAX__;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '_')
                {
                    board[i][j] = 'O';
                    best = min(best, minimax(depth + 1, true));
                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}
bool isEmpty()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != '_')
                return false;
        }
    }
    return true;
}

moov *aiTurn()
{
    moov *mov = new moov(-1, -1);
    int bestVal = INT16_MIN;
    if (!isEmpty())
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == '_')
                {
                    board[i][j] = 'X';
                    int moveVal = minimax(0, false);
                    board[i][j] = '_';
                    if (moveVal > bestVal)
                    {
                        bestVal = moveVal;
                        mov->x = i;
                        mov->y = j;
                    }
                }
            }
        }
    else
    {
        mov->x=rand()%3;
        mov->y=rand()%3;
    }
        
    return mov;
}
moov *humanTurn()
{
JUMP:
    cout << "\nYour Turn !! \nEnter the row and column you want to play";
    int x, y;
    cin >> x >> y;
    if (board[x - 1][y - 1] != '_')
    {
        cout << "Not a valid move!";
        goto JUMP;
    }
    moov *mov = new moov(x - 1, y - 1);
    return mov;
}
void play()
{
    cout << "All you have to do to play is give the row no and column no from 1 to 3.\nYou are O";
    int turn =rand()%2;
    while (!isFinished())
    {
        if (turn)
        {
            moov *mov = aiTurn();
            board[mov->x][mov->y] = 'X';
            turn = 0;
            printBoard();
            if (findResult() == 10)
            {

                cout << "AI has won!";
                return;
            }
        }
        else
        {
            moov *mov = humanTurn();
            board[mov->x][mov->y] = 'O';
            if (findResult() == -10)
            {
                cout << "You have won!";
                return;
            }
            turn = 1;
        }
    }

    cout << "Its a TIE!!!";
}

int main()
{
    while (true)
    {
        int choice;
        cout << endl
             << "Press 1 to play 0 to quit!";
        cin >> choice;
        switch (choice)
        {
        case 1:
            srand(time(0));
            board.clear();
            for (int i = 0; i < 3; i++)
            {
                vector<char> temp(3, '_');
                board.push_back(temp);
            }
            play();
            break;
        case 0:
            return 0;
        default:
            cout << "Wrong choice!" << endl;
            continue;
        }
    }
    return 0;
}