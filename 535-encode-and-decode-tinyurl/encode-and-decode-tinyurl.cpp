class Solution {
   private:
   string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

   unordered_map<string, string> urlToCode, codeToUrl;
public:
   

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code;
        // as long as the url is not in map we need to keeep trying to generate new codes 
        while(urlToCode.find(longUrl) == urlToCode.end()){
           random_shuffle(chars.begin(), chars.end());
            code = chars.substr(0,6);
            if(codeToUrl.find(code) == codeToUrl.end()){
                codeToUrl[code] = longUrl;
                urlToCode[longUrl] = code;
            }
        }
        return "http://tinyurl.com/" + code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        // pos has / 
        int pos = shortUrl.find_last_of("/");
        return codeToUrl[shortUrl.substr(pos+1)]; // so pos+1

    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));