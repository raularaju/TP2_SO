#define NPROC        64  // maximum number of processes
#define KSTACKSIZE 4096  // size of per-process kernel stack
#define NCPU          8  // maximum number of CPUs
#define NOFILE       16  // open files per process
#define NFILE       100  // open files per system
#define NINODE       50  // maximum number of active i-nodes
#define NDEV         10  // maximum major device number
#define ROOTDEV       1  // device number of file system root disk
#define MAXARG       32  // max exec arguments
#define MAXOPBLOCKS  10  // max # of blocks any FS op writes
#define LOGSIZE      (MAXOPBLOCKS*3)  // max data blocks in on-disk log
#define NBUF         (MAXOPBLOCKS*3)  // size of disk block cache
#define FSSIZE       1000  // size of file system in blocks
#define INTERV 5     // MODIFICAÇÃO: Quantidade de tempo que o processo deve executar antes de ser preemptado
#define _1T02 200    // MODIFICAÇÃO: Quantidade de tempo que o processo de prioridade 1 deve esperar antes de subir de prioridade
#define _2T03 300    // MODIFICAÇÃO: Quantidade de tempo que o processo de prioridade 2 deve esperar antes de subir de prioridade