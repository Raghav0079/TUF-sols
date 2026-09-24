#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// Helper function to check if a non-overlapping repeated substring of length L exists
bool hasNonOverlapping(const string& s, int L, int& start_idx) {
    if (L == 0) return true;
    int n = s.length();
    unsigned long long hash_val = 0;
    unsigned long long power = 1;
    unsigned long long BASE = 31;

    // Calculate hash for the first window of length L
    for (int i = 0; i < L; i++) {
        hash_val = hash_val * BASE + s[i];
        if (i > 0) power *= BASE;
    }

    unordered_map<unsigned long long, int> first_occurrence;
    first_occurrence[hash_val] = 0;

    // Slide the window across the rest of the string
    for (int i = L; i < n; i++) {
        hash_val = hash_val - s[i - L] * power;
        hash_val = hash_val * BASE + s[i];

        int prev_idx = i - L + 1;
        if (first_occurrence.find(hash_val) == first_occurrence.end()) {
            first_occurrence[hash_val] = prev_idx;
        } else {
            // Check if the current occurrence does not overlap with the first occurrence
            if (prev_idx >= first_occurrence[hash_val] + L) {
                start_idx = prev_idx;
                return true;
            }
        }
    }
    return false;
}

// Function to find the longest non-overlapping repeated substring
string longestNonOverlappingSubstring(const string& s) {
    int n = s.length();
    int low = 0, high = n;
    int best_len = 0;
    int best_start = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int temp_start = -1;
        
        if (hasNonOverlapping(s, mid, temp_start)) {
            best_len = mid;
            best_start = temp_start;
            low = mid + 1; // Try to find a longer substring
        } else {
            high = mid - 1; // Try a shorter length
        }
    }

    if (best_len == 0) return "";
    return s.substr(best_start, best_len);
}

int main() {
    string s = "banana";
    cout << "Input string: " << s << endl;
    cout << "Longest non-overlapping substring: " << longestNonOverlappingSubstring(s) << endl;
    return 0;
}