class Solution
{
public:
    // Function to return the sorted array.
    vector<int> nearlySorted(int arr[], int n, int K)
    {

        vector<int> ans;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < n; i++)
        {

            pq.push(arr[i]);
            if (pq.size() > K)
            {
                ans.push_back(pq.top());
                pq.pop();
            }
        }

        while (pq.size())
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};