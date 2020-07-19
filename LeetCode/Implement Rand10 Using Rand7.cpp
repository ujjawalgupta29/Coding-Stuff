// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

//Note: N^b * (randN() - 1) + N^(b - 1) * (randN() - 1) + N^(b - 2) * (randN() - 1) + ... + N^0 * (randN() - 1) generates randX() - 1, where X = N^(b + 1).

//https://leetcode.com/problems/implement-rand10-using-rand7/discuss/150301/Three-line-Java-solution-the-idea-can-be-generalized-to-%22Implement-RandM()-Using-RandN()%22

class Solution {
public:
    int rand10() {
        int num = 40;
        //num is selected as the highest number div by 10 in range 0-48
        while(num >= 40)
        {
            num = (rand7() - 1) * 7 + rand7() - 1; 
        }
        
        return num%10 + 1;
    }
};