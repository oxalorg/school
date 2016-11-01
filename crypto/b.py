import string
sent = open('lol.txt').read()
print(''.join([chr(((ord(c) - ord('a') + KEY)% 26) + ord('a')) if c in string.ascii_lowercase else c for c in sent]))
#for c in sent:
#    if c in string.ascii_lowercase:
#        out += chr(((ord(c) - ord('a') + KEY)% 26) + ord('a'))
#    elif c in string.ascii_uppercase:
#        out += chr(((ord(c) - ord('A') + KEY)% 26) + ord('A'))
#    else:
#        out += c
