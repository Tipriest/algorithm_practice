import sympy as sp

# 1. 定义符号
T = sp.symbols('T')

# 2. 定义矩阵，元素可以是任意多项式/有理式
A = sp.Matrix([
    [T**5/120,        T**4/24,      T**3/6      ],
    [T**4/24,     T**3/6,      T**2/2      ],
    [T**2/2-T,        T-2,      1-T**-1*2   ],
])

# 3. 求逆
A_inv = A.inv()          # 会自动按伴随矩阵 + 行列式的方式做符号求逆
print("A(T)^{-1} =")
# sp.pprint(A_inv)         # 漂亮地打印
A_inv_simplified = sp.simplify(A_inv)
print(A_inv_simplified)


# 4. 查看 det，知道什么时候不可逆
detA = A.det()
print("det(A) =", detA)