#2089. Find Target Indices After Sorting Array
#You are given a 0-indexed integer array nums and a target element target.
#A target index is an index i such that nums[i] == target.

#Return a list of the target indices of nums after sorting nums 
#in non-decreasing order. If there are no target indices, return an empty list. 
#The returned list must be sorted in increasing order.

class Solution:
    def targetIndices(self, nums: list[int], target: int) -> list[int]:
        result = []
        small = 0
        cnt = 0
        
        for i in range(len(nums)):
            if nums[i] < target:
                small += 1
            elif nums[i] == target:
                cnt += 1
        
        while cnt > 0:
            result.append(small)
            small += 1
            cnt -= 1 
        
        return result
        