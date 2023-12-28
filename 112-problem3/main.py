#
#
# NTUT 112 Problem 3
#
#

def f1(n):
    X = [i for i in range(1, n) if i%2 == 0]
    return (X)

def f2(S):
    data = dict()
    for s in S:
        if s in data.keys():
            data[s] = data[s] + 1
        else:
            data[s] = 1
    return data

def f3(n):
    f = lambda m, n: m*n+1
    X = {i:f(i, i+1) for i in range(1, n) if i%3 == 0}
    return X

def f4():
    scores = [['John', 90, 80], ['Bob', 50, 70], ['Mary', 80, 70]]
    data = filter(lambda x:True if sum(x[1:3])<150 else False, scores)
    return list(data)

def f5(s1, s2, m, n):
    return s1[m:n] + s2[m:n]

def f6(A, B):
    return list(map(lambda x, y:x ** y, A, B))

def f7(data, n):
    if n == len(data): return[data]
    elif n == 0: return ['']
    s0 = f7(data[1:], n)
    s1 = [data[0]+s for s in f7(data[1:], n-1)]
    return sorted(s0+s1)
# 3-1 ~ 3-7
print(f1(8)[2])
print(f2('ntut csie')['t'])
print(f3(6)[3])
print(f4())
print(f5('ntut', 'good', 2, 4))
print(f6([2, 4, 6], [3, 2, 1]))
print(f7('abc', 2)[2])

# 3-8 ~ 3-10
def op(data, x, y, n):
    sum = 0
    for i in range(x, x+n):
        for j in range(y, y+n):
            sum = sum + data[i][j]

    return sum // n*n

def compress(data, m, n):
    size = m//n
    target = []
    for x in range(size):
        row = []
        for y in range(size):
            row.append(op(data, x*n, y*n, n))
        target.append(row)
    return target

data = [[1, 2, 3, 4, 5, 6, 7],
        [8, 9, 10, 11, 12, 13, 14],
        [15, 16, 17, 18, 19, 20, 21],
        [22, 23, 24, 25, 26, 27, 28],
        [29, 30, 31, 32, 33, 34, 35],
        [36, 37, 38, 39, 40, 41, 42],
        [43, 44, 45, 46, 47, 48, 49]]

print(compress(data, 4, 2), '\n##')
print(compress(data, 6, 2), '\n##')
print(compress(data, 6, 3), '\n##')
#(1+2+8+9)//4 = 5,
#(3+4+10+11)//4 = 7,
#(15+16+22+23)//4 = 19,
#(17+18+24+25)//4 = 21
#...
#(1+2+3+8+9+10+15+16+17)//9 = 9,
#(4+5+6+11+12+13+18+19+20)//9 = 30,
#(22+23+24+29+30+31+36+37+38)//9 = 20,
#(25+26+27+32+33+34+39+40+41)//9 = 33