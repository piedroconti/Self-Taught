d = [0] * 1000001

d[1] = 1
d[2] = 2
d[3] = 3

N = int(input())

for i in range(3,N+1):
  d[i] = (d[i-1] + d[i-2]) % 15746

print(d[N])