#include<iostream>
#include<vector>

using namespace std;

int N;


bool canPlace(vector<vector<bool> >board,int row,int col)
{
    for(int i=0;i<col;i++)
    {
        if(board[row][i])
            return false;
    }
    for(int i=row,j=col;i>=0&&j>=0;j--,i--)
    {
        if(board[i][j])
            return false;
    }
    for(int i=row,j=col;j>=0&&i<N;i++,j--)
    {
        if(board[i][j])
            return false;
    }
    return true;
}

bool NQueen(vector<vector<bool> >&board,int col){

    if(col==N)
        return true;
    for(int i=0;i<N;i++)
    {
        if(canPlace(board,i,col)){
            board[i][col]=1;
            if(NQueen(board,col+1))
                return true;
            board[i][col]=0;
        }
    }
    return false;    

}


void printBoard(vector<vector<bool> >board)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    cout<<"Enter the size of the board";
    cin>>N;
    vector<vector<bool> >board(N,vector<bool>(N,0));
    
    if(NQueen(board,0))
        printBoard(board);
    else
        cout<<"Not possible to place all queens!";    
    return 0;
}