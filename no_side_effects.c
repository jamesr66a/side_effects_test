#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Functin takes a file name, opens the file, and 
 * dumps all the content to the console. No side
 * effects are visible to the calling function
 * (closing the file handle opened, however
 * it functions the same whether you do that
 * or not. To maintain a pure side-effect 
 * free execution, I do it here)
 */
int process_stdin_nse(char* filename)
{
    char buf[100];
    FILE* file_ptr = fopen(filename, "r");
    assert(file_ptr);

    while ( fgets( buf, sizeof(buf), file_ptr ) )
    {
        printf("%s", buf);
    }

    fclose(file_ptr);

    return 0;
}

/* Function calls the non-side effect function for
 * process stdin. It then does the same thing after-
 * ward, completing successfully since no side 
 * effects are visible to this function, in contrast
 * to passing in a file handle (which could poten-
 * tially be to piped output)
 */
int no_side_effects(char* filename)
{
    char buf[100];
    FILE* file_ptr;

    process_stdin_nse(filename);
    
    /*Now print out the same info*/
    file_ptr = fopen(filename, "r");

    while ( fgets( buf, sizeof(buf), file_ptr ) )
    {
        printf("%s", buf);
    }

    return 0;
}

/* Get the contents of stdin (in this test, piped
 * from cat) and immediately store it into a temp
 * file. Then call the no_side_effects test.
 */
int main()
{
    char buf[100];
    char tmp_file[100] = "tmp_file";
    FILE* temp;
  
    /*storing stdin into a temp file */
    temp = fopen(tmp_file, "w");
    assert(temp);

    while ( fgets(buf, sizeof(buf), stdin) )
    {
        fputs(buf, temp);
    }

    fclose(temp);

    no_side_effects(tmp_file);

    return 0;
}
