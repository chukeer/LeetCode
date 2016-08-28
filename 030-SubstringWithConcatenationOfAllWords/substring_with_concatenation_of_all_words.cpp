#include <stdio.h>
#include <vector>
#include <string>
#include <map>

using std::string;
using std::vector;
using std::map;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> results;
        if (words.size() == 0)
        {
            return results;
        }
        int word_len = words.begin()->size();
        int word_len_total = 0;
        map<string, int> words_count;
        for (vector<string>::iterator it = words.begin(); it != words.end(); ++it)
        {
            map<string, int>::iterator it_it = words_count.find(*it);
            if (it_it == words_count.end())
            {
                words_count[*it] = 1;
            }
            else
            {
                ++(it_it->second);
            }
            word_len_total += it->size();
        }
        int offset = 0;
        int last_ok_offset = -1;
        while (offset + word_len_total <= s.size())
        {
            int pos = offset;
            if (last_ok_offset > 0 && pos == last_ok_offset + word_len)
            {
                string left = string(s, last_ok_offset, word_len);
                string right = string(s, last_ok_offset + word_len_total, word_len);
                if (left == right)
                {
                    results.push_back(pos);
                    offset += 1;
                    continue;
                }
            }
            map<string, int> tmp_words_count = words_count;
            while (pos + word_len <= s.size())
            {
                string word = string(s, pos, word_len);
                map<string, int>::iterator it = tmp_words_count.find(word);
                if (it == tmp_words_count.end())
                {
                    break;
                }
                if (--(it->second) == 0)
                {
                    tmp_words_count.erase(it); 
                    if (tmp_words_count.size() == 0)
                    {
                        break;
                    }
                }
                pos += word_len;
            }
            if (tmp_words_count.size() == 0)
            {
                results.push_back(offset);
                last_ok_offset = offset;
            }
            offset += 1;
        }
        return results;
    }
};

void print_results(string& str, vector<string>& words, vector<int>& results)
{
    printf("str:%s\n", str.c_str());
    printf("words:\n");
    for (vector<string>::iterator it = words.begin(); it != words.end(); ++it)
    {
        printf("%s\n", it->c_str());
    }
    printf("results:\n");
    for (vector<int>::iterator it = results.begin(); it != results.end(); ++it)
    {
        printf("%d\n", *it);
    }
}

int main()
{
    Solution s;
    {
        string str = "barfoothefoobarman";
        vector<string> words;
        words.push_back("foo");
        words.push_back("bar");
        vector<int> results = s.findSubstring(str, words);
        print_results(str, words, results);
    }
    {
        string str = "barfoofoobarthefoobarman";
        vector<string> words;
        words.push_back("bar");
        words.push_back("foo");
        words.push_back("the");
        vector<int> results = s.findSubstring(str, words);
        print_results(str, words, results);
    }
    {
        string str = "aaaaaaaa";
        vector<string> words;
        words.push_back("aa");
        words.push_back("aa");
        words.push_back("aa");
        vector<int> results = s.findSubstring(str, words);
        print_results(str, words, results);
    }

    return 0;
}
