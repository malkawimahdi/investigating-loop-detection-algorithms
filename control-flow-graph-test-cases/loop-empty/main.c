// Example generated by Dr. Martin Nyx Brain
// https://github.com/martin-cs/cbmc/blob/feature/spicy-loops/regression/cbmc/loop-empty/main.c

#include <assert.h>

void empty_loop(void)
{
loop:
    goto loop;
    return;
}

int main(int argc, char **argv)
{
    empty_loop();

    assert(0);

    return 0;
}