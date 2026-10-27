import java.util.*;

class Counter {
    // Static variable to track the number of objects created
    private static int count = 0;

    // Default constructor increments the count
    public Counter() {
        count++;
    }

    // Static method to get the current count
    public static int getCount() {
        return count;
    }

    public static void resetCount() {
        count = 0;
    }
}

class Main15 {
    public static void main(String[] args) {
        // Hardcoded input count = 10
        int count = 10;

        // Create 10 objects
        for (int i = 0; i < count; i++) {
            new Counter();  // Creating Counter objects
        }

        // Output the count of objects created
        System.out.println("Number of objects created : " + Counter.getCount());
    }
}