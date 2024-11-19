def find_best_buy_sell_days(prices_str):
    # Convert the input string to a list of integers
    prices = list(map(int, prices_str.split(',')))
    
    if not prices:
        return -1, -1

    min_price = float('inf')
    max_profit = 0
    buy_day = -1
    sell_day = -1

    for i in range(len(prices)):
        if prices[i] < min_price:
            min_price = prices[i]
            temp_buy_day = i
        
        current_profit = prices[i] - min_price

        if current_profit > max_profit:
            max_profit = current_profit
            buy_day = temp_buy_day
            sell_day = i

    return buy_day, sell_day, max_profit

# Example usage
prices_str = "101,90,100,80,94,110,95,92,60,80,60"
buy_day, sell_day, max_profit = find_best_buy_sell_days(prices_str)

if buy_day == sell_day:
    print("No profitable buy/sell pair found.")
else:
    prices = list(map(int, prices_str.split(',')))
    print(f"Buy on day: {buy_day} (price: {prices[buy_day]})")
    print(f"Sell on day: {sell_day} (price: {prices[sell_day]})")
    print(f"Maximum profit: {max_profit}")
