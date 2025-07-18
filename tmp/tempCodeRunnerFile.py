n = int(input())

prev  = int(input())
flag = False
for i in range(1, n):
    curr  = int(input())
    if prev - curr > 1:
        flag = True
    prev = curr

if flag:
    print("NO")
else:
    print("Yes")