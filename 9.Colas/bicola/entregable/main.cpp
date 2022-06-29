#include "Queue.h"

int main() {
  Queue<int> P;
  P.enqueue(3, 'I');  // 3
  P.enqueue(8, 'D');  // 8 3
  P.enqueue(10, 'I'); // 8 3 10
  P.dequeue('D');     // 8 3
  P.enqueue(12, 'D'); // 12 8 3
  P.dequeue('I');     // 8 3
  P.printQueue('I');    // "8 3"
  return 0;
}
