//Flood fill algorithm using DFS to colour all the connected components to sr and sc who has initial colour 
//TC-> O(N x M)
//SC-> O(N x M) + O(N X M) ~ O(N X M)  
#include<iostream>
#include<vector>
using namespace std;
void dfs(int row,int col,vector<vector<int>>& ans,vector<vector<int>>& image,int colour,int initial,int n,int m)
{
    ans[row][col]=colour;
    int delr[4]={-1,0,+1,0};
    int delc[4]={0,-1,0,+1};
    for(int i=0;i<4;i++)
    {
        int nrow=delr[i]+row;
        int ncol=delc[i]+col;
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && image[nrow][ncol]==initial && ans[nrow][ncol]!=colour)
        {
            dfs(nrow,ncol,ans,image,colour,initial,n,m);
        }
    }
}
int main()
{
    int n,m;
    cout<<"Enter the total rows: ";
    cin>>n;
    cout<<"Enter the total cols: ";
    cin>>m;
    cout<<"Enter the image: ";
    vector<vector<int>> image(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>image[i][j];
        }
    }
    int sr,sc,colour;
    cout<<"Enter the starting row and col: ";
    cin>>sr>>sc;
    cout<<"Enter the new colour: ";
    cin>>colour;
    int initial=image[sr][sc];
    vector<vector<int>> ans=image;
    dfs(sr,sc,ans,image,colour,initial,n,m);
    cout<<"Modified image after flood fill algorithm: "<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}