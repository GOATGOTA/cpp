// 12. Даны строки S, S1 и S2.
// Заменить в строке S последнее вхождение строки S1 на строку S2

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s, s1, s2;
    cin >> s >> s1 >>  s2;
    int pos = s.rfind(s1);
    
    if(pos + 1){
        s.replace(pos, s1.size(), s2);
    }
    cout << s;
    return 0;
}
