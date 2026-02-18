class Solution:
    def hasAlternatingBits(self, n: int) -> bool:

        bit = None
        for i in bin(n)[2:]:
            
            if bit == i:
                return False
            
            bit = i
        return True


#Solution().hasAlternatingBits(n=10)   

for i in range(10000):
    if Solution().hasAlternatingBits(n=i):
        print(i, bin(i))