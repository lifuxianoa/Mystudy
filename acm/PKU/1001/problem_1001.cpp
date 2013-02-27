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
    size_t position = 0;

    while (cin >> s >> n)
    {
        point_len = 0;
        result.clear();
        a.clear();
        a.reserve(s.size());

        //remove last zero
        position = s.find_first_of('.');
        if (position < s.size())
        {
            position = s.find_last_not_of('0');
            if (position != s.size() - 1)
            {
                if ('.' == s[position])
                {
                    s.erase(position, s.size() - position);
                }
                else
                {
                    s.erase(position + 1, s.size() - position - 1);
                }
            }
        }

        //remove zero at the beginning
        position = s.find_first_not_of('0');
        if (position != 0)
        {
            s.erase(0, position);
        }

        for (i=0; i<s.size(); i++)
        {
            if ('.' == s[i])
            {
                point_len = s.size() - a.size() - 1;
                continue;
            }
            else if ( a.size() == 0 && s[i] == '0')
            {
                continue;
            }

            a.push_back(s[i] - '0');
        }
        if (0 == a.size())
        {
            a.push_back(0);
        }

        if (0 == n)
        {
            cout << 1 << endl;
            continue;
        }

        large_comp(a, result, n);

        point_len *= n;
        //delete addtional zero at the end.
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

