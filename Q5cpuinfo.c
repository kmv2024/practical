#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("Kernel Version:\n");
    system("cat /proc/sys/kernel/osrelease");
    printf("CPU info:\n");
    system("cat /proc/cpuinfo");
}