#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int N; // 주차공간 수
    int M; // 차량 수
    cin >> N >> M;

    // 배열은 상수 크기만을 가질 수 있으므로 벡터 사용
    vector<int> cost(N); // 주차 공간 s의 가격
    vector<int> weight(M); // k번째 차의 무게
    vector<int> isParking = vector<int>(N, 0); // 주차 여부, 0이면 비어있고 아니라면 차량 번호 값을 갖는다.

    for (int i = 0; i < N; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> weight[i];
    }

    int CarNum;
    queue<int> waitingCar;
    int price = 0;

    for (int i = 0; i < 2 * M; i++) {
        cin >> CarNum;
        bool FindSpace = false;

        // 양수라면 빈 공간을 찾는다.
        if (CarNum > 0) {
            for (int i = 0; i < N; i++) {
                // 빈 공간을 찾으면 차 번호를 저장한다.
                if (isParking[i] == 0) {
                    isParking[i] = CarNum;
                    FindSpace = true;
                    break;
                }
            }
            // 못 찾으면 대기시킨다.
            if (!FindSpace) {
                waitingCar.push(CarNum);
            }
        }
        // 음수라면 가격을 계산하고 대기 중인 차를 나간 자리에 주차시킨다.
        else {
            int abCarNum = (-1) * CarNum;
            for (int i = 0; i < N; i++) {
                if (isParking[i] == abCarNum) {
                    price += cost[i] * weight[abCarNum-1];

                    if (!waitingCar.empty()) {
                        isParking[i] = waitingCar.front();
                        waitingCar.pop();
                    }
                    else {
                        isParking[i] = 0;
                    }
                    break;
                }
            }
        }
    }
    cout << price;

    return 0;
}
