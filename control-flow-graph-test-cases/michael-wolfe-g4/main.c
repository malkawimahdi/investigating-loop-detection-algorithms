// Example generated by Mahdi Malkawi based on:
// Flow Graph Anomalies: What's in a Loop? by Michael Wolfe
// https://scholararchive.ohsu.edu/downloads/9z903022q?locale=en
// Control Flow Graph 4, (G4:) page 4

int main(int argc, char **argv)
{
    for (int counter = 0; counter < 5; ++counter)
    {
    outer:
    loop:
        for (int counter2 = 0; counter2 < 5; ++counter2)
        {
            goto outer;

            goto loop;
        }
    }

    if (1)
    {
        goto outer;
        goto loop;
    }

    return 0;
}