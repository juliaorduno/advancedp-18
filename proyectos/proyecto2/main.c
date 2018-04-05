#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
char input[100][100];

void followPath(int *i, int *j, int *dir, int *isArrow, int *R, int *C)
{
  int x = *i + dx[*dir];
  int y = *j + dy[*dir];
  isArrow = 0;

  while (x >= 0 && x < *R && y >= 0 && y < *C)
  {
    char current = input[x][y];
    if (current != '.')
    {
      *isArrow = 1;
      break;
    }
    x += dx[*dir];
    y += dy[*dir];
  }
}

int main()
{
  int R, C, T;
  char current;
  int currentDir;
  int x, y, isArrow;
  int minChanges;

  printf("Number of Test Cases:\n");
  scanf("%d", &T);

  for (int t = 1; t <= T; t++)
  {

    printf("Case #%d\n", t);

    printf("Rows and Columns\n");
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++)
    {
      printf("%d\n", i);
      for (int j = 0; j < C; j++)
      {
        scanf(" %c", &input[i][j]);
      }
    }

    minChanges = 0;
    for (int i = 0; i < R; i++)
    {
      for (int j = 0; j < C; j++)
      {
        current = input[i][j];
        if (current == '.')
        {
          continue;
        }
        switch (current)
        {
        case '<':
          currentDir = 1;
          break;
        case '^':
          currentDir = 0;
          break;
        case '>':
          currentDir = 3;
          break;
        case 'v':
          currentDir = 4;
          break;
        }

        followPath(&i, &j, &currentDir, &isArrow, &R, &C);

        if (!isArrow)
        {
          for (int dir = 0; dir < 4; dir++)
          {
            if (dir != currentDir)
            {
              followPath(&i, &j, &dir, &isArrow, &R, &C);
            }
            if (isArrow)
            {
              break;
            }
          }
          if (isArrow)
          {
            minChanges++;
          }
          else
          {
            minChanges = -1;
            break;
          }
        }
      }
      if (minChanges == -1)
      {
        break;
      }
    }

    if (minChanges == -1)
    {
      printf("IMPOSSIBLE\n");
    }
    else
    {
      printf("%d\n", minChanges);
    }
  }

  return 0;
}