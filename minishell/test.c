#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>

static char *line_read = (char *)NULL;

/* Read a string, and return a pointer to it.  Returns NULL on EOF. */
int main(void)
{
  /* If the buffer has already been allocated, return the memory
     to the free pool. */
	 while(1)
	 {
  if (line_read)
    {
      free (line_read);
      line_read = (char *)NULL;
    }

  /* Get a line from the user. */
  line_read = readline ("\n");
	printf("rl_on_new_line: %d\n", rl_on_new_line());
	printf("line_read : %s\n", line_read);
  /* If the line has any text in it, save it on the history. */
  if (line_read && *line_read)
    add_history (line_read);
	 }
}
