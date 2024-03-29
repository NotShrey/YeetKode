import java.util.HashMap;

public class Solution {
    public String minWindow(String s, String t) {
        String result = "";
        int min = Integer.MAX_VALUE;
        int i = 0;
        int j = 0;
        HashMap<Character, Integer> map = new HashMap<>();
        int count = t.length(); 

        for (char c : t.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        while (j < s.length()) {
            if (map.containsKey(s.charAt(j))) {
                map.put(s.charAt(j), map.get(s.charAt(j)) - 1);
                if (map.get(s.charAt(j)) >= 0) { 
                    count--;
                }
            }

            while (count == 0) {
                if (min > j - i + 1) {
                    result = s.substring(i, j + 1);
                    min = result.length();
                }

                if (map.containsKey(s.charAt(i))) {
                    map.put(s.charAt(i), map.get(s.charAt(i)) + 1);

                    if (map.get(s.charAt(i)) > 0) {
                        count++;
                    }
                }
                i++;
            }
            
            j++;
        }
        return result;
    }
}