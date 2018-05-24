# 用暴力法求解最大子数组问题

def MaximumSubarrayBruteForce(B):
    ans = []
    max = B[0]
    for i in range(len(B)):
        submax = B[i]
        if max < submax:
            max = submax
            start = i
            end = i
        for j in range(i,len(B)):
            submax = submax + B[j]
            if max < submax:
                max = submax
                start = i
                end = j
    return start,end

print("请输入数组元素个数：")
count = int(input())
A = []
for i in range(count):
    print("请输入第{}个元素".format(i))
    A.append(int(input()))

#A = [1,-4,3,-4]
start,end = MaximumSubarrayBruteForce(A)
print("最大子数组的下标为：")
print(start,end)

#print(A[0])