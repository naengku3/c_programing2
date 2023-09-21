#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//구조체 생성
struct Student {
  char name[20];
  int kr;
  int en;
  float sj_avg;
};

int main() {
  float kr_avg, en_avg; // 과목별 평균 float형으로 선언

  struct Student students[3] = {{"Shim", 90, 85},
                                {"Sung", 78, 92},
                                {"Park", 88, 79}}; //구조체 변수 초기화

  FILE *file = fopen("sj.csv", "wt");

  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  //파일을 wt모드로 열고 확인

  fprintf(file, "Name,Korean,English\n");

  for (int i = 0; i < 3; i++) {
    fprintf(file, "%s,%d,%d\n", students[i].name, students[i].kr,
            students[i].en);
  }

  fclose(file);
  printf("Data saved to sj.txt\n");
  //파일에 정보를 저장

  file = fopen("sj.csv", "rt");

  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  //파일을 rt모드로 열고 확인

  char buffer[100];
  fgets(buffer, sizeof(buffer), file);
  //헤더라인 무시

  printf("Name\tKorean\tEnglish\tavg\n");
  //헤더라인 출력

  struct Student student[3]; //정보를 파일에서 가져올 구조체변수 선언

  for (int p = 0; p < 3; p++) {
    fscanf(file, "%19[^,],%d,%d\n", student[p].name, &student[p].kr,
           &student[p].en); //파일을 스캔
    student[p].sj_avg =
        ((float)(student[p].kr + student[p].en) / 2.0); //학생 평균 계산
    printf("%s\t%d\t%d\t%0.1f\n", student[p].name, student[p].kr, student[p].en,
           student[p].sj_avg); //정보를 출력
  };

  kr_avg = ((float)(student[0].kr + student[1].kr + student[2].kr) / 3.0);
  en_avg = ((float)(student[0].en + student[1].en + student[2].en) /
            3.0); //과목별 평균 계산
  printf("avg\t%0.1f\t%0.1f\tX\n", kr_avg, en_avg);
  //정보를 출력
  fclose(file);

  file = fopen("sj.csv", "wt");

  if (file == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  // 파일을 wt모드로 열고 확인
  fprintf(file, "Name,Korean,English,avg\n");

  for (int i = 0; i < 3; i++) {
    fprintf(file, "%s,%d,%d,%0.1f\n", student[i].name, student[i].kr,
            student[i].en, student[i].sj_avg);
  }

  fprintf(file, "avg,%0.1f,%0.1f", kr_avg, en_avg);
  //정보를 저장
  
  return 0;
}