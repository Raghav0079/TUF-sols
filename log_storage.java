class LogSystem {
    private TreeMap<Long, Integer> logMap = new TreeMap<>();
    public LogSystem() {
        
    }
    public void put(int id, String timestamp) {
        int[] timeParts = parseTimestamp(timestamp);
        
        logMap.put(convert(timeParts), id);
    }
    public List<Integer> retrieve(String start, String end, String granularity) {
        List<Integer> result = new ArrayList<>();

        long startTime = getGranularTime(start, granularity, false);
        long endTime = getGranularTime(end, granularity, true);
        
        for (Map.Entry<Long, Integer> entry : 
             logMap.tailMap(startTime).entrySet()) {
            if (entry.getKey() >= endTime) break;
            result.add(entry.getValue());
        }
        return result;
    }

    private int[] parseTimestamp(String timestamp) {
        String[] parts = timestamp.split(":");
        int[] timeParts = new int[6];

        for (int i = 0; i < 6; i++) {
            timeParts[i] = Integer.parseInt(parts[i]);
        }
        return timeParts;
    }

    private long convert(int[] timeParts) {
        timeParts[1] = Math.max(0, timeParts[1] - 1);
        timeParts[2] = Math.max(0, timeParts[2] - 1);
        
        return (timeParts[0] - 1999L) * (31 * 12) * 24 * 60 * 60 +  
               timeParts[1] * 31 * 24 * 60 * 60 +                   
               timeParts[2] * 24 * 60 * 60 +                      
               timeParts[3] * 60 * 60 +                            
               timeParts[4] * 60 +                                  
               timeParts[5];                                    
    }

    private long getGranularTime(String timestamp, String granularity, boolean isEnd) {

        Map<String, Integer> granularityMap = Map.of(
            "Year", 0, "Month", 1, "Day", 2,
            "Hour", 3, "Minute", 4, "Second", 5
        );
        
        String[] defaultTime = {"1999", "00", "00", "00", "00", "00"};
        
        int[] timeParts = parseTimestamp(timestamp);
        
        for (int i = 0; i <= granularityMap.get(granularity); ++i) {
            defaultTime[i] = String.valueOf(timeParts[i]);
        }
        
        int[] t = new int[6];
        for (int i = 0; i < 6; i++) {
            t[i] = Integer.parseInt(defaultTime[i]);
        }
        
        if (isEnd) {
            t[granularityMap.get(granularity)]++;
        }
        
        return convert(t);
    }
}
