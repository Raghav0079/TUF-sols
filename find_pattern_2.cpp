/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 * public:
 *     InfiniteStream(vector<int> bits);
 *     int next();
 * };
 */

class Solution {
public:
    int findPattern(InfiniteStream* stream, vector<int>& pattern) {
        int patternLength = pattern.size();
        vector<int> lps(patternLength, 0);

        int len = 0, i = 1;
        while (i < patternLength) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int streamIndex = 0, patternIndex = 0;
         while (true) {
            int currentBit = stream->next();

            /*If mismatch occurs, move the pattern
            index using the LPS array*/
            while (patternIndex > 0 && 
                   currentBit != pattern[patternIndex]) {
                patternIndex = lps[patternIndex - 1];
            }

            // If current bit matches, move ahead
            if (currentBit == pattern[patternIndex]) {
                patternIndex++;
            }
            if (patternIndex == patternLength) {
                return streamIndex - patternLength + 1;
            }

            streamIndex++;
        }
        return -1;


    }
};
