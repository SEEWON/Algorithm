// A chef has collected data on the satisfaction level of his n dishes. Chef can
// cook any dish in 1 unit of time.

// Like-time coefficient of a dish is defined as the time taken to cook that
// dish including previous dishes multiplied by its satisfaction level i.e.
// time[i] * satisfaction[i].

// Return the maximum sum of like-time coefficient that the chef can obtain
// after dishes preparation.

// Dishes can be prepared in any order and the chef can discard some dishes to
// get this maximum value

// sort해서 |음수 합| < 양수 합 이면 안건드는 게 이득
// 아니면 |음수|가 젤 큰 거 하나씩 없애면서 다시 비교
// satisfaction = [-2, 5, -1, 0, 3, -3]

//           1,  2,  3, 4, 5, 6
// sort) * [-3, -2, -1, 0, 3, 5]
//     ---------------------------
// Value =  -3, -4, -3, 0, 15, 30

// Dish를 하나 제거하면, 그릇 수가 하나씩 밀리니깐 양수는 satisfaction을 다 더한
// 것만큼 손해를 보고, 음수는 제거한 dish, 그리고 남아 있는 음수의
// satisfaction을 더한 것만큼 이득을 본다 그 이득을 비교해서 dish를 제거할지
// 말지 결정!

#include <stdio.h>
int result(int *arr, int size) {
  int res = 0;
  for (int i = 0; i < size; i++) {
    res += arr[i] * (i + 1);
  }
  return res;
}

int compareProfit(int *satisfaction, int satisfactionSize, int index0) {
  int negSum = 0, posSum = 0;
  for (int i = 0; i < satisfactionSize; i++) {
    if (i < index0) {
      negSum += satisfaction[i];
    } else if (i >= index0) {
      posSum += satisfaction[i];
    }
  }
  if (posSum < -1 * negSum) {
    return 1;
  } else {
    return 0;
  }
}

int *leave(int *data, int count) {
  for (int i = 1; i < count; i++) {
    data[i - 1] = data[i];
  }
  return data;
}

int maxSatisfaction(int *satisfaction, int satisfactionSize) {
  int find0 = -1;  // 0, 혹은 음수 양수의 경계를 찾아서 인덱스 반환
  for (int i = 0; i < satisfactionSize; i++) {
    for (int j = 0; j < satisfactionSize - 1; j++) {
      if (satisfaction[j] > satisfaction[j + 1]) {
        int temp = satisfaction[j];
        satisfaction[j] = satisfaction[j + 1];
        satisfaction[j + 1] = temp;
      }
    }
  }

  if (satisfaction[0] == 0) {
    find0 = 0;
  } else {
    for (int i = 0; i < satisfactionSize - 1; i++) {
      int product = satisfaction[i] * satisfaction[i + 1];
      if (product == 0 || product < 0) {
        find0 = i + 1;
        break;
      }
    }
  }

  int token;
  if (find0 == -1 && satisfaction[0] < 0) {  // 다 음수
    return 0;
  } else if (find0 == 0 || (find0 == -1 && satisfaction[0] > 0)) {
    return (result(satisfaction, satisfactionSize));
  } else {
    token = compareProfit(satisfaction, satisfactionSize, find0);
  }

  // 양수가 얻는 이득이 커지면 compareProfit에서 0을 반환, 루프 탈출
  while (token) {
    satisfaction = leave(satisfaction, satisfactionSize);
    satisfactionSize--;
    find0--;
    token = compareProfit(satisfaction, satisfactionSize, find0);
  }

  return (result(satisfaction, satisfactionSize));
}

void main() {
  int arr[3] = {4, 3, 2};
  printf("%d\n", maxSatisfaction(arr, 3));
  return;
}
