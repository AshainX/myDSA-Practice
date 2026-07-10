class Solution:
    def printlen(self, s):
        return len(s)
        
class Solution2:
    def chuchichaiye(self,s):
        return self.chuchi(s)
        
    def chuchi(self, s):
        return len(s)+len(s[-10:])
        
if __name__ == "__main__":
    obj = Solution()
    obj2 = Solution2()
    s = "Nahalebeta_kyunki_tujhe_banna_hai_datascientist+software_engineer"
    print(obj.printlen(s))
    print(obj2.chuchichaiye(s))
