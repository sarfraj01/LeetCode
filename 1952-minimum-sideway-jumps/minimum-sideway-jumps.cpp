class Solution {
public:
    int solve(vector<int> &obstacles , int currlane , int currpos){
        //base case
        int n = obstacles.size()-1;
        if(currpos == n)
            return 0;

        if(obstacles[currpos + 1] != currlane){
            return solve(obstacles , currlane , currpos+1);
        }

        else{

            //sideway jumps
            int ans = INT_MAX;
            for(int i = 1; i <= 3; i++){
                if(currlane != i && obstacles[currpos] != i)
                    ans = min(ans , 1 + solve(obstacles , i , currpos));
            }
            return ans;
        }
    }
    //Memorization
    int solveMem(vector<int> &obstacles , int currlane , int currpos , vector<vector<int> > &dp){
        //base case
        int n = obstacles.size()-1;
        if(currpos == n)
            return 0;

        if(dp[currlane][currpos] != -1)
            return dp[currlane][currpos];

        if(obstacles[currpos + 1] != currlane){
            return solveMem(obstacles , currlane , currpos+1 , dp);
        }

        else{

            //sideway jumps
            int ans = INT_MAX;
            for(int i = 1; i <= 3; i++){
                if(currlane != i && obstacles[currpos] != i)
                    ans = min(ans , 1 + solveMem(obstacles , i , currpos , dp));
            }
            dp[currlane][currpos] = ans;
            return dp[currlane][currpos];
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        //return solve(obstacles , 2 , 0);

        //Memorization
        vector<vector<int> > dp(4 , vector<int> (obstacles.size() , -1));
        return solveMem(obstacles , 2 , 0 , dp);
    }
};