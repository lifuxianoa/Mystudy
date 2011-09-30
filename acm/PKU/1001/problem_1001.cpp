#include <iostream>
#include <vector>
#include <string>
using namespace std;

void large_mult(const vector<unsigned int>&a, const vector<unsigned int>&b, vector<unsigned int>&result)
{
    unsigned int i, j, k;

    for (i = 0; i < a.size(); i++)
    {
        k = i;
        for (j = 0; j < b.size(); j++)
        {
            result[k++] += a[i] * b[j];
        }
    }

    for (i = result.size() - 1; i > 0; i--)
    {
        if (result[i] > 9)
        {
            result[i - 1] += result[i] / 10;
            result[i] %= 10;
        }
    }

    if (result[0] > 9)
    {
        result.insert(result.begin(), result[0] / 10);
        result[1] %= 10;
    }
}

void large_comp(const vector<unsigned int>&a, vector<unsigned int>&result, unsigned int n)
{
    unsigned int i, j;

    if ( n == 1 )
    {
        result = a;
    }
    else 
    {
        result.resize(a.size() * 2 -1, 0);
        large_mult(a, a, result);

        if (n > 2)
        {
            for (i = 0; i < n - 2; i++)
            {
                vector<unsigned int> b = result;
                result.clear();
                result.resize(a.size() + b.size() - 1, 0);

                large_mult(a, b, result);

                for (j = 0; j < result.size(); j++)
                {
                    cout << result[j];
                }
                cout << endl;
            }
        }
    }
}

int main()
{
    unsigned int i, j;
    unsigned int point_len;
    string s;
    unsigned int n;
    vector<unsigned int> a;
    vector<unsigned int> result;

    while (cin >> s >> n)
    {
        point_len = 0;
        result.clear();
        a.clear();
        a.reserve(s.size());
        for (i=0; i<s.size(); i++)
        {
            if ('.' == s[i])
            {
                point_len = a.size();
                continue;
            }
            else if ( a.size() == 0 && s[i] == '0')
            {
                continue;
            }

            a.push_back(s[i] - '0');
        }

        while (a[a.size() - 1] == 0)
        {
            a.pop_back();
        }

        point_len = a.size() - point_len;
        cout << "point_len=" << point_len << endl;
        cout << "a: ";
        for (i=0; i<a.size(); i++)
        {
            cout << a[i];
        }
        cout << endl;

        large_comp(a, result, n);

        point_len *= n;
        //delete addtional zero at the end.
        cout << "point_len=" << point_len << endl;
        cout << "result.size=" << result.size() << endl;
        j = result.size() - point_len - 1;
        for (i = result.size() - 1; i > j; i--)
        {
            if (result[i] != 0)
            {
                break;
            }
            result.pop_back();
        }

        //print the result
        if (point_len > result.size())
        {
            cout << ".";
            for (i = 0; i < point_len - result.size(); i++)
            {
                cout << "0";
            }
        }

        for (i = 0; i < result.size(); i++)
        {
            if (i == result.size() - point_len)
            {
                cout << ".";
            }
            cout << result[i];
        }
        cout << endl;
    }
    return 0;
}

