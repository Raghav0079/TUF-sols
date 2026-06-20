class Solution {
public:
    void pattern22(int n) {
        int size = 2 * n - 1;
        
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                // Calculate distance from all 4 edges
                int top = i;
                int bottom = size - 1 - i;
                int left = j;
                int right = size - 1 - j;
                
                // Value is n minus the minimum distance to any edge
                int value = n - min({top, bottom, left, right});
                
                // Print the value followed by a trailing space
                cout << value << " ";
            }
            // Move to the next line after completing a row
            cout << endl;
        }
    }
};