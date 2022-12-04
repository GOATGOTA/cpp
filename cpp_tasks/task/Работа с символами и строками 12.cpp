// 12. Дана непустая строка S и целое число N (>0). 
// Вывести строку, содержащую символы строки S, между которыми вставлено по N символов «*» (звездочка).

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    for(int i = 0; i < s.size() - 1; ++i){
        cout << s[i];
        for(int j = 0; j < n; ++j)
            cout << '*';
    }
    cout << s[s.size() - 1];
    return 0;
}
