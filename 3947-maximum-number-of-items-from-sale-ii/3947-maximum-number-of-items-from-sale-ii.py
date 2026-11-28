
class Solution:
    def maximumSaleItems(self, items: List[List[int]], budget: int) -> int:
        n = len(items)
        max_factor = max(item[0] for item in items)
        freq = [0] * (max_factor + 1)
        for factor, price in items:
            freq[factor] += 1

        factor_count = [0] * (max_factor + 1)

        for i in range(1, max_factor + 1):
            for j in range(i, max_factor + 1, i):
                factor_count[i] += freq[j]

        
        items.sort(key=lambda x: x[1])

        min_price = items[0][1]
        ans = 0

        for factor, price in items:
            if price > 2 * min_price:
                break

            count = factor_count[factor] - 1

            if count <= 0:
                continue

            take = min(count, budget // price)

            ans += 2 * take
            budget -= take * price

        ans += budget // min_price

        return ans
