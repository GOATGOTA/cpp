// 12. ���� �������� ������ S � ����� ����� N (>0). 
// ������� ������, ���������� ������� ������ S, ����� �������� ��������� �� N �������� �*� (���������).

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
