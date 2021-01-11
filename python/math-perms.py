# https://leetcode.com/problems/permutations/

lop = []

def permsi(nums, i):
    if i == len(nums):
        lop.append(nums[:])

    for j in range(i, len(nums)):
        nums[i], nums[j] = nums[j], nums[i]
        permsi(nums, i+1)
        nums[i], nums[j] = nums[j], nums[i]

def perms(nums):
    permsi(nums, 0)
    return lop

print(perms([1,2,3]))

i = 0
j = 1
i, j = j, i
print("{} {}".format(i, j))