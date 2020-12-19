#include<iostream>
#include<vector>
#include<cmath>


using namespace std;

double X;

void setFirstValues(vector<vector<double> >mat,vector<vector<double> >&res)
{
    int comp=mat[0][0]+mat[0][1]+mat[1][0]+mat[1][1];
    double max=INT16_MIN;
    int i;
    for(i=16;i>=1;i--)
    {
        if(double(comp)/i>(double)9)
        {
            break;
        }
    }
    int div=i+1;
    for(i=div;i<=16;i++)
    {
        if (comp%i==0)
            {
            div=i;
            break;
            }
    }
    X=sqrt(div);

    res[1][1]=round((mat[0][0]+mat[0][1]+mat[1][0]+mat[1][1])/div);
    res[1][0]=round((mat[0][0]+mat[1][0])/X-res[1][1]);
    res[1][2]=round((mat[0][1]+mat[1][1])/X-res[1][1]);
    res[0][1]=round((mat[0][0]+mat[0][1])/X-res[1][1]);
    res[2][1]=round((mat[1][0]+mat[1][1])/X-res[1][1]);
    res[0][0]=round(mat[0][0]-res[0][1]-res[1][1]-res[1][0]);
    res[0][2]=round(mat[0][1]-res[0][1]-res[1][1]-res[1][2]);
    res[2][0]=round(mat[1][0]-res[1][0]-res[1][1]-res[2][1]);
    res[2][2]=round(mat[1][1]-res[1][2]-res[1][1]-res[2][1]);
}
void printMat(vector<vector<double> >res)
{
    for(int i=0;i<res.size();i++)
    {
        for(int j=0;j<res.size();j++)
        {
            cout<<res[i][j];
        }
        cout<<endl;
    }
}

void solve()
{
    int n;
    cin>>n;
    vector<vector<double> >mat(n,vector<double>(n));
    vector<vector<double> >res(n+1,vector<double>(n+1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>mat[i][j];
        }
    }
    if(n==1)
    {
        int x=mat[0][0];
        res[0][0]=x;
        res[0][1]=0;
        res[1][0]=0;
        res[1][1]=0;
        printMat(res);
        return;
    }
    setFirstValues(mat,res);
    for(int j=3;j<n+1;j++)
    {
        res[1][j]=round((mat[0][j-1]+mat[1][j-1])/X-res[1][j-1]);
        res[0][j]=round(mat[0][j-1]-res[0][j-1]-res[1][j-1]-res[1][j]);
        res[2][j]=round(mat[1][j-1]-res[2][j-1]-res[1][j-1]-res[1][j]);   
    }
    for(int i=3;i<n+1;i++)
    {
        for(int j=1;j<n;j++)
        {
            res[i][j]=round((mat[i-1][j-1]+mat[i-1][j])/X-res[i-1][j]);
        }
        res[i][0]=round(mat[i-1][0]-res[i-1][0]-res[i-1][1]-res[i][1]);
        res[i][n]=round(mat[i-1][n-1]-res[i-1][n]-res[i-1][n-1]-res[i][n-1]);
    }
    printMat(res);
}


int main()
{

    solve();
    return 0;
}