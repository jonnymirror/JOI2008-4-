#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//vector<pair<int,int>>—p‚Ì“ñ•ª’Tõ‚ÌÀ‘•
bool binary_search_for_pair(vector<pair<int, int>> A, pair<int, int> key) {//‚¯‚ñ‚¿‚å‚ñ–{‚ğ‰ü—Ç
    int left = 0;
    int right = A.size() - 1;
    double count = 0;
    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (A[mid] == key) {
            return true;
        }
        else if (A[mid] > key) {
            right = mid - 1;
        }
        else if (A[mid] < key) {
            left = mid + 1;
        }
        count++;
    }
    return false;
}

int main(int, char**) {
    int m;
    cin >> m;
    vector<pair<int, int>> want_to_search(m);
    for (int i = 0; i < m; i++) {
        cin >> want_to_search[i].first >> want_to_search[i].second;
    }
    int n;
    cin >> n;
    vector<pair<int, int>> now_stars(n);
    for (int i = 0; i < n; i++) {
        cin >> now_stars[i].first >> now_stars[i].second;
    }
    sort(now_stars.begin(), now_stars.end());
    for (int i = 0; i < n; i++) {
        int dx = now_stars[i].first - want_to_search[0].first;
        int dy = now_stars[i].second - want_to_search[0].second;
        bool exist = true;
        for (int j = 0; j < m; j++) {
            pair<int, int> new_star;
            new_star.first = want_to_search[j].first + dx;
            new_star.second = want_to_search[j].second + dy;
            if (!binary_search_for_pair(now_stars, new_star)) {
                exist = false;
                break;
                }
            }
        if (exist) {
            cout << dx << " " << dy << endl;
            return 0;
        }
        }
    
    return 0;
}