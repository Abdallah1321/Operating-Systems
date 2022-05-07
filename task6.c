#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4096

int main(int argc, char **argv) {
    unsigned int address;
    unsigned int page_number;
    unsigned int offset;

    if(argc<2) {
        printf("Enter the address\n");
        return -1;
    }

    address = atoi(argv[1]);
    page_number = address / PAGE_SIZE;
    offset = address % PAGE_SIZE;

    printf("The address is %u\nPage number = %u\noffset = %u\n", address, page_number, offset);

    return 0;
}