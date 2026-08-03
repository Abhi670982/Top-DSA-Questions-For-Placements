class Solution {
public:
    vector<int> solve(string &word, string &order) {

        vector<int> temp;

        for (int i = 0; i < word.length(); i++) {

            for (int j = 0; j < order.length(); j++) {

                if (word[i] == order[j]) {

                    temp.push_back(j);
                    break;
                }
            }
        }

        return temp;
    }

    bool isAlienSorted(vector<string>& words, string order) {

        int n = words.size();

        if (n == 1)
            return true;

        for (int i = 0; i < n - 1; i++) {

            vector<int> arr = solve(words[i], order);
            vector<int> arr2 = solve(words[i + 1], order);

            int n1 = words[i].length();
            int n2 = words[i + 1].length();

            int len = min(n1, n2);

            for (int j = 0; j < len; j++) {

                if (arr[j] < arr2[j])
                    break;

                if (arr[j] > arr2[j])
                    return false;

                // if equal, continue comparing
            }

            // Prefix case
            if (n1 > n2) {

                bool same = true;

                for (int j = 0; j < len; j++) {

                    if (arr[j] != arr2[j]) {

                        same = false;
                        break;
                    }
                }

                if (same)
                    return false;
            }
        }

        return true;
    }
};