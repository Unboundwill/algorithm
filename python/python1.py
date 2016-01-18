# -*- coding: utf-8 -*-

# 格式化输出
s1 = 72
s2 = 85
r = (s2-s1+0.0)/s1
print('%.1f' % r)

# generator 杨辉三角
def triangles():
	L1=[1]
	while True:
		yield L1
		L2=[1]
		for i in range(1,len(L1)):
			L2.append(L1[i-1]+L1[i])
		L2.append(1)
		L1=L2

n = 0
for t in triangles():
    print(t)
    n = n + 1
    if n == 10:
        break

# map reduce

# 姓名格式化，首字母大写，其他小写
def normalize(name):
    ans=""
    ans+=name[0].upper()
    for i in range(1,len(name)):
    	ans+=name[i].lower()
    return ans
# 测试:
L1 = ['adam', 'LISA', 'barT']
L2 = list(map(normalize, L1))
print(L2)

# 返回乘积
from functools import reduce
def prod(L):
	def mul(x,y):
		return x*y
	return reduce(mul,L)

print('3 * 5 * 7 * 9 =', prod([3, 5, 7, 9]))


# 字符串转浮点数
def str2float(s):
	def f(x, y):
		return x*10 + y
	def char2num(s):
		return {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9}[s]
	s1,s2 = s.split('.')
	return reduce(f, map(char2num, s1)) + (reduce(f, map(char2num, s2))/pow(10,len(s2)))

print('str2float(\'123.456\') =', str2float('123.456'))

#filter

#判断回文数
def is_palindrome(n):
	m=n
	t=0
	while n>0:
		t*=10
		t+=n%10
		n//=10
	return m==t

output = filter(is_palindrome, range(1, 1000))
print(list(output))

#sorted
L = [('Bob', 75), ('Adam', 92), ('Bart', 66), ('Lisa', 88)]

def by_name(t):
	return t[0]
L2 = sorted(L, key=by_name)
print(L2)

def by_score(t):
	return t[1]
L2 = sorted(L, key=by_score, reverse=True)
print(L2)

#closure
def count():
	fs = []
	for i in range(1, 4):
		def f():
			return i*i
		fs.append(f)
	return fs

f1, f2, f3 = count()
print(f1(),f2(),f3())

def count2():
	def f(j):
		def g():
			return j*j
		return g
	fs = []
	for i in range(1, 4):
		fs.append(f(i)) # f(i)立刻被执行，因此i的当前值被传入f()
	return fs
f1, f2, f3 = count2()
print(f1(),f2(),f3())