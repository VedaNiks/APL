#include <iostream>
#include <pthread.h>
using namespace std;

struct param{
  int a, b;
};
typedef struct param param_t;
void *multiply(void *param);

int main(int argc, char const *argv[])
{
  param_t var1 = {1, 2};
  param_t var2 = {3, 4};
  pthread_t t1;
  pthread_t t2;
  pthread_t t3;

  // call new thread
  pthread_create(&t1, NULL, multiply, &var1);
  pthread_create(&t2, NULL, multiply, &var2);
  
  // join the thread
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  
  pthread_create(&t3, NULL, multiply, &var1);
  pthread_join(t3, NULL);


  return 0;
}

void *multiply(void *param){
  long i =10000000, j;
  param_t * parm = (param_t *)param;
  while(i--){
    j++;
  };

  cout << parm->a << endl;
}