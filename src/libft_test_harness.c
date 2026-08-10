#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

#include <ctype.h>
#include <dlfcn.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LT_WEAK_STUB __attribute__((weak))

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

LT_WEAK_STUB int	ft_isalpha(int c) { (void)c; return (0); }
LT_WEAK_STUB int	ft_isdigit(int c) { (void)c; return (0); }
LT_WEAK_STUB int	ft_isalnum(int c) { (void)c; return (0); }
LT_WEAK_STUB int	ft_isascii(int c) { (void)c; return (0); }
LT_WEAK_STUB int	ft_isprint(int c) { (void)c; return (0); }
LT_WEAK_STUB size_t	ft_strlen(const char *s) { (void)s; return (0); }
LT_WEAK_STUB void	*ft_memset(void *b, int c, size_t len) { (void)c; (void)len; return (b); }
LT_WEAK_STUB void	ft_bzero(void *s, size_t n) { (void)s; (void)n; }
LT_WEAK_STUB void	*ft_memcpy(void *dst, const void *src, size_t n) { (void)src; (void)n; return (dst); }
LT_WEAK_STUB void	*ft_memmove(void *dst, const void *src, size_t len) { (void)src; (void)len; return (dst); }
LT_WEAK_STUB size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize) { (void)dst; (void)src; (void)dstsize; return (0); }
LT_WEAK_STUB size_t	ft_strlcat(char *dst, const char *src, size_t dstsize) { (void)dst; (void)src; (void)dstsize; return (0); }
LT_WEAK_STUB int	ft_toupper(int c) { return (c); }
LT_WEAK_STUB int	ft_tolower(int c) { return (c); }
LT_WEAK_STUB char	*ft_strchr(const char *s, int c) { (void)s; (void)c; return (NULL); }
LT_WEAK_STUB char	*ft_strrchr(const char *s, int c) { (void)s; (void)c; return (NULL); }
LT_WEAK_STUB int	ft_strncmp(const char *s1, const char *s2, size_t n) { (void)s1; (void)s2; (void)n; return (0); }
LT_WEAK_STUB void	*ft_memchr(const void *s, int c, size_t n) { (void)s; (void)c; (void)n; return (NULL); }
LT_WEAK_STUB int	ft_memcmp(const void *s1, const void *s2, size_t n) { (void)s1; (void)s2; (void)n; return (0); }
LT_WEAK_STUB char	*ft_strnstr(const char *big, const char *little, size_t len) { (void)big; (void)little; (void)len; return (NULL); }
LT_WEAK_STUB int	ft_atoi(const char *nptr) { (void)nptr; return (0); }
LT_WEAK_STUB void	*ft_calloc(size_t nmemb, size_t size) { (void)nmemb; (void)size; return (NULL); }
LT_WEAK_STUB char	*ft_strdup(const char *s1) { (void)s1; return (NULL); }
LT_WEAK_STUB char	*ft_substr(char const *s, unsigned int start, size_t len) { (void)s; (void)start; (void)len; return (NULL); }
LT_WEAK_STUB char	*ft_strjoin(char const *s1, char const *s2) { (void)s1; (void)s2; return (NULL); }
LT_WEAK_STUB char	*ft_strtrim(char const *s1, char const *set) { (void)s1; (void)set; return (NULL); }
LT_WEAK_STUB char	**ft_split(char const *s, char c) { (void)s; (void)c; return (NULL); }
LT_WEAK_STUB char	*ft_itoa(int n) { (void)n; return (NULL); }
LT_WEAK_STUB char	*ft_strmapi(char const *s, char (*f)(unsigned int, char)) { (void)s; (void)f; return (NULL); }
LT_WEAK_STUB void	ft_striteri(char *s, void (*f)(unsigned int, char *)) { (void)s; (void)f; }
LT_WEAK_STUB void	ft_putchar_fd(char c, int fd) { (void)c; (void)fd; }
LT_WEAK_STUB void	ft_putstr_fd(char *s, int fd) { (void)s; (void)fd; }
LT_WEAK_STUB void	ft_putendl_fd(char *s, int fd) { (void)s; (void)fd; }
LT_WEAK_STUB void	ft_putnbr_fd(int n, int fd) { (void)n; (void)fd; }
LT_WEAK_STUB t_list	*ft_lstnew(void *content) { (void)content; return (NULL); }
LT_WEAK_STUB void	ft_lstadd_front(t_list **lst, t_list *new_node) { (void)lst; (void)new_node; }
LT_WEAK_STUB unsigned int	ft_lstsize(t_list *lst) { (void)lst; return (0); }
LT_WEAK_STUB t_list	*ft_lstlast(t_list *lst) { (void)lst; return (NULL); }
LT_WEAK_STUB void	ft_lstadd_back(t_list **lst, t_list *new_node) { (void)lst; (void)new_node; }
LT_WEAK_STUB void	ft_lstdelone(t_list *lst, void (*del)(void *)) { (void)lst; (void)del; }
LT_WEAK_STUB void	ft_lstclear(t_list **lst, void (*del)(void *)) { (void)lst; (void)del; }
LT_WEAK_STUB void	ft_lstiter(t_list *lst, void (*f)(void *)) { (void)lst; (void)f; }
LT_WEAK_STUB t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) { (void)lst; (void)f; (void)del; return (NULL); }

typedef enum e_lt_result
{
	LT_PASS = 0,
	LT_FAIL = 1,
	LT_MISSING = 2,
	LT_SKIP = 3
}	t_lt_result;

typedef t_lt_result	(*t_lt_test_fn)(char *message, size_t size);

typedef struct s_lt_test
{
	const char		*id;
	const char		*function;
	const char		*group;
	const char		*kind;
	const char		*description;
	t_lt_test_fn	fn;
}	t_lt_test;

static int	lt_has_symbol(const char *name)
{
	const char	*symbols;
	size_t		name_len;
	const char	*cursor;

	symbols = getenv("LT_AVAILABLE_SYMBOLS");
	if (!symbols)
		return (1);
	if (!symbols[0])
		return (0);
	name_len = strlen(name);
	cursor = symbols;
	while (*cursor)
	{
		while (*cursor == ';')
			cursor++;
		if (strncmp(cursor, name, name_len) == 0
			&& (cursor[name_len] == ';' || cursor[name_len] == '\0'))
			return (1);
		while (*cursor && *cursor != ';')
			cursor++;
	}
	return (0);
}

#define LT_CHECK(expr, msg, ...) \
	do { \
		if (!(expr)) { \
			snprintf(message, size, msg, ##__VA_ARGS__); \
			return (LT_FAIL); \
		} \
	} while (0)

#define LT_REQUIRE(fn) \
	do { \
		if (!lt_has_symbol(#fn)) { \
			snprintf(message, size, "%s is missing from libft.a", #fn); \
			return (LT_MISSING); \
		} \
	} while (0)

#ifndef LT_DISABLE_ALLOC_WRAP
static void		*(*g_real_malloc)(size_t);
static void		(*g_real_free)(void *);
static void		*(*g_real_calloc)(size_t, size_t);
static void		*(*g_real_realloc)(void *, size_t);
static int		g_resolving_allocators;
static long		g_fail_after = -1;
static int		g_track_allocations;
static void		*g_tracked_ptrs[32768];
static size_t	g_tracked_count;
static unsigned char	g_bootstrap_heap[65536];
static size_t			g_bootstrap_used;

static int	lt_is_bootstrap_ptr(void *ptr)
{
	return ((unsigned char *)ptr >= g_bootstrap_heap
		&& (unsigned char *)ptr < g_bootstrap_heap + sizeof(g_bootstrap_heap));
}

static void	*lt_bootstrap_alloc(size_t size)
{
	size_t	aligned;
	void	*ptr;

	aligned = (size + 15) & ~(size_t)15;
	if (g_bootstrap_used + aligned > sizeof(g_bootstrap_heap))
		_exit(111);
	ptr = g_bootstrap_heap + g_bootstrap_used;
	g_bootstrap_used += aligned;
	return (ptr);
}

static void	lt_resolve_allocators(void)
{
	if (g_real_malloc)
		return ;
	if (g_resolving_allocators)
		return ;
	g_resolving_allocators = 1;
	g_real_malloc = dlsym(RTLD_NEXT, "malloc");
	g_real_free = dlsym(RTLD_NEXT, "free");
	g_real_calloc = dlsym(RTLD_NEXT, "calloc");
	g_real_realloc = dlsym(RTLD_NEXT, "realloc");
	g_resolving_allocators = 0;
	if (!g_real_malloc || !g_real_free || !g_real_calloc || !g_real_realloc)
		_exit(112);
}

static int	lt_should_fail_alloc(void)
{
	if (g_fail_after < 0)
		return (0);
	if (g_fail_after == 0)
		return (1);
	g_fail_after--;
	return (0);
}

static void	lt_track_ptr(void *ptr)
{
	if (!ptr || !g_track_allocations)
		return ;
	if (g_tracked_count < sizeof(g_tracked_ptrs) / sizeof(g_tracked_ptrs[0]))
		g_tracked_ptrs[g_tracked_count++] = ptr;
}

static void	lt_untrack_ptr(void *ptr)
{
	size_t	index;

	if (!ptr || !g_track_allocations)
		return ;
	index = 0;
	while (index < g_tracked_count)
	{
		if (g_tracked_ptrs[index] == ptr)
		{
			g_tracked_ptrs[index] = g_tracked_ptrs[g_tracked_count - 1];
			g_tracked_count--;
			return ;
		}
		index++;
	}
}

void	*malloc(size_t size)
{
	void	*ptr;

	if (!g_real_malloc)
	{
		if (g_resolving_allocators)
			return (lt_bootstrap_alloc(size));
		lt_resolve_allocators();
	}
	if (lt_should_fail_alloc())
		return (NULL);
	ptr = g_real_malloc(size);
	lt_track_ptr(ptr);
	return (ptr);
}

void	free(void *ptr)
{
	if (!ptr)
		return ;
	if (!g_real_free)
	{
		if (lt_is_bootstrap_ptr(ptr))
			return ;
		lt_resolve_allocators();
	}
	if (lt_is_bootstrap_ptr(ptr))
		return ;
	lt_untrack_ptr(ptr);
	g_real_free(ptr);
}

void	*calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (!g_real_calloc)
	{
		if (g_resolving_allocators)
		{
			ptr = lt_bootstrap_alloc(nmemb * size);
			memset(ptr, 0, nmemb * size);
			return (ptr);
		}
		lt_resolve_allocators();
	}
	if (lt_should_fail_alloc())
		return (NULL);
	ptr = g_real_calloc(nmemb, size);
	lt_track_ptr(ptr);
	return (ptr);
}

void	*realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (!g_real_realloc)
		lt_resolve_allocators();
	if (lt_is_bootstrap_ptr(ptr))
	{
		new_ptr = g_real_malloc(size);
		if (new_ptr && size)
			memcpy(new_ptr, ptr, size);
		return (new_ptr);
	}
	if (lt_should_fail_alloc())
		return (NULL);
	lt_untrack_ptr(ptr);
	new_ptr = g_real_realloc(ptr, size);
	lt_track_ptr(new_ptr);
	return (new_ptr);
}

static int	lt_alloc_supported(void)
{
	lt_resolve_allocators();
	return (1);
}

static void	lt_alloc_begin(long fail_after)
{
	lt_resolve_allocators();
	g_fail_after = fail_after;
	g_track_allocations = 1;
	g_tracked_count = 0;
}

static size_t	lt_alloc_end(void)
{
	size_t	outstanding;

	outstanding = g_tracked_count;
	g_fail_after = -1;
	g_track_allocations = 0;
	g_tracked_count = 0;
	return (outstanding);
}
#else
static int	lt_alloc_supported(void)
{
	return (0);
}

static void	lt_alloc_begin(long fail_after)
{
	(void)fail_after;
}

static size_t	lt_alloc_end(void)
{
	return (0);
}
#endif

static size_t	ref_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static size_t	ref_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	src_len;

	src_len = ref_strlen(src);
	if (dstsize == 0)
		return (src_len);
	index = 0;
	while (src[index] && index + 1 < dstsize)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (src_len);
}

static size_t	ref_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	index;

	dst_len = 0;
	src_len = ref_strlen(src);
	while (dst_len < dstsize && dst[dst_len])
		dst_len++;
	if (dst_len == dstsize)
		return (dstsize + src_len);
	index = 0;
	while (src[index] && dst_len + index + 1 < dstsize)
	{
		dst[dst_len + index] = src[index];
		index++;
	}
	dst[dst_len + index] = '\0';
	return (dst_len + src_len);
}

static char	*ref_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	needle;

	if (!little[0])
		return ((char *)big);
	index = 0;
	while (big[index] && index < len)
	{
		needle = 0;
		while (little[needle] && index + needle < len
			&& big[index + needle] == little[needle])
			needle++;
		if (!little[needle])
			return ((char *)(big + index));
		index++;
	}
	return (NULL);
}

static int	same_sign(int left, int right)
{
	if (left == 0 && right == 0)
		return (1);
	if (left < 0 && right < 0)
		return (1);
	if (left > 0 && right > 0)
		return (1);
	return (0);
}

static void	free_split(char **split)
{
	size_t	index;

	if (!split)
		return ;
	index = 0;
	while (split[index])
	{
		free(split[index]);
		index++;
	}
	free(split);
}

static t_lt_result	test_isalpha_ascii(char *message, size_t size)
{
	int	c;
	int	expected;

	LT_REQUIRE(ft_isalpha);
	c = -1;
	while (c <= 255)
	{
		expected = ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
		LT_CHECK(ft_isalpha(c) == expected,
			"ft_isalpha(%d) returned %d, expected %d",
			c, ft_isalpha(c), expected);
		c++;
	}
	return (LT_PASS);
}

static t_lt_result	test_isdigit_ascii(char *message, size_t size)
{
	int	c;
	int	expected;

	LT_REQUIRE(ft_isdigit);
	c = -1;
	while (c <= 255)
	{
		expected = (c >= '0' && c <= '9');
		LT_CHECK(ft_isdigit(c) == expected,
			"ft_isdigit(%d) returned %d, expected %d",
			c, ft_isdigit(c), expected);
		c++;
	}
	return (LT_PASS);
}

static t_lt_result	test_isalnum_ascii(char *message, size_t size)
{
	int	c;
	int	expected;

	LT_REQUIRE(ft_isalnum);
	c = -1;
	while (c <= 255)
	{
		expected = ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
			|| (c >= '0' && c <= '9'));
		LT_CHECK(ft_isalnum(c) == expected,
			"ft_isalnum(%d) returned %d, expected %d",
			c, ft_isalnum(c), expected);
		c++;
	}
	return (LT_PASS);
}

static t_lt_result	test_isascii_range(char *message, size_t size)
{
	int	c;
	int	expected;

	LT_REQUIRE(ft_isascii);
	c = -100;
	while (c <= 300)
	{
		expected = (c >= 0 && c <= 127);
		LT_CHECK(ft_isascii(c) == expected,
			"ft_isascii(%d) returned %d, expected %d",
			c, ft_isascii(c), expected);
		c++;
	}
	return (LT_PASS);
}

static t_lt_result	test_isprint_ascii(char *message, size_t size)
{
	int	c;
	int	expected;

	LT_REQUIRE(ft_isprint);
	c = -1;
	while (c <= 255)
	{
		expected = (c >= 32 && c <= 126);
		LT_CHECK(ft_isprint(c) == expected,
			"ft_isprint(%d) returned %d, expected %d",
			c, ft_isprint(c), expected);
		c++;
	}
	return (LT_PASS);
}

static t_lt_result	test_strlen_cases(char *message, size_t size)
{
	char	*large;
	size_t	index;

	LT_REQUIRE(ft_strlen);
	LT_CHECK(ft_strlen("") == 0, "empty string length mismatch");
	LT_CHECK(ft_strlen("libft") == 5, "basic string length mismatch");
	LT_CHECK(ft_strlen("abc\0hidden") == 3, "embedded NUL length mismatch");
	large = malloc(1024 * 1024 + 1);
	LT_CHECK(large != NULL, "tester allocation failed");
	index = 0;
	while (index < 1024 * 1024)
		large[index++] = 'x';
	large[index] = '\0';
	LT_CHECK(ft_strlen(large) == 1024 * 1024,
		"large string length mismatch");
	free(large);
	return (LT_PASS);
}

static t_lt_result	test_memset_cases(char *message, size_t size)
{
	unsigned char	buffer[16];
	unsigned char	expected[16];
	void			*ret;
	int				values[] = {-42, 0, 'A', 0xff, 0x100, 0x123, 4200, 0x1F600};
	size_t			index;

	LT_REQUIRE(ft_memset);
	index = 0;
	while (index < sizeof(values) / sizeof(values[0]))
	{
		memset(buffer, 0x7a, sizeof(buffer));
		memset(expected, 0x7a, sizeof(expected));
		ret = ft_memset(buffer + 2, values[index], 8);
		memset(expected + 2, (unsigned char)values[index], 8);
		LT_CHECK(ret == buffer + 2,
			"ft_memset did not return the destination for c=%d",
			values[index]);
		LT_CHECK(memcmp(buffer, expected, sizeof(buffer)) == 0,
			"ft_memset wrote wrong byte for c=%d, expected 0x%02x",
			values[index], (unsigned char)values[index]);
		index++;
	}
	ft_memset(buffer, 0xff, 0);
	LT_CHECK(memcmp(buffer, expected, sizeof(buffer)) == 0,
		"ft_memset changed buffer with len 0");
	return (LT_PASS);
}

static t_lt_result	test_bzero_cases(char *message, size_t size)
{
	unsigned char	buffer[12];
	unsigned char	expected[12];

	LT_REQUIRE(ft_bzero);
	memset(buffer, 0xab, sizeof(buffer));
	memset(expected, 0xab, sizeof(expected));
	ft_bzero(buffer + 3, 5);
	memset(expected + 3, 0, 5);
	LT_CHECK(memcmp(buffer, expected, sizeof(buffer)) == 0,
		"ft_bzero wrote unexpected bytes");
	ft_bzero(buffer, 0);
	LT_CHECK(memcmp(buffer, expected, sizeof(buffer)) == 0,
		"ft_bzero changed buffer with len 0");
	return (LT_PASS);
}

static t_lt_result	test_memcpy_cases(char *message, size_t size)
{
	unsigned char	src[10] = {'a', 'b', 0, 'd', 'e', 'f', 'g', 'h', 'i', 0xff};
	unsigned char	dst[10];
	unsigned char	expected[10];
	void			*ret;

	LT_REQUIRE(ft_memcpy);
	memset(dst, 0xcc, sizeof(dst));
	memset(expected, 0xcc, sizeof(expected));
	ret = ft_memcpy(dst + 1, src, 7);
	memcpy(expected + 1, src, 7);
	LT_CHECK(ret == dst + 1, "ft_memcpy did not return the destination");
	LT_CHECK(memcmp(dst, expected, sizeof(dst)) == 0,
		"ft_memcpy copied unexpected bytes");
	ft_memcpy(dst, src, 0);
	LT_CHECK(memcmp(dst, expected, sizeof(dst)) == 0,
		"ft_memcpy changed buffer with len 0");
	return (LT_PASS);
}

static t_lt_result	test_memmove_overlap(char *message, size_t size)
{
	unsigned char	left[64];
	unsigned char	right[64];
	size_t			index;

	LT_REQUIRE(ft_memmove);
	index = 0;
	while (index < sizeof(left))
	{
		left[index] = (unsigned char)index;
		right[index] = (unsigned char)index;
		index++;
	}
	ft_memmove(left + 7, left, 31);
	memmove(right + 7, right, 31);
	LT_CHECK(memcmp(left, right, sizeof(left)) == 0,
		"forward overlap result differs from memmove");
	index = 0;
	while (index < sizeof(left))
	{
		left[index] = (unsigned char)(255 - index);
		right[index] = (unsigned char)(255 - index);
		index++;
	}
	ft_memmove(left, left + 5, 37);
	memmove(right, right + 5, 37);
	LT_CHECK(memcmp(left, right, sizeof(left)) == 0,
		"backward overlap result differs from memmove");
	LT_CHECK(ft_memmove(left, right, 0) == left,
		"ft_memmove did not return dst for len 0");
	return (LT_PASS);
}

static t_lt_result	test_strlcpy_cases(char *message, size_t size)
{
	char	dst[16];
	char	ref[16];
	size_t	ret;
	size_t	expected_ret;

	LT_REQUIRE(ft_strlcpy);
	memset(dst, 'X', sizeof(dst));
	memset(ref, 'X', sizeof(ref));
	ret = ft_strlcpy(dst, "abcdef", sizeof(dst));
	expected_ret = ref_strlcpy(ref, "abcdef", sizeof(ref));
	LT_CHECK(ret == expected_ret && memcmp(dst, ref, sizeof(dst)) == 0,
		"ft_strlcpy full copy mismatch");
	memset(dst, 'X', sizeof(dst));
	memset(ref, 'X', sizeof(ref));
	ret = ft_strlcpy(dst, "abcdef", 4);
	expected_ret = ref_strlcpy(ref, "abcdef", 4);
	LT_CHECK(ret == expected_ret && memcmp(dst, ref, sizeof(dst)) == 0,
		"ft_strlcpy truncated copy mismatch");
	memset(dst, 'X', sizeof(dst));
	ret = ft_strlcpy(dst, "abc", 0);
	LT_CHECK(ret == 3 && dst[0] == 'X',
		"ft_strlcpy size 0 return/write mismatch");
	return (LT_PASS);
}

static t_lt_result	test_strlcat_cases(char *message, size_t size)
{
	char	dst[20];
	char	ref[20];
	size_t	ret;
	size_t	expected_ret;

	LT_REQUIRE(ft_strlcat);
	strcpy(dst, "abc");
	strcpy(ref, "abc");
	ret = ft_strlcat(dst, "def", sizeof(dst));
	expected_ret = ref_strlcat(ref, "def", sizeof(ref));
	LT_CHECK(ret == expected_ret && strcmp(dst, ref) == 0,
		"ft_strlcat append mismatch");
	memset(dst, 0, sizeof(dst));
	memset(ref, 0, sizeof(ref));
	strcpy(dst, "abc");
	strcpy(ref, "abc");
	ret = ft_strlcat(dst, "defgh", 6);
	expected_ret = ref_strlcat(ref, "defgh", 6);
	LT_CHECK(ret == expected_ret && memcmp(dst, ref, sizeof(dst)) == 0,
		"ft_strlcat truncation mismatch");
	strcpy(dst, "abcdef");
	ret = ft_strlcat(dst, "ZZ", 3);
	LT_CHECK(ret == 5 && strcmp(dst, "abcdef") == 0,
		"ft_strlcat dstsize smaller than dst length mismatch");
	return (LT_PASS);
}

static t_lt_result	test_toupper_cases(char *message, size_t size)
{
	int	c;
	int	expected;

	LT_REQUIRE(ft_toupper);
	c = -1;
	while (c <= 255)
	{
		expected = c;
		if (c >= 'a' && c <= 'z')
			expected = c - 32;
		LT_CHECK(ft_toupper(c) == expected,
			"ft_toupper(%d) returned %d, expected %d",
			c, ft_toupper(c), expected);
		c++;
	}
	return (LT_PASS);
}

static t_lt_result	test_tolower_cases(char *message, size_t size)
{
	int	c;
	int	expected;

	LT_REQUIRE(ft_tolower);
	c = -1;
	while (c <= 255)
	{
		expected = c;
		if (c >= 'A' && c <= 'Z')
			expected = c + 32;
		LT_CHECK(ft_tolower(c) == expected,
			"ft_tolower(%d) returned %d, expected %d",
			c, ft_tolower(c), expected);
		c++;
	}
	return (LT_PASS);
}

static t_lt_result	test_strchr_cases(char *message, size_t size)
{
	const char		*s;
	unsigned char	raw[4];

	LT_REQUIRE(ft_strchr);
	s = "abacad";
	LT_CHECK(ft_strchr(s, 'a') == s, "ft_strchr first occurrence mismatch");
	LT_CHECK(ft_strchr(s, 'd') == s + 5, "ft_strchr last char mismatch");
	LT_CHECK(ft_strchr(s, '\0') == s + 6, "ft_strchr NUL mismatch");
	LT_CHECK(ft_strchr(s, 'z') == NULL, "ft_strchr missing char mismatch");
	raw[0] = 'x';
	raw[1] = 0xff;
	raw[2] = 'y';
	raw[3] = 0;
	LT_CHECK(ft_strchr((char *)raw, 0xff) == (char *)raw + 1,
		"ft_strchr unsigned char mismatch");
	return (LT_PASS);
}

static t_lt_result	test_strrchr_cases(char *message, size_t size)
{
	const char	*s;

	LT_REQUIRE(ft_strrchr);
	s = "abacad";
	LT_CHECK(ft_strrchr(s, 'a') == s + 4,
		"ft_strrchr last occurrence mismatch");
	LT_CHECK(ft_strrchr(s, 'd') == s + 5, "ft_strrchr last char mismatch");
	LT_CHECK(ft_strrchr(s, '\0') == s + 6, "ft_strrchr NUL mismatch");
	LT_CHECK(ft_strrchr(s, 'z') == NULL, "ft_strrchr missing char mismatch");
	return (LT_PASS);
}

static t_lt_result	test_strncmp_cases(char *message, size_t size)
{
	LT_REQUIRE(ft_strncmp);
	LT_CHECK(ft_strncmp("abc", "abc", 3) == 0, "equal strings mismatch");
	LT_CHECK(ft_strncmp("abc", "xyz", 0) == 0, "n=0 mismatch");
	LT_CHECK(same_sign(ft_strncmp("abc", "abd", 3), strncmp("abc", "abd", 3)),
		"negative comparison sign mismatch");
	LT_CHECK(same_sign(ft_strncmp("abz", "abc", 3), strncmp("abz", "abc", 3)),
		"positive comparison sign mismatch");
	LT_CHECK(same_sign(ft_strncmp("a\200", "a\1", 2), strncmp("a\200", "a\1", 2)),
		"unsigned char comparison sign mismatch");
	return (LT_PASS);
}

static t_lt_result	test_memchr_cases(char *message, size_t size)
{
	unsigned char	buffer[8] = {'a', 0, 'b', 0xff, 'c', 'b', 0, 'd'};

	LT_REQUIRE(ft_memchr);
	LT_CHECK(ft_memchr(buffer, 0, sizeof(buffer)) == buffer + 1,
		"ft_memchr NUL mismatch");
	LT_CHECK(ft_memchr(buffer, 0xff, sizeof(buffer)) == buffer + 3,
		"ft_memchr high byte mismatch");
	LT_CHECK(ft_memchr(buffer, 'b', 4) == buffer + 2,
		"ft_memchr bounded search mismatch");
	LT_CHECK(ft_memchr(buffer, 'z', sizeof(buffer)) == NULL,
		"ft_memchr missing byte mismatch");
	LT_CHECK(ft_memchr(buffer, 'a', 0) == NULL,
		"ft_memchr n=0 mismatch");
	return (LT_PASS);
}

static t_lt_result	test_memcmp_cases(char *message, size_t size)
{
	unsigned char	a[4] = {0, 1, 0x80, 0xff};
	unsigned char	b[4] = {0, 1, 0x7f, 0xff};

	LT_REQUIRE(ft_memcmp);
	LT_CHECK(ft_memcmp(a, a, sizeof(a)) == 0, "same buffer mismatch");
	LT_CHECK(ft_memcmp(a, b, 2) == 0, "prefix equality mismatch");
	LT_CHECK(ft_memcmp(a, b, 0) == 0, "n=0 mismatch");
	LT_CHECK(same_sign(ft_memcmp(a, b, sizeof(a)), memcmp(a, b, sizeof(a))),
		"unsigned byte comparison sign mismatch");
	LT_CHECK(same_sign(ft_memcmp(b, a, sizeof(a)), memcmp(b, a, sizeof(a))),
		"reverse comparison sign mismatch");
	return (LT_PASS);
}

static t_lt_result	test_strnstr_cases(char *message, size_t size)
{
	const char	*haystack;
	const char	*needles[] = {"", "quick", "brown", "own", "dog", "cat"};
	size_t		lens[] = {0, 1, 5, 9, 15, 43};
	size_t		i;
	size_t		j;

	LT_REQUIRE(ft_strnstr);
	haystack = "the quick brown fox jumps over the lazy dog";
	i = 0;
	while (i < sizeof(needles) / sizeof(needles[0]))
	{
		j = 0;
		while (j < sizeof(lens) / sizeof(lens[0]))
		{
			LT_CHECK(ft_strnstr(haystack, needles[i], lens[j])
				== ref_strnstr(haystack, needles[i], lens[j]),
				"ft_strnstr mismatch for needle '%s' len %zu",
				needles[i], lens[j]);
			j++;
		}
		i++;
	}
	return (LT_PASS);
}

static t_lt_result	test_atoi_cases(char *message, size_t size)
{
	struct s_case
	{
		const char	*input;
		int			expected;
	};
	struct s_case	cases[] = {
		{"0", 0}, {"42", 42}, {"   -42", -42}, {"\t\n\v\f\r +214", 214},
		{"2147483647", INT_MAX}, {"-2147483648", INT_MIN},
		{"words", 0}, {"--12", 0}, {"+-12", 0}, {"12words34", 12}
	};
	size_t			index;

	LT_REQUIRE(ft_atoi);
	index = 0;
	while (index < sizeof(cases) / sizeof(cases[0]))
	{
		LT_CHECK(ft_atoi(cases[index].input) == cases[index].expected,
			"ft_atoi('%s') returned %d, expected %d",
			cases[index].input, ft_atoi(cases[index].input),
			cases[index].expected);
		index++;
	}
	return (LT_PASS);
}

static t_lt_result	test_calloc_cases(char *message, size_t size)
{
	unsigned char	*ptr;
	size_t			index;

	LT_REQUIRE(ft_calloc);
	ptr = ft_calloc(32, sizeof(unsigned char));
	LT_CHECK(ptr != NULL, "ft_calloc returned NULL for small allocation");
	index = 0;
	while (index < 32)
	{
		LT_CHECK(ptr[index] == 0, "ft_calloc did not zero byte %zu", index);
		index++;
	}
	free(ptr);
	ptr = ft_calloc(0, 16);
	LT_CHECK(ptr != NULL, "ft_calloc(0, size) must return a freeable pointer");
	free(ptr);
	ptr = ft_calloc(16, 0);
	LT_CHECK(ptr != NULL, "ft_calloc(nmemb, 0) must return a freeable pointer");
	free(ptr);
	ptr = ft_calloc(((size_t)-1 / 2) + 1, 2);
	LT_CHECK(ptr == NULL, "ft_calloc did not reject size_t overflow");
	return (LT_PASS);
}

static t_lt_result	test_strdup_cases(char *message, size_t size)
{
	char	*copy;
	char	empty[] = "";

	LT_REQUIRE(ft_strdup);
	copy = ft_strdup("hello");
	LT_CHECK(copy != NULL, "ft_strdup returned NULL for basic string");
	LT_CHECK(strcmp(copy, "hello") == 0, "ft_strdup content mismatch");
	copy[0] = 'H';
	LT_CHECK(strcmp(copy, "Hello") == 0, "ft_strdup result is not writable");
	free(copy);
	copy = ft_strdup(empty);
	LT_CHECK(copy != NULL && strcmp(copy, "") == 0,
		"ft_strdup empty string mismatch");
	free(copy);
	return (LT_PASS);
}

static t_lt_result	test_substr_cases(char *message, size_t size)
{
	char	*result;

	LT_REQUIRE(ft_substr);
	result = ft_substr("hello world", 6, 5);
	LT_CHECK(result != NULL && strcmp(result, "world") == 0,
		"ft_substr normal case mismatch");
	free(result);
	result = ft_substr("short", 20, 10);
	LT_CHECK(result != NULL && strcmp(result, "") == 0,
		"ft_substr start beyond length must return empty string");
	free(result);
	result = ft_substr("abcdef", 2, 100);
	LT_CHECK(result != NULL && strcmp(result, "cdef") == 0,
		"ft_substr long len mismatch");
	free(result);
	result = ft_substr("abcdef", 2, 0);
	LT_CHECK(result != NULL && strcmp(result, "") == 0,
		"ft_substr len 0 mismatch");
	free(result);
	return (LT_PASS);
}

static t_lt_result	test_strjoin_cases(char *message, size_t size)
{
	char	*result;

	LT_REQUIRE(ft_strjoin);
	result = ft_strjoin("hello", " world");
	LT_CHECK(result != NULL && strcmp(result, "hello world") == 0,
		"ft_strjoin basic mismatch");
	free(result);
	result = ft_strjoin("", "tail");
	LT_CHECK(result != NULL && strcmp(result, "tail") == 0,
		"ft_strjoin empty prefix mismatch");
	free(result);
	result = ft_strjoin("head", "");
	LT_CHECK(result != NULL && strcmp(result, "head") == 0,
		"ft_strjoin empty suffix mismatch");
	free(result);
	return (LT_PASS);
}

static t_lt_result	test_strtrim_cases(char *message, size_t size)
{
	char	*result;

	LT_REQUIRE(ft_strtrim);
	result = ft_strtrim(" \t\nhello \n", " \n\t");
	LT_CHECK(result != NULL && strcmp(result, "hello") == 0,
		"ft_strtrim basic mismatch");
	free(result);
	result = ft_strtrim("xxxx", "x");
	LT_CHECK(result != NULL && strcmp(result, "") == 0,
		"ft_strtrim all-trimmed mismatch");
	free(result);
	result = ft_strtrim("abc", "");
	LT_CHECK(result != NULL && strcmp(result, "abc") == 0,
		"ft_strtrim empty set mismatch");
	free(result);
	result = ft_strtrim("", "abc");
	LT_CHECK(result != NULL && strcmp(result, "") == 0,
		"ft_strtrim empty string mismatch");
	free(result);
	return (LT_PASS);
}

static t_lt_result	test_split_cases(char *message, size_t size)
{
	char	**result;

	LT_REQUIRE(ft_split);
	result = ft_split(",,alpha,beta,,gamma,", ',');
	LT_CHECK(result != NULL, "ft_split returned NULL for basic case");
	LT_CHECK(result[0] && strcmp(result[0], "alpha") == 0,
		"ft_split word 0 mismatch");
	LT_CHECK(result[1] && strcmp(result[1], "beta") == 0,
		"ft_split word 1 mismatch");
	LT_CHECK(result[2] && strcmp(result[2], "gamma") == 0,
		"ft_split word 2 mismatch");
	LT_CHECK(result[3] == NULL, "ft_split array is not NULL terminated");
	free_split(result);
	result = ft_split(";;;;", ';');
	LT_CHECK(result != NULL && result[0] == NULL,
		"ft_split delimiters-only mismatch");
	free_split(result);
	result = ft_split("", ',');
	LT_CHECK(result != NULL && result[0] == NULL,
		"ft_split empty string mismatch");
	free_split(result);
	result = ft_split("abc", '\0');
	LT_CHECK(result != NULL && result[0] && strcmp(result[0], "abc") == 0
		&& result[1] == NULL, "ft_split NUL delimiter mismatch");
	free_split(result);
	return (LT_PASS);
}

static t_lt_result	test_itoa_cases(char *message, size_t size)
{
	struct s_case
	{
		int			input;
		const char	*expected;
	};
	struct s_case	cases[] = {
		{0, "0"}, {42, "42"}, {-42, "-42"},
		{INT_MAX, "2147483647"}, {INT_MIN, "-2147483648"}
	};
	char			*result;
	size_t			index;

	LT_REQUIRE(ft_itoa);
	index = 0;
	while (index < sizeof(cases) / sizeof(cases[0]))
	{
		result = ft_itoa(cases[index].input);
		LT_CHECK(result != NULL, "ft_itoa returned NULL for %d",
			cases[index].input);
		LT_CHECK(strcmp(result, cases[index].expected) == 0,
			"ft_itoa(%d) returned '%s', expected '%s'",
			cases[index].input, result, cases[index].expected);
		free(result);
		index++;
	}
	return (LT_PASS);
}

static char	mapi_shift(unsigned int index, char c)
{
	return ((char)(c + (index % 3)));
}

static t_lt_result	test_strmapi_cases(char *message, size_t size)
{
	char	*result;

	LT_REQUIRE(ft_strmapi);
	result = ft_strmapi("aaaaaa", mapi_shift);
	LT_CHECK(result != NULL, "ft_strmapi returned NULL");
	LT_CHECK(strcmp(result, "abcabc") == 0,
		"ft_strmapi transformed string mismatch: '%s'", result);
	free(result);
	result = ft_strmapi("", mapi_shift);
	LT_CHECK(result != NULL && strcmp(result, "") == 0,
		"ft_strmapi empty string mismatch");
	free(result);
	return (LT_PASS);
}

static void	iteri_shift(unsigned int index, char *c)
{
	*c = (char)(*c + (index % 2));
}

static t_lt_result	test_striteri_cases(char *message, size_t size)
{
	char	buffer[8];

	LT_REQUIRE(ft_striteri);
	strcpy(buffer, "aaaaaa");
	ft_striteri(buffer, iteri_shift);
	LT_CHECK(strcmp(buffer, "ababab") == 0,
		"ft_striteri transformed string mismatch: '%s'", buffer);
	return (LT_PASS);
}

static int	read_pipe_output(int read_fd, char *buffer, size_t capacity)
{
	ssize_t	count;
	size_t	used;

	used = 0;
	while (used + 1 < capacity)
	{
		count = read(read_fd, buffer + used, capacity - used - 1);
		if (count < 0 && errno == EINTR)
			continue ;
		if (count <= 0)
			break ;
		used += (size_t)count;
	}
	buffer[used] = '\0';
	return ((int)used);
}

static t_lt_result	test_putchar_fd_cases(char *message, size_t size)
{
	int		fds[2];
	char	buffer[16];

	LT_REQUIRE(ft_putchar_fd);
	LT_CHECK(pipe(fds) == 0, "pipe failed");
	ft_putchar_fd('A', fds[1]);
	ft_putchar_fd('\n', fds[1]);
	close(fds[1]);
	read_pipe_output(fds[0], buffer, sizeof(buffer));
	close(fds[0]);
	LT_CHECK(strcmp(buffer, "A\n") == 0,
		"ft_putchar_fd output mismatch: '%s'", buffer);
	ft_putchar_fd('x', -1);
	return (LT_PASS);
}

static t_lt_result	test_putstr_fd_cases(char *message, size_t size)
{
	int		fds[2];
	char	buffer[64];

	LT_REQUIRE(ft_putstr_fd);
	LT_CHECK(pipe(fds) == 0, "pipe failed");
	ft_putstr_fd("hello", fds[1]);
	ft_putstr_fd("", fds[1]);
	close(fds[1]);
	read_pipe_output(fds[0], buffer, sizeof(buffer));
	close(fds[0]);
	LT_CHECK(strcmp(buffer, "hello") == 0,
		"ft_putstr_fd output mismatch: '%s'", buffer);
	ft_putstr_fd("ignored", -1);
	return (LT_PASS);
}

static t_lt_result	test_putendl_fd_cases(char *message, size_t size)
{
	int		fds[2];
	char	buffer[64];

	LT_REQUIRE(ft_putendl_fd);
	LT_CHECK(pipe(fds) == 0, "pipe failed");
	ft_putendl_fd("hello", fds[1]);
	ft_putendl_fd("", fds[1]);
	close(fds[1]);
	read_pipe_output(fds[0], buffer, sizeof(buffer));
	close(fds[0]);
	LT_CHECK(strcmp(buffer, "hello\n\n") == 0,
		"ft_putendl_fd output mismatch: '%s'", buffer);
	ft_putendl_fd("ignored", -1);
	return (LT_PASS);
}

static t_lt_result	test_putnbr_fd_cases(char *message, size_t size)
{
	int		fds[2];
	char	buffer[128];

	LT_REQUIRE(ft_putnbr_fd);
	LT_CHECK(pipe(fds) == 0, "pipe failed");
	ft_putnbr_fd(0, fds[1]);
	ft_putnbr_fd(-42, fds[1]);
	ft_putnbr_fd(INT_MIN, fds[1]);
	close(fds[1]);
	read_pipe_output(fds[0], buffer, sizeof(buffer));
	close(fds[0]);
	LT_CHECK(strcmp(buffer, "0-42-2147483648") == 0,
		"ft_putnbr_fd output mismatch: '%s'", buffer);
	ft_putnbr_fd(123, -1);
	return (LT_PASS);
}

static int	g_delete_count;
static int	g_iter_sum;

static void	del_count_free(void *ptr)
{
	g_delete_count++;
	free(ptr);
}

static void	iter_add_int(void *ptr)
{
	g_iter_sum += *(int *)ptr;
}

static void	*map_double_int(void *ptr)
{
	int	*value;

	value = malloc(sizeof(int));
	if (!value)
		return (NULL);
	*value = *(int *)ptr * 2;
	return (value);
}

static t_lt_result	test_lstnew_cases(char *message, size_t size)
{
	int		value;
	t_list	*node;

	LT_REQUIRE(ft_lstnew);
	value = 42;
	node = ft_lstnew(&value);
	LT_CHECK(node != NULL, "ft_lstnew returned NULL");
	LT_CHECK(node->content == &value, "ft_lstnew content mismatch");
	LT_CHECK(node->next == NULL, "ft_lstnew next is not NULL");
	free(node);
	node = ft_lstnew(NULL);
	LT_CHECK(node != NULL && node->content == NULL && node->next == NULL,
		"ft_lstnew NULL content mismatch");
	free(node);
	return (LT_PASS);
}

static t_lt_result	test_lstadd_front_cases(char *message, size_t size)
{
	t_list	a;
	t_list	b;
	t_list	*head;

	LT_REQUIRE(ft_lstadd_front);
	a.content = (void *)1;
	a.next = NULL;
	b.content = (void *)2;
	b.next = NULL;
	head = &a;
	ft_lstadd_front(&head, &b);
	LT_CHECK(head == &b && b.next == &a && a.next == NULL,
		"ft_lstadd_front did not link new head correctly");
	head = NULL;
	b.next = NULL;
	ft_lstadd_front(&head, &b);
	LT_CHECK(head == &b && b.next == NULL,
		"ft_lstadd_front empty list mismatch");
	return (LT_PASS);
}

static t_lt_result	test_lstsize_cases(char *message, size_t size)
{
	t_list	nodes[3];

	LT_REQUIRE(ft_lstsize);
	nodes[0].next = &nodes[1];
	nodes[1].next = &nodes[2];
	nodes[2].next = NULL;
	LT_CHECK(ft_lstsize(NULL) == 0, "ft_lstsize(NULL) must be 0");
	LT_CHECK(ft_lstsize(nodes) == 3, "ft_lstsize three-node mismatch");
	return (LT_PASS);
}

static t_lt_result	test_lstlast_cases(char *message, size_t size)
{
	t_list	nodes[3];

	LT_REQUIRE(ft_lstlast);
	nodes[0].next = &nodes[1];
	nodes[1].next = &nodes[2];
	nodes[2].next = NULL;
	LT_CHECK(ft_lstlast(NULL) == NULL, "ft_lstlast(NULL) must be NULL");
	LT_CHECK(ft_lstlast(nodes) == &nodes[2], "ft_lstlast mismatch");
	return (LT_PASS);
}

static t_lt_result	test_lstadd_back_cases(char *message, size_t size)
{
	t_list	a;
	t_list	b;
	t_list	*head;

	LT_REQUIRE(ft_lstadd_back);
	a.next = NULL;
	b.next = NULL;
	head = &a;
	ft_lstadd_back(&head, &b);
	LT_CHECK(head == &a && a.next == &b && b.next == NULL,
		"ft_lstadd_back did not append correctly");
	head = NULL;
	a.next = NULL;
	ft_lstadd_back(&head, &a);
	LT_CHECK(head == &a && a.next == NULL,
		"ft_lstadd_back empty list mismatch");
	return (LT_PASS);
}

static t_lt_result	test_lstdelone_cases(char *message, size_t size)
{
	t_list	*node;
	int		*content;

	LT_REQUIRE(ft_lstdelone);
	node = malloc(sizeof(t_list));
	content = malloc(sizeof(int));
	LT_CHECK(node != NULL && content != NULL, "tester allocation failed");
	*content = 42;
	node->content = content;
	node->next = (t_list *)0x1234;
	g_delete_count = 0;
	ft_lstdelone(node, del_count_free);
	LT_CHECK(g_delete_count == 1,
		"ft_lstdelone did not call del exactly once");
	return (LT_PASS);
}

static t_lt_result	test_lstclear_cases(char *message, size_t size)
{
	t_list	*head;
	t_list	*second;
	t_list	*third;

	LT_REQUIRE(ft_lstclear);
	head = malloc(sizeof(t_list));
	second = malloc(sizeof(t_list));
	third = malloc(sizeof(t_list));
	LT_CHECK(head != NULL && second != NULL && third != NULL,
		"tester node allocation failed");
	head->content = malloc(sizeof(int));
	second->content = malloc(sizeof(int));
	third->content = malloc(sizeof(int));
	LT_CHECK(head->content && second->content && third->content,
		"tester content allocation failed");
	head->next = second;
	second->next = third;
	third->next = NULL;
	g_delete_count = 0;
	ft_lstclear(&head, del_count_free);
	LT_CHECK(head == NULL, "ft_lstclear did not set list pointer to NULL");
	LT_CHECK(g_delete_count == 3,
		"ft_lstclear called del %d times, expected 3", g_delete_count);
	return (LT_PASS);
}

static t_lt_result	test_lstiter_cases(char *message, size_t size)
{
	t_list	nodes[3];
	int		values[3] = {1, 2, 3};

	LT_REQUIRE(ft_lstiter);
	nodes[0].content = &values[0];
	nodes[1].content = &values[1];
	nodes[2].content = &values[2];
	nodes[0].next = &nodes[1];
	nodes[1].next = &nodes[2];
	nodes[2].next = NULL;
	g_iter_sum = 0;
	ft_lstiter(nodes, iter_add_int);
	LT_CHECK(g_iter_sum == 6, "ft_lstiter sum mismatch: %d", g_iter_sum);
	return (LT_PASS);
}

static void	free_mapped_list(t_list *list)
{
	t_list	*next;

	while (list)
	{
		next = list->next;
		free(list->content);
		free(list);
		list = next;
	}
}

static t_lt_result	test_lstmap_cases(char *message, size_t size)
{
	t_list	nodes[3];
	t_list	*mapped;
	int		values[3] = {1, 2, 3};
	int		expected;

	LT_REQUIRE(ft_lstmap);
	nodes[0].content = &values[0];
	nodes[1].content = &values[1];
	nodes[2].content = &values[2];
	nodes[0].next = &nodes[1];
	nodes[1].next = &nodes[2];
	nodes[2].next = NULL;
	mapped = ft_lstmap(nodes, map_double_int, del_count_free);
	LT_CHECK(mapped != NULL, "ft_lstmap returned NULL");
	expected = 2;
	LT_CHECK(*(int *)mapped->content == expected, "ft_lstmap first value mismatch");
	LT_CHECK(mapped->next && *(int *)mapped->next->content == 4,
		"ft_lstmap second value mismatch");
	LT_CHECK(mapped->next->next && *(int *)mapped->next->next->content == 6,
		"ft_lstmap third value mismatch");
	LT_CHECK(mapped->next->next->next == NULL,
		"ft_lstmap result is not NULL terminated");
	free_mapped_list(mapped);
	return (LT_PASS);
}

static t_lt_result	test_allocfail_calloc(char *message, size_t size)
{
	void	*ptr;
	size_t	outstanding;

	LT_REQUIRE(ft_calloc);
	if (!lt_alloc_supported())
		return (LT_SKIP);
	lt_alloc_begin(0);
	ptr = ft_calloc(8, 8);
	outstanding = lt_alloc_end();
	LT_CHECK(ptr == NULL, "ft_calloc did not return NULL when allocation failed");
	LT_CHECK(outstanding == 0, "allocation tracker found %zu leaked pointers",
		outstanding);
	return (LT_PASS);
}

static t_lt_result	test_allocfail_strdup(char *message, size_t size)
{
	char	*ptr;
	size_t	outstanding;

	LT_REQUIRE(ft_strdup);
	if (!lt_alloc_supported())
		return (LT_SKIP);
	lt_alloc_begin(0);
	ptr = ft_strdup("abc");
	outstanding = lt_alloc_end();
	LT_CHECK(ptr == NULL, "ft_strdup did not return NULL when allocation failed");
	LT_CHECK(outstanding == 0, "allocation tracker found %zu leaked pointers",
		outstanding);
	return (LT_PASS);
}

static t_lt_result	test_allocfail_substr(char *message, size_t size)
{
	char	*ptr;
	size_t	outstanding;

	LT_REQUIRE(ft_substr);
	if (!lt_alloc_supported())
		return (LT_SKIP);
	lt_alloc_begin(0);
	ptr = ft_substr("abcdef", 1, 3);
	outstanding = lt_alloc_end();
	LT_CHECK(ptr == NULL, "ft_substr did not return NULL when allocation failed");
	LT_CHECK(outstanding == 0, "allocation tracker found %zu leaked pointers",
		outstanding);
	return (LT_PASS);
}

static t_lt_result	test_allocfail_strjoin(char *message, size_t size)
{
	char	*ptr;
	size_t	outstanding;

	LT_REQUIRE(ft_strjoin);
	if (!lt_alloc_supported())
		return (LT_SKIP);
	lt_alloc_begin(0);
	ptr = ft_strjoin("abc", "def");
	outstanding = lt_alloc_end();
	LT_CHECK(ptr == NULL, "ft_strjoin did not return NULL when allocation failed");
	LT_CHECK(outstanding == 0, "allocation tracker found %zu leaked pointers",
		outstanding);
	return (LT_PASS);
}

static t_lt_result	test_allocfail_strtrim(char *message, size_t size)
{
	char	*ptr;
	size_t	outstanding;

	LT_REQUIRE(ft_strtrim);
	if (!lt_alloc_supported())
		return (LT_SKIP);
	lt_alloc_begin(0);
	ptr = ft_strtrim("  abc  ", " ");
	outstanding = lt_alloc_end();
	LT_CHECK(ptr == NULL, "ft_strtrim did not return NULL when allocation failed");
	LT_CHECK(outstanding == 0, "allocation tracker found %zu leaked pointers",
		outstanding);
	return (LT_PASS);
}

static t_lt_result	test_allocfail_split(char *message, size_t size)
{
	char	**ptr;
	size_t	outstanding;

	LT_REQUIRE(ft_split);
	if (!lt_alloc_supported())
		return (LT_SKIP);
	lt_alloc_begin(2);
	ptr = ft_split("aa,bb,cc", ',');
	outstanding = lt_alloc_end();
	LT_CHECK(ptr == NULL, "ft_split did not return NULL after inner allocation failure");
	LT_CHECK(outstanding == 0,
		"ft_split leaked %zu tracked allocations after failure", outstanding);
	return (LT_PASS);
}

static t_lt_result	test_allocfail_itoa(char *message, size_t size)
{
	char	*ptr;
	size_t	outstanding;

	LT_REQUIRE(ft_itoa);
	if (!lt_alloc_supported())
		return (LT_SKIP);
	lt_alloc_begin(0);
	ptr = ft_itoa(INT_MIN);
	outstanding = lt_alloc_end();
	LT_CHECK(ptr == NULL, "ft_itoa did not return NULL when allocation failed");
	LT_CHECK(outstanding == 0, "allocation tracker found %zu leaked pointers",
		outstanding);
	return (LT_PASS);
}

static t_lt_result	test_allocfail_strmapi(char *message, size_t size)
{
	char	*ptr;
	size_t	outstanding;

	LT_REQUIRE(ft_strmapi);
	if (!lt_alloc_supported())
		return (LT_SKIP);
	lt_alloc_begin(0);
	ptr = ft_strmapi("abc", mapi_shift);
	outstanding = lt_alloc_end();
	LT_CHECK(ptr == NULL, "ft_strmapi did not return NULL when allocation failed");
	LT_CHECK(outstanding == 0, "allocation tracker found %zu leaked pointers",
		outstanding);
	return (LT_PASS);
}

static t_lt_result	test_allocfail_lstnew(char *message, size_t size)
{
	t_list	*ptr;
	size_t	outstanding;

	LT_REQUIRE(ft_lstnew);
	if (!lt_alloc_supported())
		return (LT_SKIP);
	lt_alloc_begin(0);
	ptr = ft_lstnew((void *)42);
	outstanding = lt_alloc_end();
	LT_CHECK(ptr == NULL, "ft_lstnew did not return NULL when allocation failed");
	LT_CHECK(outstanding == 0, "allocation tracker found %zu leaked pointers",
		outstanding);
	return (LT_PASS);
}

static t_lt_result	test_probe_memcpy_null_zero(char *message, size_t size)
{
	LT_REQUIRE(ft_memcpy);
	(void)ft_memcpy(NULL, NULL, 0);
	(void)message;
	(void)size;
	return (LT_PASS);
}

static t_lt_result	test_probe_memmove_null_zero(char *message, size_t size)
{
	LT_REQUIRE(ft_memmove);
	(void)ft_memmove(NULL, NULL, 0);
	(void)message;
	(void)size;
	return (LT_PASS);
}

static t_lt_result	test_probe_substr_null(char *message, size_t size)
{
	char	*ptr;

	LT_REQUIRE(ft_substr);
	ptr = ft_substr(NULL, 0, 1);
	LT_CHECK(ptr == NULL, "ft_substr(NULL, ...) returned a non-NULL pointer");
	return (LT_PASS);
}

static t_lt_result	test_probe_strjoin_null(char *message, size_t size)
{
	char	*ptr;

	LT_REQUIRE(ft_strjoin);
	ptr = ft_strjoin(NULL, "x");
	LT_CHECK(ptr == NULL, "ft_strjoin(NULL, ...) returned a non-NULL pointer");
	return (LT_PASS);
}

static t_lt_result	test_probe_split_null(char *message, size_t size)
{
	char	**ptr;

	LT_REQUIRE(ft_split);
	ptr = ft_split(NULL, ',');
	LT_CHECK(ptr == NULL, "ft_split(NULL, ...) returned a non-NULL pointer");
	return (LT_PASS);
}

static t_lt_result	test_probe_striteri_null(char *message, size_t size)
{
	LT_REQUIRE(ft_striteri);
	ft_striteri(NULL, iteri_shift);
	(void)message;
	(void)size;
	return (LT_PASS);
}

static t_lt_test	g_tests[] = {
	{"ft_isalpha.ascii", "ft_isalpha", "mandatory", "required", "ASCII alphabetic classification", test_isalpha_ascii},
	{"ft_isdigit.ascii", "ft_isdigit", "mandatory", "required", "ASCII digit classification", test_isdigit_ascii},
	{"ft_isalnum.ascii", "ft_isalnum", "mandatory", "required", "ASCII alphanumeric classification", test_isalnum_ascii},
	{"ft_isascii.range", "ft_isascii", "mandatory", "required", "full integer ASCII range", test_isascii_range},
	{"ft_isprint.ascii", "ft_isprint", "mandatory", "required", "printable ASCII classification", test_isprint_ascii},
	{"ft_strlen.cases", "ft_strlen", "mandatory", "required", "empty, embedded NUL, and large strings", test_strlen_cases},
	{"ft_memset.cases", "ft_memset", "mandatory", "required", "return value, signed/wide byte conversion, len 0", test_memset_cases},
	{"ft_bzero.cases", "ft_bzero", "mandatory", "required", "range zeroing and len 0", test_bzero_cases},
	{"ft_memcpy.cases", "ft_memcpy", "mandatory", "required", "binary copy and len 0", test_memcpy_cases},
	{"ft_memmove.overlap", "ft_memmove", "mandatory", "required", "forward and backward overlapping regions", test_memmove_overlap},
	{"ft_strlcpy.cases", "ft_strlcpy", "mandatory", "required", "full, truncated, and size 0 copies", test_strlcpy_cases},
	{"ft_strlcat.cases", "ft_strlcat", "mandatory", "required", "append, truncate, and small dstsize", test_strlcat_cases},
	{"ft_toupper.cases", "ft_toupper", "mandatory", "required", "ASCII conversion and untouched bytes", test_toupper_cases},
	{"ft_tolower.cases", "ft_tolower", "mandatory", "required", "ASCII conversion and untouched bytes", test_tolower_cases},
	{"ft_strchr.cases", "ft_strchr", "mandatory", "required", "first match, NUL, miss, high byte", test_strchr_cases},
	{"ft_strrchr.cases", "ft_strrchr", "mandatory", "required", "last match, NUL, and miss", test_strrchr_cases},
	{"ft_strncmp.cases", "ft_strncmp", "mandatory", "required", "sign, n 0, and unsigned comparison", test_strncmp_cases},
	{"ft_memchr.cases", "ft_memchr", "mandatory", "required", "NUL, high byte, bounds, and miss", test_memchr_cases},
	{"ft_memcmp.cases", "ft_memcmp", "mandatory", "required", "equality, n 0, and unsigned sign", test_memcmp_cases},
	{"ft_strnstr.cases", "ft_strnstr", "mandatory", "required", "needle and length boundary cases", test_strnstr_cases},
	{"ft_atoi.cases", "ft_atoi", "mandatory", "required", "spaces, signs, limits, and suffixes", test_atoi_cases},
	{"ft_calloc.cases", "ft_calloc", "mandatory", "required", "zeroing, zero-size rule, and overflow", test_calloc_cases},
	{"ft_strdup.cases", "ft_strdup", "mandatory", "required", "content, empty string, writable copy", test_strdup_cases},
	{"ft_substr.cases", "ft_substr", "mandatory", "required", "normal, out-of-range, long len, zero len", test_substr_cases},
	{"ft_strjoin.cases", "ft_strjoin", "mandatory", "required", "normal and empty-side joins", test_strjoin_cases},
	{"ft_strtrim.cases", "ft_strtrim", "mandatory", "required", "trim edges, all, empty set, empty string", test_strtrim_cases},
	{"ft_split.cases", "ft_split", "mandatory", "required", "basic, delimiters-only, empty, NUL delimiter", test_split_cases},
	{"ft_itoa.cases", "ft_itoa", "mandatory", "required", "zero, signs, INT_MIN, INT_MAX", test_itoa_cases},
	{"ft_strmapi.cases", "ft_strmapi", "mandatory", "required", "index-aware transform and empty string", test_strmapi_cases},
	{"ft_striteri.cases", "ft_striteri", "mandatory", "required", "in-place index-aware transform", test_striteri_cases},
	{"ft_putchar_fd.cases", "ft_putchar_fd", "mandatory", "required", "pipe output and invalid fd smoke", test_putchar_fd_cases},
	{"ft_putstr_fd.cases", "ft_putstr_fd", "mandatory", "required", "pipe output and invalid fd smoke", test_putstr_fd_cases},
	{"ft_putendl_fd.cases", "ft_putendl_fd", "mandatory", "required", "pipe output and newline handling", test_putendl_fd_cases},
	{"ft_putnbr_fd.cases", "ft_putnbr_fd", "mandatory", "required", "zero, negative, and INT_MIN output", test_putnbr_fd_cases},
	{"ft_lstnew.cases", "ft_lstnew", "mandatory", "required", "content and NULL initialization", test_lstnew_cases},
	{"ft_lstadd_front.cases", "ft_lstadd_front", "mandatory", "required", "prepend to filled and empty lists", test_lstadd_front_cases},
	{"ft_lstsize.cases", "ft_lstsize", "mandatory", "required", "NULL and multi-node list size", test_lstsize_cases},
	{"ft_lstlast.cases", "ft_lstlast", "mandatory", "required", "NULL and final node lookup", test_lstlast_cases},
	{"ft_lstadd_back.cases", "ft_lstadd_back", "mandatory", "required", "append to filled and empty lists", test_lstadd_back_cases},
	{"ft_lstdelone.cases", "ft_lstdelone", "mandatory", "required", "single-node delete callback", test_lstdelone_cases},
	{"ft_lstclear.cases", "ft_lstclear", "mandatory", "required", "clear list, delete contents, NULL head", test_lstclear_cases},
	{"ft_lstiter.cases", "ft_lstiter", "mandatory", "required", "iterate all node contents", test_lstiter_cases},
	{"ft_lstmap.cases", "ft_lstmap", "mandatory", "required", "map values into a new allocated list", test_lstmap_cases},
	{"ft_calloc.allocfail", "ft_calloc", "mandatory", "allocfail", "allocation failure returns NULL", test_allocfail_calloc},
	{"ft_strdup.allocfail", "ft_strdup", "mandatory", "allocfail", "allocation failure returns NULL", test_allocfail_strdup},
	{"ft_substr.allocfail", "ft_substr", "mandatory", "allocfail", "allocation failure returns NULL", test_allocfail_substr},
	{"ft_strjoin.allocfail", "ft_strjoin", "mandatory", "allocfail", "allocation failure returns NULL", test_allocfail_strjoin},
	{"ft_strtrim.allocfail", "ft_strtrim", "mandatory", "allocfail", "allocation failure returns NULL", test_allocfail_strtrim},
	{"ft_split.allocfail", "ft_split", "mandatory", "allocfail", "partial allocation failure is cleaned up", test_allocfail_split},
	{"ft_itoa.allocfail", "ft_itoa", "mandatory", "allocfail", "allocation failure returns NULL", test_allocfail_itoa},
	{"ft_strmapi.allocfail", "ft_strmapi", "mandatory", "allocfail", "allocation failure returns NULL", test_allocfail_strmapi},
	{"ft_lstnew.allocfail", "ft_lstnew", "mandatory", "allocfail", "allocation failure returns NULL", test_allocfail_lstnew},
	{"ft_memcpy.probe_null_zero", "ft_memcpy", "mandatory", "probe", "NULL pointers with len 0 diagnostic", test_probe_memcpy_null_zero},
	{"ft_memmove.probe_null_zero", "ft_memmove", "mandatory", "probe", "NULL pointers with len 0 diagnostic", test_probe_memmove_null_zero},
	{"ft_substr.probe_null", "ft_substr", "mandatory", "probe", "NULL string diagnostic", test_probe_substr_null},
	{"ft_strjoin.probe_null", "ft_strjoin", "mandatory", "probe", "NULL string diagnostic", test_probe_strjoin_null},
	{"ft_split.probe_null", "ft_split", "mandatory", "probe", "NULL string diagnostic", test_probe_split_null},
	{"ft_striteri.probe_null", "ft_striteri", "mandatory", "probe", "NULL string diagnostic", test_probe_striteri_null},
};

static size_t	test_count(void)
{
	return (sizeof(g_tests) / sizeof(g_tests[0]));
}

static int	list_tests(void)
{
	size_t	index;

	index = 0;
	while (index < test_count())
	{
		printf("%s\t%s\t%s\t%s\t%s\n", g_tests[index].id,
			g_tests[index].function, g_tests[index].group,
			g_tests[index].kind, g_tests[index].description);
		index++;
	}
	return (0);
}

static int	run_test(const char *id)
{
	size_t		index;
	char		message[1024];
	t_lt_result	result;

	index = 0;
	while (index < test_count())
	{
		if (strcmp(g_tests[index].id, id) == 0)
		{
			message[0] = '\0';
			result = g_tests[index].fn(message, sizeof(message));
			if (message[0])
				puts(message);
			return ((int)result);
		}
		index++;
	}
	fprintf(stderr, "unknown test id: %s\n", id);
	return (LT_FAIL);
}

int	main(int argc, char **argv)
{
	if (argc == 2 && strcmp(argv[1], "--list") == 0)
		return (list_tests());
	if (argc == 3 && strcmp(argv[1], "--run") == 0)
		return (run_test(argv[2]));
	fprintf(stderr, "usage: %s --list | --run <test-id>\n", argv[0]);
	return (LT_FAIL);
}
