class Solution:
    def frequencySort(self, s):
        # Frequency array for characters 'a' to 'z'
        freq = [(0, chr(i + ord("a"))) for i in range(26)]

        # Count frequency of each character
        for ch in s:
            index = ord(ch) - ord("a")
            freq[index] = (freq[index][0] + 1, ch)

        # Sort by frequency (descending) and alphabetically (ascending)
        freq.sort(key=lambda x: (-x[0], x[1]))

        # Collect characters with non-zero frequency
        result = [ch for f, ch in freq if f > 0]
        return result
