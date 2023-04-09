#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

static  long shared = 0;
static sem_t sem;

enum {THREADS = 4};
