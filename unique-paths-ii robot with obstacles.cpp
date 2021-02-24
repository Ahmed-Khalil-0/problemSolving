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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        unordered_map<pair<int, int>,int, hash_pair> uMap;
        if(obstacleGrid[obstacleGrid.size()-1][obstacleGrid[0].size()-1]==1){
            return 0;
        }
        return uniquePaths(obstacleGrid.size(),obstacleGrid[0].size(),uMap,obstacleGrid);
    }
    //With DP
    int uniquePaths(int m, int n, unordered_map<pair<int, int>,int, hash_pair>& uMap, vector<vector<int>>& obstacleGrid) {

        int path = 0;
        pair<int, int> p(m, n);
        if(uMap.find(p) != uMap.end()){
            return uMap[p];
        }else{
            if(m == 1 && n == 1)
                return 1;
            
            //go up 
            if( m > 0){
                if(!isObstacle(m-2, n-1, obstacleGrid)){
                    path += uniquePaths(m-1,n,uMap,obstacleGrid);
                    p.first = m;
                }
            }
            //go left
            if(n > 0){
                if(!isObstacle(m-1, n-2, obstacleGrid)){
                    path += uniquePaths(m,n-1,uMap,obstacleGrid);
                    p.second = n;
                }
            }
            uMap[p] = path;
            return path; 
        }

    }
    
    bool isObstacle(int r, int c,vector<vector<int>>& obstacleGrid){
        if(r < obstacleGrid.size() && r > -1 && c < obstacleGrid[0].size() && c > -1){
            if(obstacleGrid[r][c] == 1){
            return true;
            }  
        }
        return false;
    }
};
