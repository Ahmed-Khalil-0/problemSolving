public class Solution {
    public int OrangesRotting(int[][] grid) {
        
        /*search for the rotting orange in grid*/
        List<(int X,int Y)> nextVisit = new List<(int X,int Y)>(); 
        (int X,int Y) startPoint = (0,0);
        bool HasFreshOne = false;
        for(int row = 0; row < grid.Length ; row++){
            for(int col = 0; col < grid[row].Length; col++){
                if(grid[row][col] == 2){
                    startPoint.X = row;
                    startPoint.Y = col;
                    nextVisit.Add(startPoint);
                }
                if(grid[row][col] == 1){
                    HasFreshOne = true;
                }
            }
        }
        
        if(grid[startPoint.X][startPoint.Y] != 2 && !HasFreshOne)
            return 0;
        if(grid[startPoint.X][startPoint.Y] != 2){
            return -1;
        }
        
        if(!HasFreshOne){
            return 0;
        }

        int count = 0;
               
        List<(int X,int Y)> nextVisitTemp = new List<(int X,int Y)>();

        
        while(nextVisit.Count > 0){
            foreach((int X,int Y) node in nextVisit){
                //Console.WriteLine(node);
                GetNodeChilds(node.X,node.Y,grid,nextVisitTemp);
            } 
            nextVisit.Clear();
            nextVisit.AddRange(nextVisitTemp);
            if(nextVisitTemp.Count != 0)
                count++;
            nextVisitTemp.Clear();
        }
        
        for(int row = 0; row < grid.Length ; row++){
            for(int col = 0; col < grid[row].Length; col++){
                if(grid[row][col] == 1){
                    return -1;
                }
            }
        }
        return count;
    }
    
    private void GetNodeChilds(int x, int y,int[][] grid,List<(int,int)> nextVisit){
        if(x+1 < grid.Length){
            if(grid[x+1][y] == 1){
                nextVisit.Add(((x+1),y));
                grid[x+1][y] = 2;
            }
        }
        if(y+1 < grid[0].Length){
            if(grid[x][y+1] == 1){
                nextVisit.Add((x,(y+1)));
                grid[x][y+1] = 2;
            }
        }
        if(x-1 >= 0){
            if(grid[x-1][y] == 1){
                nextVisit.Add(((x-1),y));
                grid[x-1][y] = 2;
            }
        }
        if(y-1 >= 0){
            if(grid[x][y-1] == 1){
                nextVisit.Add((x,(y-1)));
                grid[x][y-1] = 2;
            }
        }
    }
    
}
