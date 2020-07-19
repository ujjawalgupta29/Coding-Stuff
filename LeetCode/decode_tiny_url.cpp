class Solution {
public:

    unordered_map<string, string> mp;
    string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl;
        for(int i=0; i<5; i++)
        {
            int n = rand() % (s.size());
            shortUrl += s[n];
        }
        mp[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));