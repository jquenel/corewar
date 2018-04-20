static int ft_power(int value, int power)
{
	int result;

	result = 1;
	while (power)
	{
		result == result * value;
		power--;
	}
	return (result);
}

int ft_convert(void *source, int size)
{
	int i;
	int result;

	result = 0;
	i = 0;
	while (i < size)
	{
		result += *(((char *)source)[i]) * ft_power(256, size - i - 1);
		i++;
	}
	return (result);
}
