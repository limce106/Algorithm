#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    int kor;
    int eng;
    int math;
};

// 정렬 기준을 정의하는 비교 함수
bool compare(const Student& a, const Student& b) {
    // compare 함수는 학생 두 명을 비교하는데 O(1)
    if (a.kor == b.kor && a.eng == b.eng && a.math == b.math)
        return a.name < b.name;
    else if (a.kor == b.kor && a.eng == b.eng)
        return a.math > b.math;
    else if (a.kor == b.kor)
        return a.eng < b.eng;
    else
        return a.kor > b.kor;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<Student> s;

    // O(N)
    for (int i = 0; i < n; i++) {
        Student temp;
        cin >> temp.name >> temp.kor >> temp.eng >> temp.math;

        // push_back은 O(1) -> n번 실행하면 O(n)
        s.push_back(temp);
    }

    // C++의 sort()는 평균 및 최악의 경우 O(N log N)
    sort(s.begin(), s.end(), compare);

    // O(N)
    for (int i = 0; i < n; i++) {
        // endl로 썼을 때는 시간초과
        cout << s[i].name << '\n';
    }

    return 0;
}

// 전체 시간 복잡도는 O(N log N)
