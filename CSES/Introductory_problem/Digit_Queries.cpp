#include <bits/stdc++.h>
#define ll long long
#define ii pair<int, int>
using namespace std;
ll MOD = 1e9 + 7;

int main()
{
    ll powerOfTen[20] = {1};
    for (int i = 1; i < 19; i++)
    {
        powerOfTen[i] = powerOfTen[i - 1] * 10;
    }
    powerOfTen[0] = 0;


    int t;
    cin >> t;
    while (t--)
    {
        ll k;
        cin >> k;
        int numberOfDigits = 0;
        ll digitSoFar = 0;
        ll digitsBeforeActualBlock = 0;
        for (int i = 1; i < 19; i++)
        {
            digitSoFar += (powerOfTen[i] - powerOfTen[i - 1]) * i;
            if (digitSoFar >= k)
            {
                numberOfDigits = i;
                break;
            }
            digitsBeforeActualBlock += (powerOfTen[i] - powerOfTen[i - 1]) * i;
        }
        ll smallestValue = powerOfTen[numberOfDigits - 1];
        ll largestValue = powerOfTen[numberOfDigits] ;
        // cout << digitsBeforeActualBlock << " > " << digitSoFar << endl;
        // cout << smallestValue << " -> " << largestValue << endl;
        // cout << numberOfDigits << endl;
        ll theBestNumber = 0;
        ll theBestIndex = 0;
        while (smallestValue <= largestValue)
        {
            ll midValue = (smallestValue + largestValue) / 2;
            ll tempIndex = (midValue - powerOfTen[numberOfDigits - 1]) * numberOfDigits + digitsBeforeActualBlock;
            if (tempIndex <= k)
            {
                theBestNumber = midValue;
                theBestIndex = tempIndex;
                smallestValue = midValue + 1;
            }
            else
            {
                largestValue = midValue - 1;
            }
            // cout << tempIndex << ">" << midValue << endl;
            // cout << smallestValue << " -> " << largestValue << endl;
        }
        // cout << theBestNumber << " : " << theBestIndex << endl;
        ll resultIndex = k - theBestIndex;
        string number = to_string(theBestNumber);
        cout << number[resultIndex] << endl;
    }
}