class Solution {
    struct hash_pair{
      template <class T1, class T2> 
      size_t operator()(const pair<T1, T2>& p) const
      {
          auto hash1 = hash<T1>{}(p.first);
          auto hash2 = hash<T2>{}(p.second);
          return hash1 ^ hash2; 
      }
    };
public:
    //without DP
    int uniquePaths(int m, int n) {
        int path = 0;
        unordered_map<pair<int, int>,int, hash_pair> kmap;
        path = uniquePaths(m,n,kmap);
        return path;
    }
    
    //without DP 
    int uniquePathsWithoutDP(int m, int n){
        int path = 0;
        if(m == 1 && n == 1)
            return 1;
        //go up 
        if( m >= 0)
          path += uniquePaths(m-1,n);
        //go left
        if(n >= 0)
          path += uniquePaths(m,n-1);
        
        return path;
    }
    //DP Iterator
    int uniquePathsDPIt(int m, int n) {
    vector<int> cur(n, 1);
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                cur[j] += cur[j - 1];
            }
        }
        return cur[n - 1];
    }
    //With DP
    int uniquePaths(int m, int n, unordered_map<pair<int, int>,int, hash_pair>& uMap) {
        int path = 0;
        pair<int, int> p(m, n);
        if(uMap.find(p) != uMap.end()){
            return uMap[p];
        }else{
            if(m == 1 && n == 1)
                return 1;
            //go up 
            if( m > 0){
                path += uniquePaths(m-1,n,uMap);
                p.first = m;
            }
            //go left
            if(n > 0){
                path += uniquePaths(m,n-1,uMap);
                p.second = n;
            }
            uMap[p] = path;
            return path; 
        }

    }

};
