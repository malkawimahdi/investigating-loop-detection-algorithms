// Example generated by Mahdi Malkawi based on:
// Flow Graph Anomalies: What's in a Loop? by Michael Wolfe
// https://scholararchive.ohsu.edu/downloads/9z903022q?locale=en
// Control Flow Graph 5a, (G5a:) page 5

int main(int argc, char **argv)
{
    int first = 0;

    int condition = 5;

    do
    {
        ++first;

        if (first == condition)
        {
                    
            goto exit_loop;
        }

    } while (first < 10);

exit_loop:
    return 0;
}