// 78.  SUBSET  (LEETCODE)

/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

*/

#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

void solve(int index,vector<int>& ans, int arr[], int n)
{
    if(index == n)   // Base Case
    {
        for(auto it:ans)
        {
            cout<< it << " ";
        }
        if(ans.size() == 0)
        {
            cout<< "{}" ;
        }
        cout<<endl;
        return;
    }
   
    solve(index+1,ans,arr,n);

    ans.push_back(arr[index]); // take or pick the particular index into the subsequences
    solve(index+1,ans,arr,n);
    
    ans.pop_back();  // not pick,this element is not added to your subsequences

   
}


int main()
{

    int arr[] = {1, 2, 3};
    int n = 3;
    vector<int> ans;
    
    int index = 0;
    solve(index,ans,arr,n);

    return 0;
}
