#include <stdio.h>

/*Function consumes text from a given file pointer.
  In this demo, the file pointer is stdin, which has piped
  text from cat. */
void process_stdin_se(FILE* in)
{
    char buf[100];
    while ( fgets(buf, sizeof(buf), in) )
    {
        printf("%s", buf);
    }
}

/*Function calls the side-effect laden function and passes in 
  its own FILE* argument. The function then attempts to rewind
  the file stream and print it again, but it fails with piped
  input 
  
  Therefore, a side effect is visible from the calling function.*/
void side_effects(FILE* in)
{
    char buf[100];

    process_stdin_se(in);

    rewind(in);

    while ( fgets(buf, sizeof(buf), in) )
    {
        printf("%s", buf);
    }
    
}

int main()
{
    side_effects(stdin);
    
    return 0;
}
