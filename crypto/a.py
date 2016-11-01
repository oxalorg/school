import string
print(''.join([chr(((ord(c) - ord('a') + 3)% 26) + ord('a')) if c in string.ascii_lowercase else c for c in input()]))
