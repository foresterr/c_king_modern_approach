#include <stdio.h>

#define N_STUDENTS 5
#define N_QUIZZES 5

int main(void)
{
  int scores[N_STUDENTS][N_QUIZZES];
  int sum, high, low;

  printf("For each student, enter results of quizzes 1-5 in order.\n");

  for (int i = 0; i < N_STUDENTS; i++) {
    printf("Enter student %c results: ", 'A' + i);
    for (int j = 0; j < N_QUIZZES; j++) {
      scanf("%d", &scores[i][j]);
    }
  }
  printf("\nStudent totals:\n");
  for (int i = 0; i < N_STUDENTS; i++) {
    for (int j = 0; j < N_QUIZZES; j++) {
      if (j == 0)
        sum = scores[i][j];
      else
        sum += scores[i][j];
    }
    printf("Student %c total score: %d, average score: %.2f\n", 'A' + i, sum, (float) sum / N_QUIZZES);
  };

  printf("\nQuiz totals:\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (j == 0)
        sum = high = low = scores[j][i];
      else
        sum += scores[j][i];
        if (high < scores[j][i])
          high = scores[j][i];
        if (low > scores[j][i])
          low = scores[j][i];
    }
    printf("Quiz %d average score: %.2f, high score: %d, low score: %d\n",
        i + 1, (float) sum / N_STUDENTS, high, low);
  }
  printf("\n");

  return 0;
}

