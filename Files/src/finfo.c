#include "../include/files.h"

int finfo_main(char **argv) 
{
        /* Look at glibc code to see the fields of this struct. There are
         * many definitions of it with most of the fields in tact. */
        struct stat buf; 
       
        if(stat(argv[1], &buf) < 0) {
                ERROR("stat error"); 
                return EXIT_FAILURE; 
        }

        /* ls -l argv[1] gives output as below */ 
        printf("%llu %s\n", buf.st_ino, argv[1]); 

        return EXIT_SUCCESS; 
}
