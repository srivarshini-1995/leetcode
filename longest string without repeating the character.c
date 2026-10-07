#include <string.h>

int lengthOfLongestSubstring(char* s) {
   
    int last_seen[256];
    for (int i = 0; i < 256; i++) {
        last_seen[i] = -1;
    }
    
    int max_len = 0;
    int start = 0; 
    
    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char current_char = s[i];
        
        
        if (last_seen[current_char] >= start) {
            start = last_seen[current_char] + 1;
        }
        
        // Update the last seen position of the character
        last_seen[current_char] = i;
        
        
        int current_len = i - start + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
    }
    
    return max_len;
}
