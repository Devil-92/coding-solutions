// Question Number 3043 //
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size() ;
        int m = arr2.size() ;
        int ans = 0 ; 
        set<string> s ;
        for(int i = 0 ; i < n ; i++)
        {
            string e = to_string(arr1[i]) ;
            string p = "" ;
            for(int i = 0 ; i < e.size() ; i++)
            {
                p += e[i] ;
                s.insert(p) ;
            }
        }
        for(int i = 0 ; i < m ; i++)
        {
            string e = to_string(arr2[i]) ;
            string p = "" ;
            for(int i = 0 ; i < e.size() ; i++)
            {
                p += e[i] ;
                if(s.count(p))
                {
                    ans = max(ans , i+1) ;
                }
            }
        }
        return ans ;
    }
};
