class Solution:
    def is_perfect_cube(self,n):
        root = round(n ** (1/3))
        return root ** 3 == n

    def findGoodIntegers(self, n: int) -> list[int]:
        possible_pairs = {}
        result = []
        limit = int(n ** (1/3))+1
        for i in range (1,limit):
            for j in range(1,limit+1):
                cube = (i*i*i)+(j*j*j)
                if cube>n:
                    break
                if cube in possible_pairs:
                    x= possible_pairs[cube][0]
                    if i!=x and j!=x:
                        result.append(cube)
                else: possible_pairs[cube]=[i,j]

        return sorted(list(set(result)))