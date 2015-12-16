double pi_bbp(int n);
double pi_leibniz(int n);

double pi_bbp(int n) //bbp function
{
    double a = 1.;
    double p = 0.;
    int k;

    for ( k = 0; k < n; k++)
    {
        int k8 = 8*k;
        double b = 4./(k8+1);
        double c = 2./(k8+4);
        double d = 1./(k8+5);
        double e = 1./(k8+6);
        p += a*(b-c-d-e);
        a /= 16.;
    }
    return p;
}

double pi_leibniz(int n) //leibniz function
{
    double p =0., o;
  
    for (int i = 0; i < n; ++i)
    {
        o = 1./(2*i+1);
        o = (i % 2 == 1) ? -o : o;
        p += o;
    }
    return 4*p;
}
