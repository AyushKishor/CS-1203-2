#include <stdio.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 3; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
    return 0;
}

/*
If there's only one disk, move it from the source rod to the destination rod.
If there are more than one disk, move the top n-1 disks from the source rod to the auxiliary rod using the destination rod as auxiliary.
Move the nth disk from the source rod to the destination rod.
Move the n-1 disks from the auxiliary rod to the destination rod using the source rod as auxiliary.
*/