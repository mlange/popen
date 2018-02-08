#include <moca.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


long GetCommandLength(char *format, ...)
{
    long length;

    FILE *outfile;

    va_list args;

    va_start(args, format);

    /* Open the NULL device. */
    if ((outfile = fopen(OS_NULL_DEVICE, "w")) == NULL)
	return -1;

    /* Get the length of the command as a side-effect. */
    length = vfprintf(outfile, format, args);

    /* Close the output file. */
    fclose(outfile);

    va_end(args);

    return length;
}
