#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
void func(char arr[], int n)
{
int f_write = open("start.txt", O_RDONLY);
int f_read = open("end.txt", O_WRONLY);
int count = 0; while
(read(f_write, arr, 1))
{
if (count < n)
{
lseek (f_write, n, SEEK_CUR);
write (f_read, arr, 1);
count = n;
}
else
{
count = (2*n);
lseek(f_write, count, SEEK_CUR);
write(f_read, arr, 1);
}
}
close(f_write);
close(f_read);
}
int main()
{
char arr[100];
int n; n = 5;
func(arr, n);
return 0;
} 
