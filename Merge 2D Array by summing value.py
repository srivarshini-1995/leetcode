class Solution:
    def mergeArrays(self, nums1: list[list[int]], nums2: list[list[int]]) -> list[list[int]]:
        res = []
        i, j = 0, 0
        n1, n2 = len(nums1), len(nums2)
        
        while i < n1 and j < n2:
            id1, val1 = nums1[i]
            id2, val2 = nums2[j]
            
            if id1 == id2:
                res.append([id1, val1 + val2])
                i += 1
                j += 1
            elif id1 < id2:
                res.append([id1, val1])
                i += 1
            else:
                res.append([id2, val2])
                j += 1
                
       
        while i < n1:
            res.append(nums1[i])
            i += 1
        while j < n2:
            res.append(nums2[j])
            j += 1
            
        return res

        
