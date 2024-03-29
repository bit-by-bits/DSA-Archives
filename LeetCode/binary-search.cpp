class Solution
{
public:
    int search(vector<int> &arr, int target)
    {

        int str = 0;
        int mid = 0;
        int end = arr.size() - 1;

        while (str <= end)
        {

            mid = str + (end - str) / 2;

            if (arr[mid] < target)
                str = mid + 1;
            else if (target < arr[mid])
                end = mid - 1;
            else
                return mid;
        }

        return -1;
    }