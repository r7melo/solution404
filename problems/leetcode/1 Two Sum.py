
"""
Dado um array de inteiros `nums` e um inteiro `target`, retorne os índices dos dois números cuja soma seja igual a `target`.
Você pode assumir que cada entrada terá exatamente uma solução e não pode usar o mesmo elemento 
duas vezes. A ordem dos índices pode ser qualquer uma.
"""

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        
        indices = set()

        for i in range(len(nums)):
            for j in range(len(nums)):

                if i == j:
                    continue

                if nums[i] + nums[j] == target:
                    indices.add(i) 
                    indices.add(j) 

        return list(indices)
        

r = Solution().twoSum([3,2,4],  5)
print(r)