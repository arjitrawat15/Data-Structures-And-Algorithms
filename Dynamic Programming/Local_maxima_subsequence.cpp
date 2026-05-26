/* You are given an permutation array of size and a integer K. You must select a subsequence of array with exactly k length
The weight is calculated as sum of local maxima with subsequence. Your goal is to maximise the weight of subsequence.
Find maximum possible weight amoung all the subsequence of length K. 
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
//1 5 2 4 3
void solve(int ind,vector<int>& sub,int k,int &maxi,vector<int>& arr)
{
    if(sub.size()==k)
    {
        int sum=0;
        for(int i=0;i<sub.size();i++)
        {
            if(i==0)
            {
                if(sub[i]>sub[i+1])
                {
                    sum+=sub[i];
                }
            }
            else if(i==sub.size()-1)
            {
                if(sub[i]>sub[i-1])
                {
                    sum+=sub[i];
                }
            }
            else
            {
                if(sub[i]>sub[i-1] && sub[i]>sub[i+1])
                {
                    sum+=sub[i];
                }
            }
        }
        maxi=max(maxi,sum);
        return;
    }
    if(ind==arr.size())
    {
        return;
    }
    sub.push_back(arr[ind]);
    solve(ind+1,sub,k,maxi,arr);
    sub.pop_back();
    solve(ind+1,sub,k,maxi,arr);
    return;
}
int main()
{
    int n,k;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the size k: ";
    cin>>k;
    int maxval=0;
    for(int i=0;i<n;i++)
    {
        maxval=max(maxval,arr[i]);
    }
    if(k==1)
    {
        cout<<"Maximum sum of local maxima is: "<<maxval;
        return 0;
    }
    int maxi=INT_MIN;
    vector<int>sub;
    solve(0,sub,k,maxi,arr);
    cout<<"Maximum sum of local maxima is: "<<maxi;
    return 0;
}*/
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    cin >> k;
    sort(arr.begin(), arr.end(), greater<int>());
    int peaks = (k + 1) / 2;
    int sum = 0;
    for(int i = 0; i < peaks; i++)
    {
        sum += arr[i];
    }
    cout << "Maximum sum of local maxima is: " << sum;
}