void delay_fv(unsigned int x, int y)
{
	unsigned int i,j;
	for(i=0;i<x;i++)
	for(j=0;j<y;j++);
}
void delay_ms(int count)
{
	int j=0,i=0;
	for(j=0;j<count;j++)
	{
		for(i=0;i<35;i++);
	}
}