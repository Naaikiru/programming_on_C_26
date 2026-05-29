
int count_bits_in_double(double n)
{
    unsigned char *p = (unsigned char*)&n;
    int count = 0;
    
    for(int i = 0; i < sizeof(double); i++)
    {
        for(int bit = 0; bit < 8; bit++)
        {
            if(p[i] & (1 << bit))
                count++;
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    double n;  // тип double
    printf("n=");
    scanf("%lf", &n);  // %lf для double
    printf("number of bits=%d\n", count_bits_in_double(n)); 
    //system("PAUSE");  
    return 0;
}