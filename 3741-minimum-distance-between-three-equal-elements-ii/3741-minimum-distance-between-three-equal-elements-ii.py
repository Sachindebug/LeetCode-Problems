class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        ele_map = {}
        for i in range(0,len(nums)):
            if nums[i] in ele_map.keys():
                ele_map[nums[i]].append(i)
            else: ele_map[nums[i]] = [i]
        
        min_dist = 3*len(nums)
        for key in ele_map.keys():
            indexes = ele_map[key]
            for i in range(0,len(indexes)-2):
                min_dist = min(min_dist,2*(indexes[i+2]-indexes[i]))

        if min_dist==3*len(nums): return -1
        return min_dist