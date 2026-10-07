class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int i = 0;

        while (i < chars.size()) {

            char current = chars[i];
            int count = 0;

            // Count consecutive characters
            while (i < chars.size() && chars[i] == current) {
                count++;
                i++;
            }

            // Write the character
            chars[write] = current;
            write++;

            // Write the count
            if (count > 1) {
                string countStr = to_string(count);

                for (char digit : countStr) {
                    chars[write] = digit;
                    write++;
                }
            }
        }

        return write;
    }
};