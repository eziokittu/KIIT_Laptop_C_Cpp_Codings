n=int(input())
l=[]
for i in range(n):
    a = (input().split())
    if (len(a)>2):
        l.append(a[len(a)-1])
    else:
        l.append("N/A")

for i in l:
    print(i)
