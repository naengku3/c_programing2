#include <stdio.h>
enum Light {
  red, // red == 0과 같다.
  orange, // red부터 순차적으로 0, 1, 2 즉 orange == 2
  green
}; 
int main(void) {
  enum Light now = green; //enum Light의 변수 now 선언
  if(now == red) {
    printf("빨간불 입니다.");
  }
  else if(now == orange) {
    printf("주황불 입니다.");
  }
  else if(now == green) {
    printf("초록불 입니다.");
  } //now = green으로 선언했기 때문에 "초록불 입니다." 출력
  return 0;
} 