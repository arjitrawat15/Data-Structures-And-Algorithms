# Approach 1- 
#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;++)
  {
    cin>>arr[i];
  }
  int target;
  cin>>target;
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
{
if(nums[i]+nums[j]==target)
{
return true; //exists
}
}
}
