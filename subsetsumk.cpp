/*
Given an integer array nums,return all possible subsequences whose sum is equal to 
given target.

Example:

Input: nums = [1,2,1]  Target = 2 
Output: [[2],[1,1]]
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int index,vector<int>& ans,int sum,int target,int nums[],int size)
{
    if(index == size)
    {
        if(sum == target)
        {
            for(auto it: ans)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
        /*
        if(sum != target)
        {
            for(auto it: ans)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
        */

        
        return;
    }

    ans.push_back(nums[index]);
    sum+= nums[index];

    solve(index+1,ans,sum,target,nums,size);

    sum-= nums[index];
    ans.pop_back();
   

    solve(index+1,ans,sum,target,nums,size);


}

int main()
{

    int nums[] = {1, 2, 1};
    int n = 3;
    int target = 2;
    vector<int> ans;

    solve(0,ans,0,target,nums,n);

    return 0;
}
