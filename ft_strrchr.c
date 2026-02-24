
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c != 0)
	{
		while (s[i])
			i++;
		i -= 1;
		while (i > 0 && s[i] != c)
		{
			if (s[i] == c)
				return(&s[i]);
			i--;
		}
	}
	return (NULL);
}
