class Solution:
    def findTheArrayConcVal(self, nums: list[int]) -> int:
        concat_val = 0
        left, right = 0, len(nums) - 1
        
        while left <= right:
            if left == right:
                
                concat_val += nums[left]
                break
            
            
            num1 = nums[left]
            num2 = nums[right]
            
            
            temp = num2
            multiplier = 1
            while temp > 0:
                multiplier *= 10
                temp //= 10
                
            
            concatenated = num1 * multiplier + num2
            concat_val += concatenated
            
            
            left += 1
            right -= 1
            
        return concat_val
