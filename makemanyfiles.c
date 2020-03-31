#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

int main ( int argc, char ** argv )
{
unsigned long long  start_num, count; 
unsigned long long cursor = -1;
int file_handle; 
char *filename;
char *dirname;
mode_t dir_mode = S_IWRITE|S_IREAD|S_IEXEC;

if ( argc < 2 ) { 
	printf ("usage: gomakefiles <startnum> <endnum>\n"); 
	exit (EDOOFUS);
}
filename  = calloc ( sizeof(char), 1024); 

start_num = strtoll ( argv[1],NULL,0 ) ;
count = strtoll ( argv[2],NULL,0 ) ;

dirname  = calloc ( sizeof(char), 1024); 
//get timestamp as a unique-ish thing
sprintf (dirname,   "noncedir%lX", time(NULL));
mkdir( dirname, dir_mode ); 
chdir( dirname ); 
//printf ( "d"); 

errno =0;
for ( cursor = start_num; cursor < start_num + count ; cursor ++ ) 
	{
	sprintf (filename,   "nonce%llX", cursor);
	file_handle = open ( filename,O_CREAT|O_RDWR,S_IRWXU); 
	write ( file_handle , &cursor, sizeof(cursor) );
	close ( file_handle); 
	if ( errno != 0 ) { perror ("died"); printf (" at %llX \n", cursor ); }
	}
return ( 0 );
}
