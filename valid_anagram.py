class Solution:
    def anagramStrings(self, s, t):
        # Edge Cases
        if len(s) != len(t):
            return False

        # To store the count of each character
        count = [0] * 26

        # Count occurrence of each character in first string 
        for c in s:
            count[ord(c) - ord('a')] += 1

        # Decrement the count for each character in the second string
        for c in t:
            count[ord(c) - ord('a')] -= 1

        # Check for count of every character
        for i in count:
            # If the count is not zero
            if i != 0:
                return False # Return false

        # Otherwise strings are anagram
        return True
