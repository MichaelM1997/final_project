#include <stdio.h>
#include <limits.h>

#define MAX_JOBS 10

int n; // number of jobs
int u_j[MAX_JOBS];
int v_j[MAX_JOBS];
int LDj[MAX_JOBS];

int best_order[MAX_JOBS];
int current_order[MAX_JOBS];
int visited[MAX_JOBS];
int min_Cmax = INT_MAX;

void calculate(int level, int current_time)
{
    if (level == n)
    {
        if (current_time < min_Cmax)
        {
            min_Cmax = current_time;
            for (int i = 0; i < n; i++)
            {
                best_order[i] = current_order[i];
            }
        }
        return;
    }

    for (int j = 0; j < n; j++)
    {
        if (!visited[j])
        {
            visited[j] = 1;
            current_order[level] = j;

            int start_time = current_time;
            int proc_time = (start_time < LDj[j]) ? u_j[j] : v_j[j];

            calculate(level + 1, start_time + proc_time);

            visited[j] = 0;
        }
    }
}

int main()
{
    // Example input
    n = 8;
    int input_u[] = {31, 33, 33, 47, 30, 47, 29, 32};
    int input_v[] = {11, 21, 18, 15, 6, 19, 4, 5};
    int input_LDj[] = {130, 132, 135, 137, 147, 155, 176, 218};

    for (int i = 0; i < n; i++)
    {
        u_j[i] = input_u[i];
        v_j[i] = input_v[i];
        LDj[i] = input_LDj[i];
    }

    calculate(0, 0);

    printf("Optimal order: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", best_order[i] + 1);
    }

    printf("\nMinimum completion time (Cmax): %d\n", min_Cmax);

    return 0;
}
