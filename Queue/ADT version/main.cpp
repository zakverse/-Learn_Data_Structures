#include "Queue.h"

int main() {
    Queue antrian = CreateQueue(5);

    Enqueue(antrian, "Boboiboy");
    Enqueue(antrian, "Yaya");
    Enqueue(antrian, "Ying");
    Enqueue(antrian, "Gopal");

    Dequeue(antrian);
    PrintQueue(antrian);

    DestroyQueue(antrian);
    PrintQueue(antrian);

    return 0;
}
