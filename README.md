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
https://www.gutenberg.org/browse/scores/top<br>

# The algorithm explained
First we define a static buffer array, this array will store the last bytes read from [read(2)]((https://linux.die.net/man/2/read).
The algorithm first tries to fill the buffer with as many new bytes as possible. It does this by first checking if there's an old leftover string. Deleting it if so. Then filling up all the empty space with a read from buffer.
Once we then have a maximally filled buffer we ask "is there a newline in this buffer or is the buffer empty?" If not that means we haven't gotten to the end of a string yet. We store our not yet finished string in return and read again.
When we do reach a newline or recieve nothing from read(2) it means our string is finished, we put the end of our finished string in return and give it's memory adress as return value. Checking along the way if the file descriptor is still valid. or if the string we are about to make is empty. Which in case we return a pointer to NULL.
