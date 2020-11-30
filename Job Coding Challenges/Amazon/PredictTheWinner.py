def PredictTheWinner(self, nums: List[int]) -> bool: 
        def score(nums, l, r):
            if r == l:
                return nums[l]

            l_choice = nums[l] - score(nums, l+1, r)
            r_choice = nums[r] - score(nums, l, r-1)

            return max(l_choice, r_choice)
        
        return score(nums, 0, len(nums)-1) >= 0
    