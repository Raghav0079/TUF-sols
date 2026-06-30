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

        // Sliding window to store bits read from the stream
        vector<int> window;

        // Index to track the number of bits read so far
        int index = 0;

        // Infinite loop to continuously read bits from the stream
        while (true) {

            // Get the next bit from the stream
            int bit = stream->next();

            // Add the bit to the window
            window.push_back(bit);

            // Only start checking for pattern once window size is at least pattern length
            if(window.size() >= patternLength) {

                // Assume it is a match until proven otherwise
                bool match = true;

                // Check the last 'patternLength' bits in the window with the pattern
                for(int i = 0; i < patternLength; i++) {
                    if(window[window.size() - patternLength + i] != pattern[i]){
                        match = false;
                        break;
                    }
                }

                // If a match is found, return the starting index of the pattern in the stream
                if(match) {
                    return index - patternLength + 1;
                }
            }

            // Move to the next bit
            index++;
        }

        // Return -1 (just in case, although unreachable in valid input)
        return -1;
    }
};
