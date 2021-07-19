#include <cstdio>
#include <string.h>
#include <stdint.h> // for uint8_h, uint32_h
#include <netinet/in.h> // for ntohs, htonl
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int i=argc;

    uint32_t a1, a2, b1, b2;

    FILE *fp1 = fopen(argv[1], "rb");
    FILE *fp2 = fopen(argv[2], "rb");

    fread(&a1, sizeof(uint32_t), 1, fp1);
    fread(&a2, sizeof(uint32_t), 1, fp2);

    b1 = ntohl(a1); //nbo->hbo
    b2 = ntohl(a2); //nbo->hbo

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", b1, b1, b2, b2, b1+b2, b1+b2);
    fclose(fp1);
    fclose(fp2);

    return 0;

}
