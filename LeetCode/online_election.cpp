class TopVotedCandidate {
public:
    vector<int> person;
    vector<int> time;
    vector<int> winner;
    
    map<int, int> votes;
    
    int max_votes = 0;
    int person_idx = -1;
    
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        person = persons;
        time = times;
        int c0 = 0, c1 = 0;
        
        for(int i=0; i<person.size(); i++)
        {
            int x = person[i];
            votes[x]++;
            if(votes[x] >= max_votes)
            {
                max_votes = votes[x];
                person_idx = x;
            }
            winner.push_back(person_idx);
        }
    }
    
    int q(int t) {
        int idx = b_search(time, 0, time.size() - 1, t);
        if(idx >= time.size())
            idx = time.size() - 1;
        return winner[idx];
    }
    
    int b_search(vector<int> &time, int l, int r, int target)
    {
        while(l <= r)
        {
            int mid = (l + r) / 2;
            
            if(time[mid] == target)
                return mid;
            else if(time[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        
        return r;
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */