// Example generated by Mahdi Malkawi
// Example of unreachable code, in which the latter half contains a cycle.
// Technically algorithms should make no attempt at detecting the cycle, however is detecting the cycle wrong?
int main(int argc, char **argv)
{
    print("Hello World! \n");
    
    return 0;

    // Unreachable code begins..
    int sum  = 0;

    for (int i = 0; i < 10; ++i)
    {
        sum += i; 
    }
}