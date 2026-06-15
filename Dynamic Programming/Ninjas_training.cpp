//To calculate the maximum no of points gained by ninja by performing a activity out of 3 
//activites for n number of days where ninja can't perform same activity on consecutive days.
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int recursion(int day,int last,vector<vector<int>>& task) // TC-> O(expo)
{
    if(day==0)
    {
        int maxi=INT_MIN;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            {
                maxi=max(maxi,task[0][i]);
            }
        }
        return maxi;
    }   
    int maxi=INT_MIN;
    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
            int points=recursion(day-1,i,task) + task[day][i];
            maxi=max(maxi,points);
        }
    }
    return maxi;
}
int memo(int day,int last,vector<vector<int>>& task,vector<vector<int>>& dp) // TC->O(N X 4 X 3)  SC->O(N X 4)+O(N)
{
    if(day==0)
    {
        int maxi=INT_MIN;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            {
                maxi=max(maxi,task[0][i]);
            }
        }
        return maxi;
    }   
    if(dp[day][last]!=-1) return dp[day][last];
    int maxi=INT_MIN;
    for(int i=0;i<3;i++)
    {
        if(i!=last)
        {
            int points=memo(day-1,i,task,dp) + task[day][i];
            maxi=max(maxi,points);
        }
    }
    return dp[day][last]=maxi;
}
int tabulation(vector<vector<int>>& task,vector<vector<int>>& dp) // TC-> O(N X 4 X 3) SC-> O(N X 4)
{
    int n=task.size();
    for(int last=0;last<4;last++)
    {
        int maxi=INT_MIN;
        for(int i=0;i<3;i++)
        {
            if(i!=last)
            {
                maxi=max(maxi,task[0][i]);
            }   
        }
        dp[0][last]=maxi;
    }
    /* or 
    dp[0][0]=max(task[0][1],task[0][2]);
    dp[0][1]=max(task[0][0],task[0][2]);
    dp[0][2]=max(task[0][0],task[0][1]);
    dp[0][3]=max(task[0][0],task[0][1],task[0][2]);
    */
   for(int day=1;day<n;day++)
   {
        for(int last=0;last<4;last++)
        {
            int maxi=INT_MIN;
            for(int i=0;i<3;i++)
            {
                if(i!=last)
                {
                    int points=dp[day-1][i] + task[day][i];
                    maxi=max(maxi,points); 
                }
            }
            dp[day][last]=maxi;
        }
   }
   return dp[n-1][3];
}
int main()
{
    int n;
    cout<<"Enter the number of days: ";
    cin>>n;
    vector<vector<int>> task(n,vector<int>(3));
    cout<<"Enter all the points for each activity day wise: ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>task[i][j];
        }
    }
    cout<<"Maximum no of points using recursion is: "<<recursion(n-1,3,task)<<endl;
    vector<vector<int>> dp(n,vector<int>(4,-1));
    cout<<"Maximum no of points using memoization is: "<<memo(n-1,3,task,dp)<<endl;
    vector<vector<int>> dp2(n,vector<int>(4,-1));
    cout<<"Maximum no of points using tabulation is: "<<tabulation(task,dp2)<<endl;
    return 0;
}
