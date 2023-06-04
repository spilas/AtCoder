from collections import defaultdict

class UnionFind():
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return

        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return len(self.roots())

    def all_group_members(self):
        group_members = defaultdict(list)
        for member in range(self.n):
            group_members[self.find(member)].append(member)
        return group_members

    def __str__(self):
        return '\n'.join(f'{r}: {m}' for r, m in self.all_group_members().items())

n, m = map(int, input().split())
uf = UnionFind(n+1)

for i in range(m):
    u_i, u_j = tuple(map(int, input().split()))
    uf.union( u_i, u_j )

xy = set()

for i in range(int(input())):
    x = tuple(map(int, input().split()))
    x = (uf.find(x[0]), uf.find(x[1]))
    x = sorted(x)
    xy.add(f"{x[0]}_{x[1]}")


for i in range(int(input())):
    pq = tuple(map(int, input().split()))
    pq = (uf.find(pq[0]), uf.find(pq[1]))
    pq = sorted(pq)
    key = (f"{pq[0]}_{pq[1]}")
    if key in xy:
        print("No")
    else:
        print("Yes")
