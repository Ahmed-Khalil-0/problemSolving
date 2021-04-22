public class Solution {
    public int NumIslands(char[][] grid) {
        bool[,] visitingReport = new bool[grid.Length, grid[0].Length];
        
        int numberOfLands = 0;
        for(int row = 0; row < grid.Length; row++){
            for(int col = 0; col < grid[row].Length; col++){
                
                if(grid[row][col] == '1' && !visitingReport[row, col])
                {
                    DFS(grid, row, col, visitingReport);
                    numberOfLands++;
                }
            }
        }
        return numberOfLands; 
    }
    
    private bool IsSave(char[][] grid, int row, int col, bool[,] visitingReport){
        return ((row >= 0) && (row < grid.Length) && (col>= 0) && (col < grid[row].Length) && ((grid[row][col] == '1')&&(!visitingReport[row,col])));
    }
    
    private void DFS(char[][] grid, int row, int col, bool[,] visitingReport){

        visitingReport[row,col] = true;
        
        int[] rowDirections = new int[]{-1,0,0,1};        
        int[] colDirections = new int[]{0,-1,1,0};

        for(int neib = 0;neib < 4; neib++){
            if(IsSave(grid,row+rowDirections[neib],col+colDirections[neib],visitingReport))    
                DFS(grid,row+rowDirections[neib],col+colDirections[neib],visitingReport);
        }
        
    }
}
