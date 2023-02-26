class Solution {
public:

    bool issafe(char ch, int r, int c, vector<vector<char>> &mat){

        //row-checking
        for(int i=0;i<9;i++){
            if(mat[r][i]==ch){
                return false;
            }
        }
        
        //col-checking
        for(int i=0;i<9;i++){
            if(mat[i][c]==ch){
                return false;
            }
        }

        int x,y,i,j;
        x = r/3*3;
        y = c/3*3;

        //3x3 diag checking
        for(i=x;i<x+3;i++){
            for(j=y;j<y+3;j++){
                if(mat[i][j]==ch){
                    return false;
                }
            }
        }

        return true;
    }

    void solve(int r, int c, vector<vector<char>> &mat, vector<vector<char>> &ans){

        if(r==8 && c==9){
            ans = mat;
        }

        else{

            if(c==9){
                //we need to start from next row
                r+=1;
                c=0;
            }

            if(mat[r][c]=='.'){

                //try all possible moves i.e. 1 to 9
                for(int i=1;i<=9;i++){
                    char ch = i + '0';
                    if(issafe(ch,r,c,mat)){
                        mat[r][c] = ch;
                        solve(r,c+1,mat,ans);
                        mat[r][c] = '.';
                    }
                }
            }

            else{
                solve(r,c+1,mat,ans);//block already filled, go to next
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board) {
        
        vector<vector<char>> ans;
        solve(0,0,board,ans);
        board = ans;
    }
};
