#include <stdio.h>
#include <string.h>

void magic_num_lookup(unsigned char *buffer);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    printf("File provided: %s\n", argv[1]);

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL) {
        perror("Could not open file");
        return 1;
    }

    unsigned char buffer[16];

    size_t bytes_read = fread(buffer, 1, sizeof(buffer), file);

    if (bytes_read < 4) {
        printf("File too small\n");
        fclose(file);
        return 1;
    }

    for (int i = 0; i < bytes_read; i++) {
        printf("%02x ", buffer[i]);
    }

    printf("\n");

    magic_num_lookup(buffer);

    fclose(file);

    return 0;
}


void magic_num_lookup(unsigned char *buffer)
{
    FILE *reference = fopen("magicnum_reference.txt", "r");

    if (reference == NULL) {
        perror("Could not open reference file");
        return;
    }

    // Convert first 4 bytes into a single number
    unsigned int file_magic =
        (buffer[0] << 24) |
        (buffer[1] << 16) |
        (buffer[2] << 8) |
        buffer[3];


    char line[256];

    while (fgets(line, sizeof(line), reference))
    {
        char magic[64];
        char description[128];

        sscanf(line, "%[^|]|%[^\n]", magic, description);

        unsigned int magic_value;

        sscanf(magic, "%x", &magic_value);


        if (file_magic == magic_value)
        {
            printf("MATCH: %s\n", description);
            fclose(reference);
            return;
        }
    }

    printf("Unknown file type\n");

    fclose(reference);
}