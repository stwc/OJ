class Solution
{
public:
    static bool cmp(const string &l, const string &r)
    {
        string lid = l.substr(0, l.find(" "));
        string lv = l.substr(l.find(" ") + 1);
        string rid = r.substr(0, r.find(" "));
        string rv = r.substr(r.find(" ") + 1);
        if (!isdigit(lv[0]) && !isdigit(rv[0])) {
            if (lv == rv)
                return lid < rid;
            return lv < rv;
        }
        return (isdigit(lv[0])) ? false : true;
    }

    vector<string> reorderLogFiles(vector<string> &logs)
    {
        stable_sort(logs.begin(), logs.end(), cmp);
        return logs;
    }
};