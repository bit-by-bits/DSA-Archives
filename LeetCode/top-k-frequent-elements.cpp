class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> counts;
        for (auto i : nums)
            ++counts[i];

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto &k : counts)
            buckets[k.second].push_back(k.first);
        reverse(begin(buckets), end(buckets));

        vector<int> res;
        for (auto &bucket : buckets)
            for (auto i : bucket)
            {
                res.push_back(i);
                if (res.size() == k)
                    return res;
            }

        return res;
    }
};

// class Solution
// {
// public:
//     vector<int> topKFrequent(vector<int> &nums, int k)
//     {
//         unordered_map<int, int> counts;
//         priority_queue<int, vector<int>, greater<int>> max_k;
//         for (auto i : nums)
//             ++counts[i];
//         for (auto &i : counts)
//         {
//             max_k.push(i.second);
//             // Size of the min heap is maintained at equal to or below k
//             while (max_k.size() > k)
//                 max_k.pop();
//         }
//         vector<int> res;
//         for (auto &i : counts)
//         {
//             if (i.second >= max_k.top())
//                 res.push_back(i.first);
//         }
//         return res;
//     }
// };