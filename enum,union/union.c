#include <stdio.h>
union myUnion {
  int a;
  float b;
  char c;
}; 
//union은 멤버중 가장 큰 자료형의 공간을 공유
int main(void) {
  union myUnion me;
  me.a = 10;
  me.b = 20.2;
  me.c = 'k'; 
  //공간을 공유하기 때문에 한 멤버의 값이 변하면 다른 멤버도 같이 변한다.
  printf("%d\n", me.a);
  printf("%f\n", me.b);
  printf("%c\n", me.c);
} //값이 변해 me.a와 me.b에는 다른값이 들어갔다.