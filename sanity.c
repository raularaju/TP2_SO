// IMPLEMENTACAO SANITY
#include "types.h"
#include "user.h"
#define N 1000000
#define CPU_BOUND 0
#define S_CPU_BOUND 1
#define IO_BOUND 2
#define RETIME 0
#define STIME 1
#define RUTIME 2
/* int empty_loop(int n)
{
    int fat = 1;
    for (int i = 0; i < n; i++)
    {
        fat *= i;
    }
    return fat;
} */
void empty_loop(){
    for (int i = 0; i < N; i++)
    {
        ;    
    }
    
}
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf(1, "Sanity expects one parameter [n]\n");
        exit();
    }

    int n = atoi(argv[1]);
    int sum[3][3] = {0};
    // loop creating 3n processes
    // Running processes
    for (int i = 0; i < 3 * n; i++)
    {
        int pid = fork();
        if (pid == 0) // if its the child
        {
            int k = (getpid());
            switch (k % 3)
            {
            case CPU_BOUND: // CPU-BOUND
                for (int i = 0; i < 100; i++)
                    empty_loop();
                break;
            case S_CPU_BOUND: // S-CPU
                for (int i = 0; i < 100; i++){
                    empty_loop();
                    yield();
                }
                break;
            case IO_BOUND: // IO-BOUND
                for (int a = 0; a < 100; a++)
                {
                    sleep(1);
                }
                break;
            default:
                break;
            }
            exit(); // exiting children processes
        }
    }


    for (int i = 0; i < 3 * n; i++)
    {
        int retime, rutime, stime;
        int k = wait2(&retime, &rutime, &stime);
        
        switch (k % 3)
        {
        case CPU_BOUND: // CPU-BOUND
            printf(1, "CPU-Bound, pid: %d, ready time: %d, running time: %d, sleeping time: %d\n", k, retime, rutime, stime);
            sum[CPU_BOUND][RETIME] += retime;
            sum[CPU_BOUND][RUTIME] += rutime;
            sum[CPU_BOUND][STIME] += stime;

            break;
        case S_CPU_BOUND: // S-CPU
            printf(1, "CPU-S Bound, pid: %d, ready time: %d, running time: %d, sleeping time: %d\n", k, retime, rutime, stime);
            sum[S_CPU_BOUND][RETIME] += retime;
            sum[S_CPU_BOUND][RUTIME] += rutime;
            sum[S_CPU_BOUND][STIME] += stime;
            break;
        case IO_BOUND: // IO-BOUND
            printf(1, "IO-Bound, pid: %d, ready time: %d, running time: %d, sleeping time: %d\n", k, retime, rutime, stime);
            sum[IO_BOUND][RETIME] += retime;
            sum[IO_BOUND][RUTIME] += rutime;
            sum[IO_BOUND][STIME] += stime;
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            sum[i][j] /= n;
        }
    }
    


    printf(1, "\n\nCPU bound:\nAverage ready time: %d\nAverage running time: %d\nAverage sleeping time: %d\nAverage turnaround time: %d\n\n\n", sum[CPU_BOUND][RETIME]/ n, sum[CPU_BOUND][RUTIME] / n, sum[CPU_BOUND][STIME] / n, (sum[CPU_BOUND][RETIME] + sum[CPU_BOUND][RUTIME] + sum[CPU_BOUND][STIME]) / n);
    printf(1, "CPU-S bound:\nAverage ready time: %d\nAverage running time: %d\nAverage sleeping time: %d\nAverage turnaround time: %d\n\n\n", sum[S_CPU_BOUND][RETIME] / n, sum[S_CPU_BOUND][RUTIME] / n, sum[S_CPU_BOUND][STIME] / n, (sum[S_CPU_BOUND][RETIME] + sum[S_CPU_BOUND][RUTIME] + sum[S_CPU_BOUND][STIME]) / n);
    printf(1, "I/O bound:\nAverage ready time: %d\nAverage running time: %d\nAverage sleeping time: %d\nAverage turnaround time: %d\n\n\n", sum[IO_BOUND][RETIME] / n, sum[IO_BOUND][RUTIME] / n, sum[IO_BOUND][STIME] / n, (sum[IO_BOUND][RETIME] + sum[IO_BOUND][RUTIME] + sum[IO_BOUND][STIME]) / n);
    exit();
}