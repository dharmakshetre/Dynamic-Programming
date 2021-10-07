// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int editDistance(string s, string t) {
        // Code here
        int m = s.length();
        int n = t.length();
        int mat[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0){
                    mat[i][j]=j;     //when 1st string is empty
                }
                else if(j==0){
                    mat[i][j]=i;     //when 2nd string is empty                    
                }
                else if(s[i-1]==t[j-1]){
                    mat[i][j] = mat[i-1][j-1];   //when character is same, no operation                                                
                }
                else{
                    int a = mat[i][j-1]; //insert
                  int b = mat[i-1][j];   //remove
                  int c = mat[i-1][j-1]; //replace
                   int l;
                   if(a<b && a<c){
                     l  = a;
                   }
                   else if(b<c){
                     l = b;
                   }
                   else{
                     l = c;
                   }
                    mat[i][j] = 1 + l;
                }
            }
        }
        return mat[m][n];
    }
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
