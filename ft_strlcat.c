
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (src[k])
		k++;
	while (dst[i])
		i++;
	if (i >= dstsize)
		return (i + destsize);
	while(src[j] && j < dstsize - i - 1)
	{	
		dst[i + j] = src[j];
		j++;
	}
		dst[i + j] = '\0';
	return (i + k);
}
