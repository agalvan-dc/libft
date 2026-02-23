
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char	*c;
	const unsigned char	*p;
	size_t	i;

	i = 0;
	c = (unsigned char *)dst;
	p = (const unsigned char *)src;
	while (i < n)
	{
		c[i] = p[i];
		i++;
	}
	return (dst);
}
