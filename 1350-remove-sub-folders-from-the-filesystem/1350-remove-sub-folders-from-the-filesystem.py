class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder.sort(key = lambda x: len(x))
        seen = defaultdict(int)
        result = []
        for path in folder:
            temp = ""
            seenalready = False
            for char in path:
                if temp!="" and char=='/' and seen[temp] > 0:
                    seenalready = True
                temp+=char
            if not seenalready:
                result.append(path)
                seen[path]+=1

        return result 
