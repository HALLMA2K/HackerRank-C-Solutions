#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


// get mean of a vector
double getMean(vector<double>& v)
{
    int size = v.size();
    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += v[i];
    }
    return sum / size;
}

// get median average of a vector
double getMedian(vector<double>& v)
{
    int size = v.size();
    sort(v.begin(), v.end());
    if (size % 2 == 0)
    {
        return (v[size / 2 - 1] + v[size / 2]) / 2;
    }
    else
    {
        return v[size / 2];
    }
}

// get mode of a vector
double getMode(const std::vector<double>& v) {
    std::map<double, int> frequency;
    for (double num : v) {
        frequency[num]++;
    }
    double mode = v[0];
    int max_frequency = frequency[mode];
    for (const auto& [num, count] : frequency) {
        if (count > max_frequency) {
            mode = num;
            max_frequency = count;
        }
    }
    return mode;
}

// get standard deviation of a vector
double getStdDev(vector<double>& v)
{
    double mean = getMean(v);
    double sum = 0;
    int size = v.size();
    for (int i = 0; i < size; i++) {
        sum += (v[i] - mean) * (v[i] - mean);
    }
    return sqrt(sum / size);
}


int main()
{
    // cin vector
    int n = 0;
    cin>>n;
    vector<double> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    cout << getMean(v) << endl;
    cout << getMedian(v) << endl;
    cout << getMode(v) << endl;
    cout << getStdDev(v) << endl;
    double lower, upper;
    lower = getMean(v) - 1.96 * getStdDev(v) / sqrt(v.size());
    upper = getMean(v) + 1.96 * getStdDev(v) / sqrt(v.size());
    cout << lower << " " << upper << endl;
    
    return 0;
}
