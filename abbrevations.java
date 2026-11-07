class Solution {
    public void storeAbbreviations(List<String> abbreviations, String word,
                                   String currWord, int index, int abbreviatedCount) {

        if (index == word.length()) {
            currWord +=
                abbreviatedCount == 0 ? "" : Integer.toString(abbreviatedCount);

            abbreviations.add(currWord);
            return;
        }

        String abbreviatedString =
            abbreviatedCount == 0 ? "" : Integer.toString(abbreviatedCount);

        storeAbbreviations(abbreviations, word,
                           currWord + abbreviatedString + word.charAt(index),
                           index + 1, 0);
        storeAbbreviations(abbreviations, word, currWord, index + 1,
                           abbreviatedCount + 1);
    }
    public List<String> generateAbbreviations(String word) {
        List<String> abbreviations = new ArrayList<>();

        storeAbbreviations(abbreviations, word, "", 0, 0);
        return abbreviations;
    }
}

