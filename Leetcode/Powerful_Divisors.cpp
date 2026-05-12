/*
Platform: InterviewBit
Problem: Powerful Divisors
Topic: Math, Sieve
Difficulty: Medium
Link: https://www.interviewbit.com/problems/powerful-divisors/

Approach:
- Count divisors for every number using modified sieve
- Check if divisor count is power of 2 ( x & (x-1) )
- Prefix sum preprocessing

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

vector<int> Solution::powerfulDivisors(vector<int> &A) {
    int maxm = A[0] ;
    for(auto i : A)
    {
        maxm = max(maxm , i) ; 
    }
    int n = A.size() ;
    vector<int> div_c(maxm+1) ;
    for(int i = 1 ; i <= maxm ; i++)
    {
        for(int j = i ; j <= maxm ; j+=i)
        {
            div_c[j]++;
        }
    }
    vector<int> count(maxm+1) ;
    count[1] = 1 ;
    for(int i = 2 ; i <= maxm ; i++)
    {
        int x = div_c[i] ;
        if((x & (x - 1)) == 0)
        {
            count[i] = 1 ;
        }
    }
    for(int i = 2 ; i <= maxm ; i++)
    {
        count[i] += count[i-1] ;
    }
    vector<int> ans(n) ;
    for(int i = 0 ; i < n ; i++)
    {
        ans[i] = count[A[i]] ;
    }
    return ans ;
}
