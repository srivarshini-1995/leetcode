class Solution:
    def findThePrefixCommonArray(self, A: list[int], B: list[int]) -> list[int]:
        n = len(A)
        C = []
        seen = set()
        common_count = 0
        
        for i in range(n):
            
            if A[i] in seen:
                common_count += 1
            else:
                seen.add(A[i])
                
            
            if B[i] in seen:
                common_count += 1
            else:
                seen.add(B[i])
                
            C.append(common_count)
            
        return C
