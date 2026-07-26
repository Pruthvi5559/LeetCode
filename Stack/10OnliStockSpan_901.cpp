//901. Online Stock Span
class StockSpanner {
public:
    // Stores {price, index} in monotonic decreasing order of price
    stack<pair<int, int>> st;

    // Current day's index
    int ind;

    StockSpanner() {
        ind = -1;
    }

    int next(int price) {

        // Move to the next day
        ind++;

        // Remove all previous prices less than or equal to current price
        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        // Previous greater element's index
        int prevGreaterIndex = st.empty() ? -1 : st.top().second;

        // Stock span = distance from previous greater price
        int ans = ind - prevGreaterIndex;

        // Push current price and its index
        st.push({price, ind});

        return ans;
    }
};