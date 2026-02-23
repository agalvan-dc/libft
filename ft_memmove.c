
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	const unsigned char	*s;
	size_t	i;

	i = 0;
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d < s)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else 
	{
		d += len;
		s += len;
		while (len > 0)
		{
			len--;
			d[len] = s[len];
		}
	}
	return(dst);
}
