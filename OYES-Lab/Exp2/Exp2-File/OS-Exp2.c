#include <sys/types.h>
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFSIZE 512
int main () {
int from, to, nr, nw, n; char buf[BUFSIZE],ch;
if ((from=open("one.txt", O_RDONLY)) < 0) {
printf("Error opening source file");
exit(1);
 }

 if ((to=creat("two.txt", O_RDWR)) < 0) {
printf("Error creating destination file"); exit(2);
 }
while((nr=read(from, buf, sizeof( buf))) != 0) {
if (nr < 0) {
 printf("Error reading source file");
exit(3);

 }
nw=0;
 do {
 if ((n=write(to, &buf[nw], nr-nw)) < 0) {
printf("Error writing destination file"); exit(4);
 } nw +=
n; } while (nw <
nr);
 }
printf("successfully copied the content from fiel one.txt to two.txt");
 close(from); close(to);
} 
