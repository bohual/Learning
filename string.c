/*
 * memset - Fill a region of memory with the given value
 * @s: Pointer to the start of the area.
 * @c: The byte to fill the area with
 * @count: The size of the area.
 */
 void *memset(void *s, int c, size_t count)
 {
	 char *xs = s;
	 while (count--)
		 *xs++ = c;
	 return s;
 }
 
 /*
* memcpy - Copy one area of memory to another
* @dest: Where to copy to
* @src: Where to copy from
* @count: The size of the area.
*/
void *memcpy(void *dest, const void *src, size_t count)
{
	char *tmp = dest;
	const char *s = src;
	while(count--)
		*temp++ = *s++;
	return dest;
}

/*
 * memcmp - Compare two areas of memory
 * @cs: One area of memory
 * @ct: Another area of memory
 * @count: The size of the area.
 */
 int memcmp(const void *cs, const void *ct, size_t count)
 {
	 const unsigned char *su1, *su2;
	 for (su1 = cs, su2 = ct; 0 < count; ++su1, ++su2, count--)
		 if ((res = *su1 - *su2) != 0)
			 break;
	return res;
 }
 
 /*
 * strcpy - Copy a %NUL terminated string
 * @dest: Where to copy the string to
 * @src: Where to copy the string from
 */
 char *strcpy(char *dest, const char *src)
 {
	 char *temp = dest;
	 while((*dest++ = *src++) != '\0');
	 return temp;
 }
 
 //实现strcpy函数
 char *strcpy(char *destination, const char *source)
 {
	 assert(destination ！= NULL && source != NULL);
	 char *target = destination;
	 while ((*destination++ = *source++) != '\0');
	 return target;
 }
 
 
 /*
 * strncpy - Copy a length-limited, %NUL-terminated string
 * @dest: Where to copy the string to
 * @src: Where to copy the string from
 * @count: The maximum number of bytes to copy
 *
 * The result is not %NUL-terminated if the source exceeds
 * @count bytes.
 *
 * In the case where the length of @src is less than that of
 * count, the remainder of @dest will be padded with %NUL.
 */
 
 char *strncpy(char *dest, const char *src, size_t count)
 {
	char *temp =dest;
	
	while (count)
	{
		if ((*temp = *src) != 0)
			src++;
		temp++;
		count--;
	}
	return dest;
 }
 
 /*
 * strcat - Append one %NUL-terminated string to another
 * @dest: The string to be appended to
 * @src: The string to append to it
 */
 char *strcat(char *dest, const char *src)
 {
	 char *tmp = dest;
	 while (*dest)
		 dest++;
	 while ((*dest++ = *src++) != '\0');
	 return tmp;
 }
 
 /*
 * strncat - Append a length-limited, %NUL-terminated string to another
 * @dest: The string to be appended to
 * @src: The string to append to it
 * @count: The maximum numbers of bytes to copy
 *
 * Note that in contrast to strncpy(), strncat() ensures the result is
 * terminated.
 */
 char *strncat(char *dest, const char *src, size_t count)
 {
	 char *tmp = dest;
	 if (count)
	 {
		 while (*dest++)
			 dest++;
		 while ((*dest++ = *src++) != 0)
		 {
			 if (--count == 0)
			 {
				 *dest = '\0';
				 break;
			 }
		 }
	 }
 }
 
 
 /*
 * strcmp - Compare two strings
 * @cs: One string
 * @ct: Another string
 */
 int strcmp(const char *cs, const char *ct)
 {
	 unsigned char c1, c2;
	 while(1)
	 {
		 c1 = *cs++;
		 c2 = *ct++;
		 if (c1 != c2)
			 return c1 < c2 ? -1 : 1;
		 if (!c1)
			 break;
	 }
	 return 0;
 }
 
 //手写strcmp
 int strcmp1(char *l, char *r)
 {
	 assert(l != NULL && r != NULL);
	 while (*l == *r && *l != '\0')
	 {
		 l++;
		 r++;
	 }
	 if (*l > *r)
		 return 1;
	 else if (*l == *r)
		 return 0;
	 else 
		 return -1;
 }
 
 /*
 * strncmp - Compare two length-limited strings
 * @cs: One string
 * @ct: Another string
 * @count: The maximum number of bytes to compare
 */
 int strncmp(const char *cs, const char *ct, size_t count)
 {
	 unsigned char c1, c2;
	 while (count)
	 {
		 c1 = *cs++;
		 c2 = *ct++;
		 if (c1 != c2)
			 return c1 < c2 ? -1 : 1;
		 if ((!c1)
			 break;
		 count--;
 }
 
 /*
 * strchr - Find the first occurrence of a character in a string
 * @s: The string to be searched
 * @c: The character to search for
 */
 char *strchr(const char *s, int c)
 {
	 for (; *s != (char)c; ++s)
		 if (*s == '\0')
			 return NULL;
		
	return (char *)s;
 }
 
 /*
 * strlen - Find the length of a string
 * @s: The string to be sized
 */
 size_t strlen(const char *s)
 {
	 const char *sc;
	 for (sc = s; *sc != '\0'; ++sc)
		 ;
	 return sc - s;
 }
 
 /*
 * strnlen - Find the length of a length-limited string
 * @s: The string to be sized
 * @count: The maximum number of bytes to search
 */
 
 size_t strnlen(const char *s, size_t count)
 {
	 const char *sc;
	 for (sc = s; count-- && *sc != '\0'; sc++)
		 ;
	 return sc -s;
 }
 

/*
 * strstr - Find the first substring in a %NUL terminated string
 * @s1: The string to be searched
 * @s2: The string to search for
 */
 
 char *strstr(const char  *s1, const char *s2)
 {
	 int l1, l2;
	 
	 l2 = strlen(s2);
	 if (!l2)
		 return (char *)s1;
	 l1 = strlen(s1);
	 while (l1 >= l2)
	 {
		 l1--;
		 if (!memcmp(s1, s2, l2))
			 return (char *)s1;
		 s1++;
	 }
	 return NULL;
	 
 }
 

//写出在母串中查找子串出现次数的代码
int count1(char *str, char *s）
{
	char *s1;
	char *s2;
	int count = 0;
	while (*str != '\0')
	{
		s1 = str;
		s2 = s;
		while (*s2 == *s1 && (*s2 != '\0') && (*s1 != '\0'))
		{
			s2++;
			s1++;
		}
		if (*s2 == '\0')
			count++;
		str++;
	}
}

//实现字符串反转(不使用strlen)
void reverse(char *str)
{
	if (str == NULL)
		return;
	char *p1 = str;
	char *p2 = str - 1;
	while (*++p2)
		;
	p2 -= 1;
	while (p1 < p2)
	{
		char c = *p1;
		*p1++ = *p2;
		*p2-- = c;
	}
}

//给定字符串A和B,输出A和B中的最大公共子串。
//比如A="aocdfe" B="pmcdfa" 则输出"cdf"
char *commonstring(char shortstring[], char longstring[])
{
	int i, j;
	char *substring = (char *)malloc(sizeof(int) * 250);
	if (strstr(longstrig, shortstring) != NULL)
		return shortstring;
	for (i = strlen(substring) - 1; i > 0; i--)
	{
		for (j = 0; j <= strlen(substring) - i; j++)
		{
			memcpy(substring, &shortstring[j], i);
			substring[i] = '\0';
			if (strstr(long string, substrig) != NULL)
				return substring;
		}
	}
	return NULL;
}

//内存拷贝实现(考虑内存重叠的情况)
char *memcpy(char *dst, const char *src, int cnt)
{
	assert (dst != NULL && src != NULL);
	char *ret = dst;
	if (dst >= src && dst<= src + cnt -1)
	{
		dst = dst + cnt - 1;
		src = src + cnt - 1;
		while (cnt--)
		{
			*dst-- = *src--;
		}
		else
		{
			while (cnt--)
			{
				*dst++ = *src++;
			}
		}
	}
	return ret;
}

//内存拷贝实现（考虑内存重叠，优化版本）
void *memcpy(void *dst, const void *src, unsigned int len)
{
	register char *d;
	register char *s;
	if (len == 0)
		return dst;
	if (dst > src)
	{
		d = (char *)dst + len - 1;
		s = (char *)src + len - 1;
		while (len >= 4)
		{
			
			*d-- = *s--;
			*d-- = *s--;
			*d-- = *s--;
			*d-- = *s--;
		}
		while (len--)
		{
			*d-- = *s--;
		}
	}
	else if (dst < src)
	{
		d = (char *)dst;
		s = (char *)src;
		while (len >= 4)
		{
			*d++ = *s++;
			*d++ = *s++;
			*d++ = *s++;
			*d++ = *s++;
		}
		while (len--)
		{
			*d++ = *s++;
		}
	}
	return dst;
}

//将一个数字字符串转换为数字
int atoi(char *s)
{
	assert(s != NULL);
	int num = 0;
	int temp;
	while (*s > '0' && *s < '9')
	{
		num *= 10;
		num += *s - '0';
		s++;
	}
	return num;
}

//编写一个c函数，该函数在一个字符串中找到可能的最长的子字符串
//且该字符串由同一个字符组成
char *search(char *cpSource, char ch)
{
	char *cpTemp = NULL;
	char *cpDest = NULL;
	int iTemp;
	int iCount = 0;
	while (*cpSource)
	{
		if (*cpSource == ch)
		{
			iTemp = 0;
			cpTemp = cpSource;
			while (*cpSource == ch)
			{
				++iTemp;
				++cpSource;
			}
			if (iTemp > iCount)
			{
				iCount = iTemp;
				cpDest = cpTemp;
			}
			if (!*cpSource)
				break;
		}
		cpSource++;
	}
	return cpDest;
}


/*
写一个函数,它的原形是int continumax(char *outputstr,char *intputstr)
功能：
在字符串中找出连续最长的数字串，并把这个串的长度返回，
并把这个最长数字串付给其中一个函数参数outputstr所指内存。
例如："abcd12345ed125ss123456789"的首地址传给intputstr后，
函数将返回9，outputstr所指的值为123456789

*/
int countinumax(char *outputstr, char *inputstr)
{
	char *in = inputstr;
	char *out = outputstr;
	int *temp = NULL;
	int *final = NULL;
	int count = maxlen = 0;
	while (*in != '\0)
	{
		if (temp = in; *in > 47 && *in < 58; i++)
			count++;
		else
			in++;
		if (maxlen < count)
		{
			maxlen = count;
			count  = 0;
			final = temp;
		}
	}
	for (int i = 0; i < maxlen; i++)
	{
		*out++ = *final++;
	}
	*cout = '\0';
	return maxlen;
}