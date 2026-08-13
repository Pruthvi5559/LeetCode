//2213. Longest Substring of One Repeating Character

class Solution {
    struct Node {
        int len;
        int prefix;
        int suffix;
        int best;
        char leftChar;
        char rightChar;

        Node() {
            len = prefix = suffix = best = 0;
            leftChar = rightChar = '#';
        }

        Node(char c) {
            len = 1;
            prefix = suffix = best = 1;
            leftChar = rightChar = c;
        }
    };

    vector<Node> seg;

    Node merge(Node left, Node right) {
        Node parent;

        parent.len = left.len + right.len;

        parent.leftChar = left.leftChar;
        parent.rightChar = right.rightChar;

        // Best prefix
        parent.prefix = left.prefix;

        if (left.prefix == left.len &&
            left.rightChar == right.leftChar) {
            parent.prefix += right.prefix;
        }

        // Best suffix
        parent.suffix = right.suffix;

        if (right.suffix == right.len &&
            left.rightChar == right.leftChar) {
            parent.suffix += left.suffix;
        }

        // Best repeating substring inside this segment
        parent.best = max(left.best, right.best);

        // Check substring crossing the middle
        if (left.rightChar == right.leftChar) {
            parent.best = max(
                parent.best,
                left.suffix + right.prefix
            );
        }

        return parent;
    }

    void build(int node, int l, int r, string& s) {
        if (l == r) {
            seg[node] = Node(s[l]);
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, s);
        build(node * 2 + 1, mid + 1, r, s);

        seg[node] = merge(
            seg[node * 2],
            seg[node * 2 + 1]
        );
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            seg[node] = Node(c);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, c);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, c);
        }

        seg[node] = merge(
            seg[node * 2],
            seg[node * 2 + 1]
        );
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        int n = s.size();

        // Segment tree needs O(4n) nodes
        seg.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            // Apply the character update
            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            // Root stores the answer for the entire string
            ans.push_back(seg[1].best);
        }

        return ans;
    }
};