def threeSum(nums:list):
    s = set()
    nums.sort()
    n = len(nums)
    
    for i in range(n):
        j, k = i+1, n-1
        while j < k:
            current = nums[i] + nums[j] + nums[k]
            if current == 0:
                s.add((nums[i], nums[j], nums[k]))
                j, k = j+1, k-1
            elif current < 0:
                j += 1
            else:
                k -= 1
    return list(s)

if __name__ == '__main__':
    nums = [-1,0,1,2,-1,-4]
    ans = threeSum(nums)
    print(ans)
    
        