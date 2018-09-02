link reverse(link x)
{
    while (y != NULL)
    { t = y->next; y->next = r; r = y; y = t;}
    
    return r;
}