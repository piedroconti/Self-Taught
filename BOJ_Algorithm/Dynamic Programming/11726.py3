d = [0] * 1001
N = int(input())
d[1] = 1
d[2] = 2
d[3] = 3

for i in range(4, N+1):
  d[i] = (d[i - 1] + d[i - 2]) % 10007

print(d[N])