#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

struct status {
    int lo, hi, sum;
};

void print_status(status stat) {
    cout << "lo:" << stat.lo << " hi:" << stat.hi << " max:" << stat.sum << endl;
}


// 暴力
status find_maxium_subarray_brute(vector<int>& a) {
    int lo, hi, sum;
    lo = hi = sum = 0;
    int curmax = INT32_MIN;
    
    for (int i = 0; i < a.size(); i++) {
        sum = 0;
        for (int j = i; j < a.size(); j++) {
            sum += a[j];
            if (sum > curmax) {
                curmax = sum;
                lo = i;
                hi = j;
            }
        }
    }

    return {lo, hi, curmax};
}

status find_maxium_cross(vector<int>& a, int lo, int mid, int hi);

// 分治
status find_maxium_subarray_divide(vector<int> &a, int lo, int hi) {
    if (lo == hi) {
        return {lo, hi, a[lo]};
    } else {
        int mid = lo + (hi - lo) / 2;
        auto left = find_maxium_subarray_divide(a, lo, mid);
        auto right = find_maxium_subarray_divide(a, mid + 1, hi);
        auto middle = find_maxium_cross(a, lo, mid, hi);

        if (left.sum > right.sum && left.sum > middle.sum)
            return left;
        else if (right.sum > left.sum && right.sum > middle.sum)
            return right;
        else
            return middle;
    }
}

// https://en.wikipedia.org/wiki/Maximum_subarray_problem
status find_maxium_subarray_dynamic(vector<int>& a) {
    int lo, hi, curlo;
    lo = hi = curlo = 0;
    int max_sum, sum;
    max_sum = sum = INT32_MIN;
    for (int i = 0; i < a.size(); i++) {
        if (sum > 0) {
            sum += a[i];
        } else {
            curlo = i;
            sum = a[i];
        }
        if (sum > max_sum) {
            max_sum = sum;
            hi = i;
            lo = curlo;
        }
    }
    
    return {lo,hi,max_sum};
}

/**
 * local_sum = max(local_sum + A[i], A[i])
 * https://medium.com/@rsinghal757/kadanes-algorithm-dynamic-programming-how-and-why-does-it-work-3fd8849ed73d
 */
int find_maxium_sum(vector<int> &a) {
    int n = a.size();
    int local_sum = 0;
    int global_sum = INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        local_sum = max(a[i], a[i] + local_sum);
        global_sum = max(global_sum, local_sum);
    }
    return global_sum;
}


int main(int argc, char const *argv[])
{
    vector<int> a(10);

    srand(time(0));
    generate(a.begin(), a.end(), []{ return rand() % 100 - 50; });

    copy(a.begin(), a.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    auto stat = find_maxium_subarray_brute(a);
    print_status(stat);

    stat = find_maxium_subarray_divide(a, 0, a.size() - 1);
    print_status(stat);

    stat = find_maxium_subarray_dynamic(a);
    print_status(stat);

    return 0;
}




status find_maxium_cross(vector<int>& a, int lo, int mid, int hi) {
    int leftsum = INT32_MIN, rightsum = INT32_MIN, sum = 0;
    int leftindex = 0, rightindex = 0;
    for (int i = mid; i >= lo; i--) {
        sum += a[i];
        if (sum > leftsum) {
            leftsum = sum;
            leftindex = i;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= hi; i++) {
        sum += a[i];
        if (sum > rightsum) {
            rightsum = sum;
            rightindex = i;
        }
    }
    return {leftindex, rightindex, leftsum + rightsum};
}


