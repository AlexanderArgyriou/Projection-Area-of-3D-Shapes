class Solution 
{
    private:
        inline void Rotate(const std::vector<std::vector<int>> &s, std::vector<std::vector<int>> &d) const noexcept
        {
            for( std::size_t i = 0; i < s.size(); ++i )
                for( std::size_t j = 0; j < s[i].size(); ++j )
                    d[i][j] = s[j][i];
        }   // Rotate
    
    public:
        inline int projectionArea(std::vector<std::vector<int>> &grid) const noexcept
        {
            std::size_t xy_proj = 0;
            std::size_t xz_proj = 0;
            std::size_t yz_proj = 0;
            
            std::vector<std::vector<int>> RotatedGrid( grid.size() );
            for( auto &row : RotatedGrid )
                row.resize( grid.size() );
            
            // DownSide 2D projection's(xy) area, is the number of non zero elements in the grid, every cube(1x1x1) have area = 1.
            // FrontSide 2D projection's(xz) area is the sum of the max elements of every row in the grid, because the "highest" tower
            // of cubes in every row "makes" the shadow.
            for( std::size_t i = 0; i < grid.size(); ++i )
            {
                xz_proj += *max_element( grid[i].begin(), grid[i].end() );
                for( std::size_t j = 0; j < grid[i].size(); ++j )
                    if( grid[i][j] )
                        ++xy_proj;    
            }
        
            // BackSide 2D projection's(xz) area is the sum of the max elements of every col in the grid, because the "highest" tower
            // of cubes in every col "makes" the shadow.
            Rotate( grid, RotatedGrid );
            for( std::size_t i = 0; i < RotatedGrid.size(); ++i ) 
                yz_proj += *max_element( RotatedGrid[i].begin(), RotatedGrid[i].end() );
        
            return xy_proj + xz_proj + yz_proj;
        }   // projectionArea
};  // Solution
