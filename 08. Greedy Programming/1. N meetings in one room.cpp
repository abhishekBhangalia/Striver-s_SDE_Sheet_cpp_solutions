class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int finish[], int n)
    {
        vector<pair<int,int>> acts;
    
        for(int i=0; i<n; i++){
            acts.push_back({finish[i], start[i]});
        }
        sort(acts.begin(), acts.end());
    
        int time = 0;
        int max_acts = 0;
        for(const auto& a:acts){
            if(a.second > time){
                time = a.first;
                max_acts++;
            }
        }
        return max_acts;
    }
};
