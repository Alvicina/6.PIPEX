
The goal of this project is to understand how pipes and redirections work in a UNIX environment. The program takes the argv[1] as the input to be processed by the first command, which is the argv[2]. The argv[2] does not show the output through standard output, instead it is "piped" to the second command, which is argv[3]. Argv[3] then sends the output to a file called "outfile" which is argv[4]. This implementation would be the non-bonus part of the project:

![Sin título](https://github.com/user-attachments/assets/972715f4-f30a-4a73-a6c9-29a45f1fcb19)

For the bonus part, the schema is almost the same. The thing is that for the bonus, the number of argvs is not just argv = till argv[4]. It can be as many as commands are needed to be executed. However, argv[1] and argv[last] will always be infile and outfile:
![Sin título](https://github.com/user-attachments/assets/1771db3b-48a9-440c-ad8d-0ca15422e71e)

To complete the bonus part it is also mandatory to implement "<<" aka "here_document". Using this syntax in bash you can redirect multiple input lines to a command directly typing them. Whatever is written after the "<<" will be considered the EOF:
![Sin título](https://github.com/user-attachments/assets/b525788d-c68c-4f5e-8e29-e6c7dd3c223e)

In my case, the bonus part was done but not evaluated.

This project was first done and finished in a different repo to this one (42 camps provides us with independent repos for each project). Once finished, the project was then copied to my personal repo in gitHub.

In the following pdf you can find the project requirements as specified by 42 campus: [README_PIPEX.pdf](https://github.com/Alvicina/PIPEX/files/15310103/README_PIPEX.pdf)

The following snapshot if proof that the project was succesfully done:
![Sin título](https://github.com/user-attachments/assets/b08f5af1-f462-4176-90ce-e1eb34cb5cea)



