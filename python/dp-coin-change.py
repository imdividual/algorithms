import math
import numpy as np

def coin_change(coins, amount):
    dp = np.full(amount+1, math.inf)
    dp[0] = 0

    for i in range(len(dp)):
        for j in coins:
            if i - j >= 0 and dp[i-j] != math.inf:
                dp[i] = min(dp[i], dp[i-j]+1)

    if dp[amount] == math.inf:
        return -1
    else:
        return int(dp[amount])

coins = [2]
amount = 3
print(coin_change(coins, amount))
