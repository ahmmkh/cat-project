#include <unistd.h>
#include <fcntl.h>
#define SIZ 512

void print_char_star(char *buf)
{
    size_t i = 0;
    while (buf[i] != '\0')
        i++;
    write(1, buf, i);
}
void print_char_star_err(char *buf)
{
    size_t i = 0;
    while (buf[i] != '\0')
        i++;
    write(2, buf, i);
}
void cat_read(char *f_name)
{
    char storage[SIZ];
    int file = open(f_name, O_RDONLY);
    if (-1 == file)
    {
        print_char_star_err("file doesn't exist");
    }
    else
    {

        int return_read_bytes;
        // while(read(file, storage, SIZ)>0)
        /**http://www.cs.uregina.ca/Links/class-info/330/SystemCall_IO/SystemCall_IO.html**/
        while ((return_read_bytes = read(file, storage, SIZ)) != 0)
            write(1, &storage, return_read_bytes);

        close(file);
    }
}
int main(int argc, char *argv[])
{

    if (argc < 2)
    {
        char in_store[SIZ];
        int ret_size;
        // the <file1> file2 case
        while ((ret_size = read(0, in_store, SIZ)) != 0)
            write(1, &in_store, ret_size);
    }
    else
    {
        for (size_t i = 1; i < argc; i++)
            cat_read(argv[i]);
    }

    return 0;
}