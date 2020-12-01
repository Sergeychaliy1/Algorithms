﻿// lab - двухмерный массив, в котором хранится лабиринт
// n,m - количество строк и столбцов в массиве lab
// si,sj - начальная позиция
// fi,fj - конечная позиция

typedef struct point { int i, j; } point;

int di[4] = { -1, 0, 1,  0 };
int dj[4] = { 0, 1, 0, -1 };
 const int n = 6;
 const int m = 5;
int d[n][m];            // массив расстояний 
int head, tail;          // указатели очереди
point queue[n * m];       // очередь

// обнуляем массив расстояний
for (i = 0; i < n; i++)
{
    for (j = 0; j < m; j++)
    {
        d[i][j] = 0;
        d[si][sj] = 1;          // расстояние до начальной клетки равно 1 


    // инициализируем очередь
        head = tail = 0;
        queue[tail].i = si;
        queue[tail++].j = sj;   // заносим в очередь начальную клетку
    }

    while (head < tail)     // цикл пока очередь не пуста
    {
        point p = queue[head++];          // берем следующую позицию из очереди
        for (int k = 0; k < 4; k++)       // цикл по соседним клеткам
        {
            point newp;
            newp.i = p.i + di[k];
            newp.j = p.j + dj[k];
            // проверяем, что такая клетка есть
            if (0 <= newp.i && newp.i < n && 0 <= newp.j && newp.j < m)
                // проверяем, что она свободна и ранее ее не посещали
                if (lab[newp.i][newp.j] != '#' && d[newp.i][newp.j] == 0)
                {
                    d[newp.i][newp.j] = d[p.i][p.j] + 1;     // находим расстояние 
                    queue[tail++] = newp;                    // заносим позицию в очередь
                }
        }
    }
}


if (d[fi][fj])
printf("расстояние = %d\n", d[fi][fj]);
else
printf("нет ни одного пути");
