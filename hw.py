def task1(arr1,arr2):
    res = []
    for i,j in zip(arr1,arr2):
        res.append((i+j)/2)
    # print(res)
    return res
def scale(x,mi,ma,ami,ama):
    val = ((ma-mi)/(ama-ami))*(x-ama)+ma
    return val
def task2(arr):
    res = []
    ma = max(arr)
    mi = min(arr)
    for i in range(0,len(arr)):
        res.append(scale(arr[i],0,255,mi,ma))
    return res


if __name__ == "__main__":
    n = int(input("Enter the length of array 1\n"))
    m = int(input("Enter the length of array 2\n"))
    arr1,arr2 = [],[]
    print("Enter elements in array 1")
    while(n>0):
        arr1.append(int(input()))
        n -= 1
    print("Enter elements in array 2")
    while(m>0):
        arr2.append(int(input()))
        m -= 1
    print(task2(task1(arr1,arr2)))
    
