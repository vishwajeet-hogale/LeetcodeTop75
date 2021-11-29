def shortestPalindrome(s):
    length = len(s)
    while(length>0):
        if(s[:length] == s[:length][::-1]):
            break
        length -= 1
    return s[length:][::-1] + s