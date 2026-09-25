//1096. Brace Expansion II
/*
Under the grammar given below, strings can represent a set of lowercase words. Let R(expr) 
denote the set of words the expression represents.

The grammar can best be understood through simple examples:

Single letters represent a singleton set containing that word.
R("a") = {"a"}
R("w") = {"w"}
When we take a comma-delimited list of two or more expressions, we take the union of possibilities.
R("{a,b,c}") = {"a","b","c"}
R("{{a,b},{b,c}}") = {"a","b","c"} (notice the final set only contains each word at most once)
When we concatenate two expressions, we take the set of possible concatenations between two words where 
the first word comes from the first expression and the second word comes from the second expression.
R("{a,b}{c,d}") = {"ac","ad","bc","bd"}
R("a{b,c}{d,e}f{g,h}") = {"abdfg", "abdfh", "abefg", "abefh", "acdfg", "acdfh", "acefg", "acefh"}
Formally, the three rules for our grammar:

For every lowercase letter x, we have R(x) = {x}.
For expressions e1, e2, ... , ek with k >= 2, we have R({e1, e2, ...}) = R(e1) ∪ R(e2) ∪ ...
For expressions e1 and e2, we have R(e1 + e2) = {a + b for (a, b) in R(e1) × R(e2)}, where + denotes concatenation, 
and × denotes the cartesian product.
Given an expression representing a set of words under the given grammar, return the sorted list of words that the 
expression represents.
*/

class Solution {
public:
    int index = 0;

    // Parse a comma-separated union.
    set<string> parseUnion(const string& expression) {
        set<string> result = parseConcat(expression);

        while (index < expression.size() &&
               expression[index] == ',') {
            index++; // Skip ','

            set<string> next = parseConcat(expression);

            result.insert(next.begin(), next.end());
        }

        return result;
    }

    // Parse consecutive expressions and concatenate them.
    set<string> parseConcat(const string& expression) {
        set<string> result = {""};

        while (index < expression.size() &&
               expression[index] != '}' &&
               expression[index] != ',') {

            set<string> current;

            if (expression[index] == '{') {
                index++; // Skip '{'

                current = parseUnion(expression);

                index++; // Skip '}'
            } else {
                // A single lowercase letter.
                current.insert(string(1, expression[index]));
                index++;
            }

            result = concatenate(result, current);
        }

        return result;
    }

    // Cartesian product of two sets using string concatenation.
    set<string> concatenate(const set<string>& first,
                             const set<string>& second) {
        set<string> result;

        for (const string& a : first) {
            for (const string& b : second) {
                result.insert(a + b);
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        set<string> result = parseUnion(expression);

        return vector<string>(result.begin(), result.end());
    }
};