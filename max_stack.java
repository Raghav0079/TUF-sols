class MaxStack {
    private TreeMap<Integer, Integer> stack;
    private TreeMap<Integer, TreeSet<Integer>> values;
    private int cnt;

    public MaxStack() {
        stack = new TreeMap<>();
        values = new TreeMap<>();
        cnt = 0;
    }


    public void push(int x) {
        stack.put(cnt, x);
        values.putIfAbsent(x, new TreeSet<>());
        values.get(x).add(cnt);
        cnt++;
    }

    public int pop() {
        int idx = stack.lastKey();
        int val = stack.remove(idx);
        TreeSet<Integer> set = values.get(val);
        set.remove(idx);
        if (set.isEmpty()) {
            values.remove(val);
        }
        return val;
    }

    public int top() {
        return stack.lastEntry().getValue();
    }

    public int peekMax() {
        return values.lastKey();
    }


    public int popMax() {
        int maxVal = values.lastKey();
        TreeSet<Integer> set = values.get(maxVal);
        int maxIdx = set.last();
        set.remove(maxIdx);
        if (set.isEmpty()) {
            values.remove(maxVal);
        }
        stack.remove(maxIdx);
        return maxVal;
    }
}
