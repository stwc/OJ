class Solution
{
public:
    string complexNumberMultiply(string a, string b)
    {
        int ra = stoi(a.substr(0, a.find("+")));
        int ia = stoi(a.substr(a.find("+") + 1, a.find("i") - a.find("+") - 1));
        int rb = stoi(b.substr(0, b.find("+")));
        int ib = stoi(b.substr(b.find("+") + 1, b.find("i") - b.find("+") - 1));
        // cout << ra << ", " << ia << endl;
        // cout << rb << ", " << ib << endl;
        string retR = to_string(ra * rb - ia * ib);
        string retI = to_string(ra * ib + rb * ia);
        // cout << retR + "+" + retI + "i" << endl;
        return retR + "+" + retI + "i";
    }
};
