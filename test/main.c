
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <cuishark.h>

static void* back(void* arg)
{
  char** argv = (char**)arg;
  int argc;
  for (argc=0; argv[argc]; argc++) ;
  cuishark_init(argc, argv);
  fprintf(stderr, "finish cuishark_init\n");
  return NULL;
}

static void fail(const char* msg)
{
  fprintf(stderr, "%s\n", msg);
  exit(1);
}

int main(int argc, char** argv)
{
  pthread_t backend;
  pthread_create(&backend , NULL, back, argv);

  /* sleep(2); */
  /* cuishark_apply_dfilter("ssh"); */
  /* size_t ret = cuishark_num_displayed_packets(); */
  /* if (ret != 9) fail("arp filter"); */

  pthread_join(backend, NULL);
  fprintf(stderr, "joined\n");
}
