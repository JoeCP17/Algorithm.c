# include<cs50.h>
# include<stdio.h> 

void array(void) {
    
    printf("학점 프로그램\n");
    printf("종료를 원하시면 \"999\"를 입력\n");
    printf("[학점 테이블]\n");
    printf("점수 : 95   90  85  80  75  70  65  60  0\n");
    printf("학점 : A+   A   B+  B   C+  C   D+  D   F\n");

}



int main(void) { 

    array();
    int score ; 

    while (true) {

        score = get_int("당신의 성적을 입력하세요\n"); 
        if (0<=score || score <= 100) {
            if (score == 999) {
                printf("프로그램을 종료합니다\n");
                break;
            }

            if (score>=95) {
                printf("당신의 학점은 A+입니다.\n");
            }
            else if (score>=90) {
                printf("당신의 학점은 A입니다.\n");
            }
            else if (score>=85) {
                printf("당신의 학점은 B+입니다.\n");
            }
            else if (score>=80) {
                printf("당신의 학점은 B입니다.\n");
            }
            else if (score>=75) {
                printf("당신의 학점은 C+입니다.\n");
            }
            else if (score>=70) {
                printf("당신의 학점은 C입니다.\n");
            }
            else if (score>=65) {
                printf("당신의 학점은 D+입니다.\n");
            }
            else if (score>=60) {
                printf("당신의 학점은 D입니다.\n");
            }
            else  {
                printf("당신의 학점은 F입니다.\n");
            }
        }

    }
}
