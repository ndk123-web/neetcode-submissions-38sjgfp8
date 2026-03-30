class Solution {

    public String encode(List<String> strs) {
        StringBuilder encoded = new StringBuilder();

        for (String s : strs){
            encoded.append(s.length()).append("#").append(s);
        }

        return encoded.toString();
    }

        // -> 4 # n e e t 3 # y o  u   
        // -> 0 1 2 3 4 5 6 7 8 9  10

    public List<String> decode(String str) {
        List<String> ans = new ArrayList<>();
        int i = 0;
        int j;

        while (i < str.length()){
            j = i;
            while (str.charAt(j) != '#'){
                j++;
            }
            int curr_len = Integer.parseInt(str.substring(i,j));
            i = j + 1;
            ans.add(str.substring(i,i+curr_len));
            i = i + curr_len;
        }
        return ans;
    }
}
