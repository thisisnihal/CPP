private int transact(int i, int sellMode)
    {
        if(i == PRICES.length)
            return 0;

        if(sellMode == 0)
        {
            return Math.max(
                0 + transact(i+1,0),
                -PRICES[i] + transact(i+1,1)
            );
        }
        else
        {
            return Math.max(
                0 + transact(i+1,1),
                PRICES[i]-FEE + transact(i+1,0)
            );
        }
    }