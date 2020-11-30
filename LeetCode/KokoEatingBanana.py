class Solution:        
    def minEatingSpeed(self, piles: List[int], H: int) -> int:
        
        k_nxt = math.ceil(sum(piles) / H)
        r = max(piles)
        canEatFaster = self.canEatAll(piles, k_nxt, H)
        while (not canEatFaster):
            k_nxt += not canEatFaster
            canEatFaster = self.canEatAll(piles, k_nxt, H)

        return k_nxt
                
        
    def canEatAll(self, pile, k, H):
        time = 0;
        for size in pile:
            time += math.ceil(size / k) 
        return time <= H