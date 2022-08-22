class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size(),sum=0;
        vector <int> v(n+1,0);
        int cnt=0;
        for(int i=0;i<shifts.size();i++){
            int l=shifts[i][0];
            int r=shifts[i][1];
            if(shifts[i][2]==0){
                v[l]--;
                v[r+1]++;
            }
            else{
                v[l]++;
                v[r+1]--;
            }
            cnt++;
           // cout<<v[i]<<" ";
        }
        
        //for(int i=0;i<v.size();i++) cout<<v[i]<<" ";
        for(int i=0;i<n;i++)
        {
            sum+=v[i];
            // cout<<sum<<" ";
            int k=sum%26;
            int p=(s[i]-'a'+k+26)%26;
           // cout<<p<<" ";
            
            s[i]=char('a'+p);
        }
        return s;
    }
};















// class Solution {
// public:
//     string shiftingLetters(string s, vector<vector<int>>& shifts) {
//         int i=0;
        
//         while(i<shifts.size())
//         {
//             int start = shifts[i][0];
//             int end   = shifts[i][1];
//             int direction = shifts[i][2];
            
//             if(direction) //forward
//             {
//                 for(int j=start;j<=end;j++)
//                 {
//                     if(s[j] == 'z') 
//                     {
//                         s[j] = 'a';
//                         continue;
//                     }
//                     s[j] = s[j] + 1;  
//                 }
//             }
            
//             else  //backward
//             {
//                 for(int j=start;j<=end;j++)
//                 {
//                     if(s[j]=='a')
//                     {   
//                         s[j] = 'z';
//                         continue;
//                     }
//                     s[j] = s[j] - 1;
//                 }
//             }
            
//             i++;
//         }
//         return s;
//     }
    
// };