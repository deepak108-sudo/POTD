//--------------t.c: O(n^2)-------------------
//--------------s.c: O(n^2)-------------------

class Solution {
    pair<int,int> findCoord(int num,int &n)
    {
        int row=(num-1)/n;               //Formula -> (num-1)/Total no. of rows
        int row_bottom=(n-1)-row;       //total - row from up..........0 based so used (n-1)

        int col=(num-1)%n;              //Formula -> (num-1)%Total no. of cols

        //here left-> right and right->left (problem)
        //We use observation
        if((row_bottom %2==0 && n%2==0) || (row_bottom%2!=0 && n%2!=0))     //right->left
        {
            col=(n-1)-col;              //total - col
        }

        return {row_bottom,col};
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();

        vector<vector<int>> visited(n,vector<int>(n,0));
        queue<int> q;
        q.push(1);
        visited[n-1][0]=1;
        int step=0;

        while(!q.empty())
        {
            int N=q.size();
            while(N--)
            {
                int curr=q.front();
                q.pop();

                for(int k=1;k<=6;k++)
                {
                    int next=curr+k;

                    if(curr==n*n){          //If trget found then return
                        return step;
                    }

                    if(next>n*n)
                    {
                        break;
                    }

                    auto [r,c]=findCoord(next,n);

                    if(visited[r][c]!=1)  //Not visited
                    {
                        if(board[r][c]==-1)
                        {
                            q.push(next);
                        }
                        else{
                            q.push(board[r][c]);    //Ladder or snake
                        }

                        visited[r][c]=1;
                    }
                }
            }
            step++;
        }
        return -1;      //Target not found
    }
};