class Solution {
public:
    int solve(vector<int> &satisfaction , int index , int time){
        //base case
        if(index == satisfaction.size())
            return 0;

        int include = satisfaction[index] * (time+1) + solve(satisfaction , index+1 , time+1);
        int exlude = 0 + solve(satisfaction , index+1 , time);

        return max(include , exlude); 
    }
    //Memorization
    int solveMem(vector<int> &satisfaction , int index , int time , vector<vector<int> > &dp){
        //base case
        if(index == satisfaction.size())
            return 0;

        if(dp[index][time] != -1)
            return dp[index][time];

        int include = satisfaction[index] * (time+1) + solveMem(satisfaction , index+1 , time+1 , dp);
        int exlude = 0 + solveMem(satisfaction , index+1 , time , dp);

        return dp[index][time] = max(include , exlude); 
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        //sort the vector
        sort(satisfaction.begin() , satisfaction.end());
        // return solve(satisfaction , 0 , 0);

        int n = satisfaction.size();

        vector<vector<int> > dp(n+1 , vector<int> (n+1 , -1));
        
        return solveMem(satisfaction , 0 , 0 , dp);
    }
};