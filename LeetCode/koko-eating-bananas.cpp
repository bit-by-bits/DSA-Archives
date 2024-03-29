class Solution
{
public:
    bool check(vector<int> piles, int mid, int h)
    {

        long long int hours = 0;
        int SIZE = piles.size();

        for (int i = 0; i < SIZE; i++)
        {

            if (piles[i] <= mid)
                hours++;
            else
                hours += ceil(piles[i] / (double)mid);

            if (hours > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {

        int str = 1;
        int end = *max_element(piles.begin(), piles.end());

        int res = end;
        while (str <= end)
        {

            int mid = str + (end - str) / 2;
            if (check(piles, mid, h))
            {
                res = mid;
                end = mid - 1;
            }
            else
                str = mid + 1;
        }

        return res;
    }
};