
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{	
		if (s[i] == c)
			return(&s[i]);
		i++;
	}
	return(NULL);
}
