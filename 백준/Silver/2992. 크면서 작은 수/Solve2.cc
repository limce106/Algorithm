#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
  string num;
  cin >> num;

  if(next_permutation(num.begin(), num.end()))
      cout << num;
  else
      cout << 0;
    
  return 0;
}

// bool next_permutation(Iterator first, Iterator last); 순열을 사전 순 기준으로 다음 순열로 바꿔주는 함수
// 다음 순열이 있으면 true 반환, 없으면 false 반환
// num의 현재 순서를 기준으로 다음 순열이 뭔지 계산해서 알려줌
