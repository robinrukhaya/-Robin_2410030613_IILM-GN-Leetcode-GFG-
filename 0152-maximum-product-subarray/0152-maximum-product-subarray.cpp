class Solution {
public:
   int maxProduct(vector<int>& arr)
{
    int maxi = arr[0];
    int mini = arr[0];
    int answer = arr[0];

    for (int i = 1; i < arr.size(); i++)
    {
        int x = arr[i];

        int newMax = max(x, max(x * maxi, x * mini));
        int newMin = min(x, min(x * maxi, x * mini));

        maxi = newMax;
        mini = newMin;

        answer = max(answer, maxi);
    }

    return answer;
    }
};