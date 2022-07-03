#include "Queue.h"

int main() {
  Queue<int> P;

  P.enqueue(3, 'I');
  P.enqueue(8, 'D');
  P.enqueue(10, 'I');
  P.dequeue('D');
  P.enqueue(12, 'D');
  P.dequeue('I');

  P.show('I');

  return 0;
}
