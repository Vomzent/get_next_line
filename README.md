_This project has been created as part of the 42 curriculum by vcoevert_

# get_next_line
This function reads text from a file descriptor, then returns the next line.<br>
Starting with everything before the first newline, ending at the file end.<br>
Once it has read everything or an error occurs, it returns NULL.<br>
The goal of this project was to learn about static variables (and also to add get_next_line to my libft).<br>

# Instructions
When using this function you must compile it with `-D BUFFER_SIZE=` followed by a value.<br>
This value will be used as the amount of bytes [read(2)](https://linux.die.net/man/2/read) will try to read from the file on each call.<br>
The function is prototyped as follows: `char *get_next_line(int fd);`
It takes a file descriptor as it's only parameter. And returns either a pointer to a [malloc(3)](https://linux.die.net/man/3/malloc)'d line or a pointer to NULL on error.

# Resources
My peers!! Including but not limited to:<br>
- biversen<br>
- ivan-der<br>
- mmelo<br>
- odschreu<br>

https://www.educative.io/answers/read-data-from-a-file-using-read-in-c<br>
https://www.w3schools.com/c/ref_keyword_static.php<br>
https://github.com/Tripouille/gnlTester<br>


