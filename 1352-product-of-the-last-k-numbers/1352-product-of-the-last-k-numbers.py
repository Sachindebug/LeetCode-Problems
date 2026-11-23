
class ProductOfNumbers:

    def __init__(self):
        self.zero = 0
        self.numbers = [1]
        self.zeroCount = [0]

    def add(self, num: int) -> None:
        last = self.numbers[-1]
        if num != 0:
            self.numbers.append(num * last)
        else:
            self.numbers.append(last)
            self.zero += 1

        self.zeroCount.append(self.zero)

    def getProduct(self, k: int) -> int:
        n = len(self.zeroCount) - 1

        if self.zeroCount[n] != self.zeroCount[n-k]:
            return 0

        return self.numbers[n] // self.numbers[n-k]
