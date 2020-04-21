bool sortcomp(const vector<int>& v1, const vector<int>& v2)
{
    return (v1[0] > v2[0] || ( (v1[0] == v2[0]) && (v1[1] < v2[1]) ) );
}

class Solution {
public:
 
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        sort(people.begin(), people.end(), sortcomp);
        vector<vector<int>> peopleAfter;
        for (int i = 0; i < people.size(); i++) {
            if (people[i][1] == peopleAfter.size()) {
                peopleAfter.push_back(people[i]);
            } else {
                peopleAfter.insert(peopleAfter.begin() + people[i][1],
                                   people[i]);
            }
        }
        return peopleAfter;
    }
};