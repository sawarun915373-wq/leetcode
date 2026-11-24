class Solution {
    const vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
                                 "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
                                 "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    const vector<string> scales = {"", "Thousand", "Million", "Billion"};

    string below1000(int n) {
        string res;
        if (n >= 100) {
            res += ones[n / 100] + " Hundred";
            n %= 100;
            if (n) res += " ";
        }
        if (n >= 20) {
            res += tens[n / 10];
            n %= 10;
            if (n) res += " " + ones[n];
        } else if (n > 0) {
            res += ones[n];
        }
        return res;
    }

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        string res;
        for (int i = 0; num > 0; i++, num /= 1000) {
            int chunk = num % 1000;
            if (chunk == 0) continue;

            string part = below1000(chunk);
            if (!scales[i].empty()) part += " " + scales[i];
            res = res.empty() ? part : part + " " + res;
        }
        return res;
    }
};