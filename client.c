#include "getmax.h"

int main(int argc, char** argv)
{
    CLIENT *pclnt;
    char host[256];

    strncpy(host, argv[1], sizeof(host));

    /* 3 args: ip a b */
    if (argc < 3) {
        fprintf(stderr, "Invalid number of arguments.");
        exit(1);
    }
   
    pclnt = clnt_create(host, GETMAXPROG, GETMAXVERS, "udp");
    
    if (pclnt == NULL) {
        clnt_pcreateerror(host);
        exit(1);
    }

    struct input_data data = {
        .a = atoi(argv[2]),
        .b = atoi(argv[3])
    };

    int* result = getmax_1(&data, pclnt);

    printf("The max is : %d\n", *result);
    
    clnt_destroy(pclnt);
}