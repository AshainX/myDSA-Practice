# Online Python compiler (interpreter) to run Python online.
# Write Python 3 code in this online editor and run it.

def isReflectionEqual(s):
    # Write your code here.
    start = 0 
    end = len(s) - 1
    mirror = {'A','W','T','Y','U','I','O','H','X','V','M'}
    #mirror2 = set("WTUIOAHXVM")
    # what to do if the strings are belong from this 
    

    while start<=end:
        if s[start]!=s[end]:
            return 'NO'
        if s[start] not in mirror:
            return 'NO'
        start+=1
        end-=1
    return 'YES'
print(isReflectionEqual("MOM"))
print(isReflectionEqual("ABCDEFGHIJKLMNOPQRSTUVWXYZ"))
print(isReflectionEqual("AHIMOTUVWXYYXWVUTOMIHA"))
print(isReflectionEqual("UVWXYZZYXWVU"))
print(isReflectionEqual("ZZZZZZAZZZZZZ"))
print(isReflectionEqual("AIMIA"))
