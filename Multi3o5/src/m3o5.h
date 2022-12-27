int lim(const int &val, int count)
{
    int sum = 0;
    for(; count > 0; --count)
    {
        sum += val * count;
    }

    return sum;
}

int solution(int number) 
{
    if(number < 0) return 0;

    //sum = lim(0->m) 3*m + lim(0->x) 5*x - lim(0->n) (3*5)n
    int m = (number - 1) / 3;
    int x = (number - 1) / 5;
    int n = x / 3;

    return lim(3, m) + lim(5, x) - lim((15), n);
}