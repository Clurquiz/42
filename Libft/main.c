/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: curquiza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:14:47 by curquiza          #+#    #+#             */
/*   Updated: 2016/11/21 16:40:10 by curquiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "libft.h"

#define COLOR_RESET "\033[0m"
#define COLOR_TITLE "\033[33m"
#define COLOR_BIG_TITLE "\033[36m"
#define COLOR_SUCCES "\033[32m"
#define COLOR_FAIL "\033[31m"

#define VALEUR_A "Clementine92"
#define VALEUR_B "hel lo"
#define VALEUR_VIDE ""
#define LEN 4

void	ft_init_str(char **a1, char **a2, char **b1, char **b2, char **vide1, char **vide2)
{
	free(*a1);
	free(*a2);
	free(*b1);
	free(*b2);
	free(*vide1);
	free(*vide2);
	*a1 = ft_strdup(VALEUR_A);
	*a2 = ft_strdup(VALEUR_A);
	*b1 = ft_strdup(VALEUR_B);
	*b2 = ft_strdup(VALEUR_B);
	*vide1 = ft_strdup(VALEUR_VIDE);
	*vide2 = ft_strdup(VALEUR_VIDE);
}

void	ft_init_tab_int(int *tab, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		tab[i] = i + 1;
}

void	ft_aff_tab_int(int num ,int *tab, int len)
{
	int	i;

	i = -1;
	printf("tab%d[%d] = {", num, LEN);
	while (++i < len)
	{
		printf("%d", tab[i]);
		if (i != 3)
			printf(", ");
	}
	printf("}\n");
}

void	ft_aff_list(t_list *begin_list)
{
	while (begin_list)
	{
		printf("content = \"%s\", content_size = %zu\n", begin_list->content, begin_list->content_size);
		begin_list = begin_list->next;
	}
}

void	ft_aff_split(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != 0)
	{
		printf("tab[%d] = \"%s\"\n", i, tab[i]);
		i++;
	}
	printf("tab[%d] = \"%s\"\n\n", i, tab[i]);
}

void	ft_free_split(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

void	ft_test_striter(char *s)
{
	*s = *s + 1;
	printf("%c", *s);
}

void	ft_test_striteri(unsigned int i, char *s)
{
	printf("old char : %c - ", *s);
	*s = *s + 1;
	printf("new char : %c - index : %d\n", *s, i);
}

char	ft_test_strmap(char s)
{
	s = s + 1;
	return (s);
}

char	ft_test_strmapi(unsigned int i, char s)
{
	s = s + 1;
	printf("%d ", i);
	return (s);
}

void	ft_test_lstiter(t_list *elem)
{
	elem->content_size = 42;
}

t_list	*ft_test_lstmap(t_list *elem)
{
	//t_list	*tmp;

	//tmp = lstnew("ecole42", sizeof("ecole42"));
	elem->content = ft_strdup("ecole42");
	return (elem);
}

void	ft_del_lst(void *content, size_t content_size)
{
	free(content);
	content = NULL;
	content_size = 0;
}

int		main(void)
{
	char	*vide1;
	char	*vide2;
	char	*a1;
	char	*a2;
	char	*b1;
	char	*b2;
	int		tab1[LEN];
	int		tab2[LEN];

	a1 = ft_strdup(VALEUR_A);
	a2 = ft_strdup(VALEUR_A);
	b1 = ft_strdup(VALEUR_B);
	b2 = ft_strdup(VALEUR_B);
	vide1 = ft_strdup(VALEUR_VIDE);
	vide2 = ft_strdup(VALEUR_VIDE);



// *****************************************************************************
// ******************************* PARTIE I ************************************
// *****************************************************************************

printf(COLOR_BIG_TITLE "\n\n\n*****************************************************************************\n");
printf("******************************* PARTIE I ************************************\n");
printf("*****************************************************************************\n" COLOR_RESET);

// === MEMSET ==================================================================

	printf(COLOR_TITLE "\n---------- MEMSET ----------\n\n" COLOR_RESET);
	printf("a1 = \"%s\"\n", a1);
	printf("a2 = \"%s\"\n", a2);
	printf("vide1 = \"%s\"\n", vide1);
	printf("vide2 = \"%s\"\n\n", vide2);
	
	memset(a1, 'b', 4);
	printf("memset(a1, 'b', 4) ==> a1 = %s\n", a1);
	ft_memset(a2, 'b', 4);
	printf("ft_memset(a2, 'b', 4) ==> a2 = %s\n\n", a2);
	
	memset(a1, 0, 4);
	printf("memset(a1, 0, 4) ==> a1 = %s\n", a1);
	ft_memset(a2, 0, 4);
	printf("ft_memset(a2, 0, 4) ==> a2 = %s\n\n", a2);
	
	memset(vide1, 'B', 3);
	printf("memset(vide1,'B', 3) ==> vide1 = %s\n", vide1);
	ft_memset(vide2, 'B', 3);
	printf("ft_memset(vide2,'B', 3) ==> vide2 = %s\n", vide2);
	
	//La vraie fonction memset empeche la compilation : overflow de destination
	//comme memset(a1, 'B', 102);

	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);


// === BZERO ===================================================================

	printf(COLOR_TITLE "\n\n---------- BZERO ----------\n\n" COLOR_RESET);
	printf("a1 = \"%s\"\n", a1);
	printf("a2 = \"%s\"\n", a2);
	printf("b1 = \"%s\"\n", b1);
	printf("b2 = \"%s\"\n", b2);
	printf("vide1 = \"%s\"\n", vide1);
	printf("vide2 = \"%s\"\n", vide2);
	ft_init_tab_int(tab1, LEN);
	ft_init_tab_int(tab2, LEN);
	ft_aff_tab_int(1, tab1, LEN);
	ft_aff_tab_int(2, tab2, LEN);

	bzero(tab1, 4);
	ft_bzero(tab2, 4);	
	printf("\nAvec les tableaux de int :\nbzero(tab1, 4) ==> ");
	ft_aff_tab_int(1, tab1, LEN);
	printf("ft_bzero(tab2, 4) ==> ");
	ft_aff_tab_int(2, tab2, LEN);
	ft_init_tab_int(tab1, LEN);
	ft_init_tab_int(tab2, LEN);
	
	bzero(tab1, 9);
	ft_bzero(tab2, 9);
	printf("bzero(tab1, 9) ==> ");
	ft_aff_tab_int(1, tab1, LEN);
	printf("ft_bzero(tab2, 9) ==> ");
	ft_aff_tab_int(2, tab2, LEN);
	ft_init_tab_int(tab1, LEN);
	ft_init_tab_int(tab2, LEN);

	// si je re-utilise les chaines a1 et a2, bzero rale.	
	bzero(a1, 4);
	ft_bzero(a2, 4);
	printf("\nAvec les chaines de caracteres :\nbzero(a1, 4) ==> %s", a1);
	printf("\nft_bzero(a2, 4) ==> %s\n", a2);
		
	bzero(b1, 0);
	ft_bzero(b2, 0);
	printf("bzero(b1, 0) ==> %s", b1);
	printf("\nft_bzero(b2, 0) ==> %s\n", b2);

	bzero(vide1, 20);
	ft_bzero(vide2, 20);
	printf("bzero(vide1, 20) ==> %s", vide1);
	printf("\nft_bzero(vide2, 20) ==> %s\n", vide2);
		
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);


// === MEMCPY ==================================================================

	printf(COLOR_TITLE "\n\n---------- MEMCPY ----------\n\n" COLOR_RESET);
	printf("a1 = \"%s\"\n", a1);
	printf("a2 = \"%s\"\n", a2);
	printf("b1 = \"%s\"\n", b1);
	printf("b2 = \"%s\"\n", b2);
	printf("vide1 = \"%s\"\n", vide1);
	printf("vide2 = \"%s\"\n\n", vide2);
	
	printf("memcpy(a1, b1, 4) ==> %s\n", memcpy(a1, b1, 4));
	printf("ft_memcpy(a2, b2, 4) ==> %s\n", ft_memcpy(a2, b2, 4));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("memcpy(b1, a1, 9) ==> %s\n", memcpy(b1, a1, 9));
	printf("ft_memcpy(b2, a2, 9) ==> %s\n", ft_memcpy(b2, a2, 9));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("memcpy(a1, b1, 0) ==> %s\n", memcpy(a1, b1, 0));
	printf("ft_memcpy(a2, b2, 0) ==> %s\n", ft_memcpy(a2, b2, 0));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("memcpy(a1, b1, 0) ==> %s\n", memcpy(a1, b1, 0));
	printf("ft_memcpy(a2, b2, 0) ==> %s\n", ft_memcpy(a2, b2, 0));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("memcpy(vide1, a1, 4) ==> %s\n", memcpy(vide1, a1, 4));
	printf("ft_memcpy(vide2, a2, 4) ==> %s\n", ft_memcpy(vide2, a2, 4));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("memcpy(a1, vide1, 4) ==> %s\n", memcpy(a1, vide1, 4));
	printf("ft_memcpy(a2, vide2, 4) ==> %s\n", ft_memcpy(a2, vide2, 4));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("memcpy(vide1, \"\", 4) ==> %s\n", memcpy(vide1, "", 4));
	printf("ft_memcpy(vide2, \"\", 4) ==> %s\n", ft_memcpy(vide2, "", 4));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);


// === MEMCCPY =================================================================

	printf(COLOR_TITLE "\n\n---------- MEMCCPY ----------\n\n" COLOR_RESET);
	printf("a1 = \"%s\"\n", a1);
	printf("a2 = \"%s\"\n", a2);
	printf("b1 = \"%s\"\n", b1);
	printf("b2 = \"%s\"\n", b2);
	printf("vide1 = \"%s\"\n", vide1);
	printf("vide2 = \"%s\"\n\n", vide2);

	printf("memccpy(a1, b1, 'l', 4) ==> dst = %s, return = %s\n", a1, memccpy(a1, b1, 'l', 4));
	printf("ft_memccpy(a2, b2, 'l', 4) ==> dst = %s, return = %s\n", a2, ft_memccpy(a2, b2, 'l', 4));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	
	printf("\nmemccpy(a1, b1, 'l', 20) ==> dst = %s, return = %s\n", a1, memccpy(a1, b1, 'l', 20));
	printf("ft_memccpy(a2, b2, 'l', 20) ==> dst = %s, return = %s\n", a2, ft_memccpy(a2, b2, 'l', 20));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	
	printf("\nmemccpy(a1, b1, 'l', 0) ==> dst = %s, return = %s\n", a1, memccpy(a1, b1, 'l', 0));
	printf("ft_memccpy(a2, b2, 'l', 0) ==> dst = %s, return = %s\n", a2, ft_memccpy(a2, b2, 'l', 0));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	
	printf("\nmemccpy(a1, b1, 'y', 4) ==> dst = %s, return = %s\n", a1, memccpy(a1, b1, 'y', 4));
	printf("ft_memccpy(a2, b2, 'y', 4) ==> dst = %s, return = %s\n", a2, ft_memccpy(a2, b2, 'y', 4));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	
	//printf("\nmemccpy(a1, b1, 'y', 20) ==> dst = %s, return = %s\n", a1, memccpy(a1, b1, 'y', 20));
	//printf("ft_memccpy(a2, b2, 'y', 20) ==> dst = %s, return = %s\n", a2, ft_memccpy(a2, b2, 'y', 20));
	//ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	
	//printf("\nmemccpy(a1, b1, 'y', 0) ==> dst = %s, return = %s\n", a1, memccpy(a1, b1, 'y', 0));
	//printf("ft_memccpy(a2, b2, 'y', 0) ==> dst = %s, return = %s\n", a2, ft_memccpy(a2, b2, 'y', 0));
	//ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	
	//printf("\nmemccpy(vide1, b1, 'y', 4) ==> dst = %s, return = %s\n", vide1, memccpy(vide1, b1, 'y', 4));
	//printf("ft_memccpy(vide2, b2, 'y', 4) ==> dst = %s, return = %s\n", vide2, ft_memccpy(vide2, b2, 'y', 4));
	//ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	
	//printf("memccpy(a1, vide1, 'y', 4) ==> dst = %s, return = %s\n", a1, memccpy(a1, vide1, 'y', 4));
	//printf("ft_memccpy(a2, vide2, 'y', 4) ==> dst = %s, return = %s\n", a2, ft_memccpy(a2, vide2, 'y', 4));
	
	//ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	
	//printf("memccpy(vide1, \"\", 'y', 4) ==> dst = %s, return = %s\n", vide1, memccpy(vide1, "", 'y', 4));
	//printf("ft_memccpy(vide2, \"\", 'y', 4) ==> dst = %s, return = %s\n", vide2, ft_memccpy(vide2, "", 'y', 4));
	//ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);


// === MEMMOVE =================================================================

	printf(COLOR_TITLE "\n\n---------- MEMMOVE ----------\n\n" COLOR_RESET);
	printf("a1 = \"%s\"\n", a1);
	printf("a2 = \"%s\"\n", a2);
	printf("b1 = \"%s\"\n", b1);
	printf("b2 = \"%s\"\n", b2);
	printf("vide1 = \"%s\"\n", vide1);
	printf("vide2 = \"%s\"\n\n", vide2);

	printf("memmove(a1 + 1, a1, 5) => %s\n", memmove(a1 + 1, a1, 5));
	printf("ft_memmove(a2 + 1, a2, 5) => %s\n\n", ft_memmove(a2 + 1, a2, 5));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	
	printf("memmove(a1, a1 + 1, 5) => %s\n", memmove(a1, a1 + 1, 5));
	printf("ft_memmove(a2, a2 + 1, 5) => %s\n\n", ft_memmove(a2, a2 + 1, 5));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);

	printf("memmove(a1, b1, 5) => %s\n", memmove(a1, b1, 5));
	printf("ft_memmove(a2, b2, 5) => %s\n\n", ft_memmove(a2, b2, 5));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);

	printf("memmove(a1 + 4, a1, 0) => %s\n", memmove(a1 + 4, a1, 0));
	printf("ft_memmove(a2 + 4, a2, 0) => %s\n\n", ft_memmove(a2 + 4, a2, 0));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);

	printf("\nmemmove(vide1, a1, 5) => %s\n", memmove(vide1, a1, 5));
	printf("ft_memmove(vide2, a2, 5) => %s\n\n", ft_memmove(vide2, a2, 5));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);

	printf("memmove(a1, vide1, 5) => %s\n", memmove(a1, vide1, 5));
	printf("ft_memmove(a2, vide2, 5) => %s\n\n", ft_memmove(a2, vide2, 5));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);

	printf("memmove(vide1, \"\", 5) => %s\n", memmove(vide1, "", 5));
	printf("ft_memmove(vide2, \"\", 5) => %s\n\n", ft_memmove(vide2, "", 5));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);


// === MEMCHR ==================================================================
	
	printf(COLOR_TITLE "\n\n---------- MEMCHR ----------\n\n" COLOR_RESET);
	printf("a1 = \"%s\"\n", a1);
	printf("a2 = \"%s\"\n", a2);
	printf("vide1 = \"%s\"\n", vide1);
	printf("vide2 = \"%s\"\n\n", vide2);
	
	printf("memchr(a1, 'm', 10) => %s\n", memchr(a1, 'm', 10));
	printf("ft_memchr(a2, 'm', 10) => %s\n", ft_memchr(a2, 'm', 10));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("memchr(a1, 'm', 1) => %s\n", memchr(a1, 'm', 1));
	printf("ft_memchr(a2, 'm', 1) => %s\n", ft_memchr(a2, 'm', 1));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("memchr(a1, 'm', 20) => %s\n", memchr(a1, 'm', 20));
	printf("ft_memchr(a2, 'm', 20) => %s\n", ft_memchr(a2, 'm', 20));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("memchr(a1, 'm', 0) => %s\n", memchr(a1, 'm', 0));
	printf("ft_memchr(a2, 'm', 0) => %s\n", ft_memchr(a2, 'm', 0));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("memchr(a1, 'y', 10) => %s\n", memchr(a1, 'y', 10));
	printf("ft_memchr(a2, 'y', 10) => %s\n", ft_memchr(a2, 'y', 10));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("memchr(a1, 'y', 20) => %s\n", memchr(a1, 'y', 20));
	printf("ft_memchr(a2, 'y', 20) => %s\n", ft_memchr(a2, 'y', 20));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("memchr(vide1, 'y', 20) => %s\n", memchr(vide1, 'y', 20));
	printf("ft_memchr(vide2, 'y', 20) => %s\n", ft_memchr(vide2, 'y', 20));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("memchr(a1, 0, 20) => %s\n", memchr(a1, 0, 20));
	printf("ft_memchr(a2, 0, 20) => %s\n", ft_memchr(a2, 0, 20));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);


// === MEMCMP ==================================================================

	printf(COLOR_TITLE "\n\n---------- MEMCMP ----------\n\n" COLOR_RESET);
	printf("a1 = \"%s\"\n", a1);
	printf("a2 = \"%s\"\n", a2);
	printf("b1 = \"%s\"\n", b1);
	printf("b2 = \"%s\"\n", b2);
	printf("vide1 = \"%s\"\n", vide1);
	printf("vide2 = \"%s\"\n\n", vide2);
	
	printf("memcmp ~ ft_memcmp\n");
	printf("(\"\", \"\", 10) => %d ~ %d\n", memcmp("", "", 10), ft_memcmp("","", 10));
	printf("(\"\", \"test\", 10) => %d ~ %d\n", memcmp("", "test", 10), ft_memcmp("","test", 10));
	printf("(\"test\", \"\", 10) => %d ~ %d\n", memcmp("test", "", 10), ft_memcmp("test","", 10));
	printf("(\"hello the \", \"hello the \", 25) => %d ~ %d\n", memcmp("hello the ", "hello the ", 25), ft_memcmp("hello the ","hello the ", 25));
	printf("(\"test1\", \"test2\", 10) => %d ~ %d\n", memcmp("test1", "test2", 10), ft_memcmp("test1","test2", 10));
	printf("(\"test1\", \"test2\", 2) => %d ~ %d\n", memcmp("test1", "test2", 2), ft_memcmp("test1","test2", 2));
	printf("(\"testtt\", \"test\", 10) => %d ~ %d\n", memcmp("testtt", "test", 10), ft_memcmp("testtt","test", 10));
	printf("(\"test\", \"testtt\", 10) => %d ~ %d\n", memcmp("test", "testtt", 10), ft_memcmp("test","testtt", 10));
	printf("(\"test\", \"testtt\", 4) => %d ~ %d\n", memcmp("test", "testtt", 4), ft_memcmp("test","testtt", 4));
	printf("(\"test\", \"hello\", 10) => %d ~ %d\n", memcmp("test", "hello", 10), ft_memcmp("test","hello", 10));
	printf("(\"test\", \"hello\", 1) => %d ~ %d\n", memcmp("test", "hello", 1), ft_memcmp("test","hello", 1));
	printf("(\"test\", \"hello\", 0) => %d ~ %d\n", memcmp("test", "hello", 0), ft_memcmp("test","hello", 0));


// === STRLEN ==================================================================

	printf(COLOR_TITLE "\n\n---------- STRLEN ----------\n\n" COLOR_RESET);
	printf("Taille de a2 = \"%s\" ==> %zu\n", a2, ft_strlen(a2));
	printf("Taille de b2 = \"%s\" ==> %zu\n", b2, ft_strlen(b2));
	printf("Taille de vide2 = \"%s\" ==> %zu\n", vide2, ft_strlen(vide2));


// === STRDUP ==================================================================

	printf(COLOR_TITLE "\n\n---------- STRDUP ----------\n\n" COLOR_RESET);
	printf("strdup(\"Tatata\") ==> %s\n", strdup("Tatata"));
	printf("ft_strdup(\"Tatata\") ==> %s\n", ft_strdup("Tatata"));
	printf("strdup(\"Tatata  Hello   \") ==> %s\n", strdup("Tatata  Hello   "));
	printf("ft_strdup(\"Tatata  Hello   \") ==> %s\n", ft_strdup("Tatata  Hello   "));
	printf("strdup(\"\") ==> %s\n", strdup(""));
	printf("ft_strdup(\"\") ==> %s\n", ft_strdup(""));


// === STRCPY ==================================================================

	printf(COLOR_TITLE "\n\n---------- STRCPY ----------\n\n" COLOR_RESET);
	printf("a1 = \"%s\"\n", a1);
	printf("a2 = \"%s\"\n", a2);
	printf("vide1 = \"%s\"\n", vide1);
	printf("vide2 = \"%s\"\n\n", vide2);

	// la src ne doit pas etre plus grande que la dst
	printf("strcpy(a1, \"TEST\") ==> %s\n", strcpy(a1, "TEST"));
	printf("ft_strcpy(a2, \"TEST\") ==> %s\n", ft_strcpy(a2, "TEST"));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("strcpy(a1, \"HellohelloHi\") ==> %s\n", strcpy(a1, "HellohelloHi"));
	printf("ft_strcpy(a2, \"HellohelloHi\") ==> %s\n", ft_strcpy(a2, "HellohelloHi"));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("strcpy(a1, \"\") ==> %s\n", strcpy(a1, ""));
	printf("ft_strcpy(a2, \"\") ==> %s\n", ft_strcpy(a2, ""));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("strcpy(vide1, \"\") ==> %s\n", strcpy(vide1, ""));
	printf("ft_strcpy(vide2, \"\") ==> %s\n", ft_strcpy(vide2, ""));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	

// === STRNCPY =================================================================

	printf(COLOR_TITLE "\n\n---------- STRNCPY ----------\n\n" COLOR_RESET);
	printf("a1 = \"%s\"\n", a1);
	printf("a2 = \"%s\"\n", a2);
	printf("vide1 = \"%s\"\n", vide1);
	printf("vide2 = \"%s\"\n\n", vide2);

	printf("strncpy(a1, \"TEST\", 20) ==> %s\n", strncpy(a1, "TEST", 20));
	printf("ft_strncpy(a2, \"TEST\", 20) ==> %s\n", ft_strncpy(a2, "TEST", 20));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("strncpy(a1, \"TEST\", 2) ==> %s\n", strncpy(a1, "TEST", 2));
	printf("ft_strncpy(a2, \"TEST\", 2) ==> %s\n", ft_strncpy(a2, "TEST", 2));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("strncpy(a1, \"HellohelloHi\", 12) ==> %s\n", strncpy(a1, "HellohelloHi", 12));
	printf("ft_strncpy(a2, \"HellohelloHi\", 12) ==> %s\n", ft_strncpy(a2, "HellohelloHi", 12));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("strncpy(a1, \"\", 2) ==> %s\n", strncpy(a1, "", 2));
	printf("ft_strncpy(a2, \"\", 2) ==> %s\n", ft_strncpy(a2, "", 2));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("strncpy(vide1, \"\", 2) ==> %s\n", strncpy(vide1, "", 2));
	printf("ft_strncpy(vide2, \"\", 2) ==> %s\n", ft_strncpy(vide2, "", 2));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);

	
// === STRCAT ==================================================================

	printf(COLOR_TITLE "\n\n---------- STRCAT ----------\n\n" COLOR_RESET);
	printf("a1 = \"%s\"\n", a1);
	printf("a2 = \"%s\"\n", a2);
	printf("vide1 = \"%s\"\n", vide1);
	printf("vide2 = \"%s\"\n\n", vide2);

	//rajouter chaine2 dans chaine1 ne doit pas depasser la taille de chaine1
	//si je ne re-initialise pas a chaque fois, ça bugue, a2 devient vide -> pourquoi ?
	printf("strcat(a1, \"TEST\") ==> %s\n", strcat(a1, "TEST"));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("ft_strcat(a2, \"TEST\") ==> %s\n", ft_strcat(a2, "TEST"));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("strcat(a1, \"HelloLesCocos!!!\") ==> %s\n", strcat(a1, "HelloLesCocos!!!"));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("ft_strcat(a2, \"HelloLesCocos!!!\") ==> %s\n", ft_strcat(a2, "HelloLesCocos!!!"));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("strcat(a1, \"\") ==> %s\n", strcat(a1, ""));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("ft_strcat(a2, \"\") ==> %s\n", ft_strcat(a2, ""));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);


// === STRNCAT =================================================================

	printf(COLOR_TITLE "\n\n---------- STRNCAT ----------\n\n" COLOR_RESET);
	printf("a1 = \"%s\"\n", a1);
	printf("a2 = \"%s\"\n", a2);
	printf("vide1 = \"%s\"\n", vide1);
	printf("vide2 = \"%s\"\n\n", vide2);

	//rajouter chaine2 dans chaine1 ne doit pas depasser la taille de chaine1
	//si je ne re-initialise pas a chaque fois, ça bugue, a2 devient vide -> pourquoi ?
	printf("strncat(a1, \"TEST\", 8) ==> %s\n", strncat(a1, "TEST", 8));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("ft_strncat(a2, \"TEST\", 8) ==> %s\n", ft_strncat(a2, "TEST", 8));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	
	printf("strncat(a1, \"TEST\", 0) ==> %s\n", strncat(a1, "TEST", 0));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("ft_strncat(a2, \"TEST\", 0) ==> %s\n", ft_strncat(a2, "TEST", 0));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);


	printf("strncat(a1, \"HelloLesCocos!!!\", 2) ==> %s\n", strncat(a1, "HelloLesCocos!!!", 2));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("ft_strncat(a2, \"HelloLesCocos!!!\", 2) ==> %s\n", ft_strncat(a2, "HelloLesCocos!!!", 2));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("strncat(a1, \"\", 8) ==> %s\n", strncat(a1, "", 8));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);


// === STRLCAT =================================================================

	printf(COLOR_TITLE "\n\n---------- STRLCAT ----------\n\n" COLOR_RESET);
	printf("a1 = \"%s\"\n", a1);
	printf("a2 = \"%s\"\n", a2);
	printf("vide1 = \"%s\"\n", vide1);
	printf("vide2 = \"%s\"\n\n", vide2);

	//char	truc[100]= "Clementine92";
	printf("strlcat(a1, \"TEST\", 20) ==> return = %zu, dst = %s\n", strlcat(a1, "TEST", 20), a1);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("ft_strlcat(a2, \"TEST\", 20) ==> return = %zu, dst = %s\n\n", ft_strlcat(a2, "TEST", 20), a2);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	
	printf("strlcat(a1, \"TEST\", 7) ==> return = %zu, dst = %s\n", strlcat(a1, "TEST", 7), a1);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("ft_strlcat(a2, \"TEST\", 7) ==> return = %zu, dst = %s\n\n", ft_strlcat(a2, "TEST", 7), a2);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	
	printf("strlcat(a1, \"TEST\", 15) ==> return = %zu, dst = %s\n", strlcat(a1, "TEST", 15), a1);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("ft_strlcat(a2, \"TEST\", 15) ==> return = %zu, dst = %s\n\n", ft_strlcat(a2, "TEST", 15), a2);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	
	printf("strlcat(a1, \"TEST\", 12) ==> return = %zu, dst = %s\n", strlcat(a1, "TEST", 12), a1);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("ft_strlcat(a2, \"TEST\", 12) ==> return = %zu, dst = %s\n\n", ft_strlcat(a2, "TEST", 12), a2);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	
	//printf("strlcat(a1, \"HelloLesCocos Comment ca va ?\", 20) ==> return = %zu, dst = %s\n", strlcat(a1, "HelloLesCocos Comment ca va ?", 20), a1);
	//ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	//printf("ft_strlcat(a2, \"HelloLesCocos Comment ca va ?\", 20) ==> return = %zu, dst = %s\n\n", ft_strlcat(a2, "HelloLesCocos Comment ca va ?", 20), a2);
	//ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);

	printf("strlcat(a1, \"TEST\", 0) ==> return = %zu, dst = %s\n", strlcat(a1, "TEST", 0), a1);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("ft_strlcat(a2, \"TEST\", 0) ==> return = %zu, dst = %s\n\n", ft_strlcat(a2, "TEST", 0), a2);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	
	printf("strlcat(a1, \"\", 10) ==> return = %zu, dst = %s\n", strlcat(a1, "", 10), a1);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("ft_strlcat(a2, \"\", 10) ==> return = %zu, dst = %s\n\n", ft_strlcat(a2, "", 10), a2);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	
	printf("strlcat(a1, \"\", 20) ==> return = %zu, dst = %s\n", strlcat(a1, "", 20), a1);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	printf("ft_strlcat(a2, \"\", 20) ==> return = %zu, dst = %s\n", ft_strlcat(a2, "", 20), a2);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);


// === STRCHR ==================================================================

	printf(COLOR_TITLE "\n\n---------- STRCHR ----------\n\n" COLOR_RESET);

	printf("strchr ~ ft_strchr\n");
	printf("(\"Clementine\", 'm') ==> %s ~ %s\n", strchr("Clementine", 'm'), ft_strchr("Clementine", 'm'));
	printf("(\"Clementine\", 'y') ==> %s ~ %s\n", strchr("Clementine", 'y'), ft_strchr("Clementine", 'y'));
	printf("(\"C\", 'C') ==> %s ~ %s\n", strchr("C", 'C'), ft_strchr("C", 'C'));
	printf("(\"C\", 'c') ==> %s ~ %s\n", strchr("C", 'c'), ft_strchr("C", 'c'));
	printf("(\"\", 'm') ==> %s ~ %s\n", strchr("", 'm'), ft_strchr("", 'm'));
	printf("(\"Clementine\", '\\0') ==> %s ~ %s\n", strchr("Clementine", '\0'), ft_strchr("Clementine", '\0'));
	printf("(\"\", '\\0') ==> %s ~ %s\n", strchr("", '\0'), ft_strchr("", '\0'));


// === STRRCHR ==================================================================

	printf(COLOR_TITLE "\n\n---------- STRRCHR ----------\n\n" COLOR_RESET);

	printf("strrchr ~ ft_strrchr\n");
	printf("(\"Clementine\", 'm') ==> %s ~ %s\n", strrchr("Clementine", 'm'), ft_strrchr("Clementine", 'm'));
	printf("(\"Clementine\", 'y') ==> %s ~ %s\n", strrchr("Clementine", 'y'), ft_strrchr("Clementine", 'y'));
	printf("(\"Clementine\", 'C') ==> %s ~ %s\n", strrchr("Clementine", 'C'), ft_strrchr("Clementine", 'C'));
	printf("(\"Clementine\", 'e') ==> %s ~ %s\n", strrchr("Clementine", 'e'), ft_strrchr("Clementine", 'e'));
	printf("(\"Clementine\", '\\0') ==> %s ~ %s\n", strrchr("Clementine", '\0'), ft_strrchr("Clementine", '\0'));
	printf("(\"C\", 'C') ==> %s ~ %s\n", strrchr("C", 'C'), ft_strrchr("C", 'C'));
	printf("(\"C\", 'c') ==> %s ~ %s\n", strrchr("", 'c'), ft_strrchr("C", 'c'));
	printf("(\"\", 'y') ==> %s ~ %s\n", strrchr("", 'y'), ft_strrchr("", 'y'));
	printf("(\"\", '\\0') ==> %s ~ %s\n", strrchr("", '\0'), ft_strrchr("", '\0'));


// === STRSTR ==================================================================

	printf(COLOR_TITLE "\n\n---------- STRSTR ----------\n\n" COLOR_RESET);

	printf("strstr ~ ft_strstr\n");
	printf("(\"Clementine\", \"men\") ==> %s ~ %s\n", strstr("Clementine", "men"), ft_strstr("Clementine", "men"));
	printf("(\"Clementine\", \"ne\") ==> %s ~ %s\n", strstr("Clementine", "ne"), ft_strstr("Clementine", "ne"));
	printf("(\"Clementine\", \"C\") ==> %s ~ %s\n", strstr("Clementine", "C"), ft_strstr("Clementine", "C"));
	printf("(\"Clementine\", \"t\") ==> %s ~ %s\n", strstr("Clementine", "t"), ft_strstr("Clementine", "t"));
	printf("(\"Clementine\", \"\") ==> %s ~ %s\n", strstr("Clementine", ""), ft_strstr("Clementine", ""));
	printf("(\"Clementine\", \"tim\") ==> %s ~ %s\n", strstr("Clementine", "tim"), ft_strstr("Clementine", "tim"));
	printf("(\"Clementine\", \"y\") ==> %s ~ %s\n", strstr("Clementine", "y"), ft_strstr("Clementine", "y"));
	printf("(\"Clem\", \"Clementine\") ==> %s ~ %s\n", strstr("Clem", "Clementine"), ft_strstr("Clem", "Clementine"));
	printf("(\"\", \"y\") ==> %s ~ %s\n", strstr("", "y"), ft_strstr("", "y"));
	printf("(\"y\", \"\") ==> %s ~ %s\n", strstr("y", ""), ft_strstr("y", ""));
	printf("(\"\", \"\") ==> %s ~ %s\n", strstr("", ""), ft_strstr("", ""));


// === STRNSTR =================================================================

	printf(COLOR_TITLE "\n\n---------- STRNSTR ----------\n\n" COLOR_RESET);
	
	printf("strnstr ~ ft_strnstr\n");
	printf("(\"Clementine\", \"ment\", 12) ==> %s ~ %s\n", strnstr("Clementine", "ment", 12), ft_strnstr("Clementine", "ment", 12));
	printf("(\"Clementine\", \"truc\", 12) ==> %s ~ %s\n", strnstr("Clementine", "truc", 12), ft_strnstr("Clementine", "truc", 12));
	printf("(\"Clementine\", \"Clementine\", 12) ==> %s ~ %s\n", strnstr("Clementine", "Clementine", 12), ft_strnstr("Clementine", "Clementine", 12));
	printf("(\"Clementine\", \"Clementine\", 10) ==> %s ~ %s\n", strnstr("Clementine", "Clementine", 10), ft_strnstr("Clementine", "Clementine", 10));
	printf("(\"Clementine\", \"Clementine\", 8) ==> %s ~ %s\n", strnstr("Clementine", "Clementine", 8), ft_strnstr("Clementine", "Clementine", 8));
	printf("(\"Clementine\", \"ment\", 2) ==> %s ~ %s\n", strnstr("Clementine", "ment", 2), ft_strnstr("Clementine", "ment", 2));
	printf("(\"Clementine\", \"ment\", 4) ==> %s ~ %s\n", strnstr("Clementine", "ment", 4), ft_strnstr("Clementine", "ment", 4));
	printf("(\"Clementine\", \"Clement\", 4) ==> %s ~ %s\n", strnstr("Clementine", "Clement", 4), ft_strnstr("Clementine", "Clement", 4));
	printf("(\"Clementine\", \"Clement\", 6) ==> %s ~ %s\n", strnstr("Clementine", "Clement", 6), ft_strnstr("Clementine", "Clement", 6));
	printf("(\"Clementine\", \"Clement\", 7) ==> %s ~ %s\n", strnstr("Clementine", "Clement", 7), ft_strnstr("Clementine", "Clement", 7));
	printf("(\"Clementine\", \"ment\", 6) ==> %s ~ %s\n", strnstr("Clementine", "ment", 6), ft_strnstr("Clementine", "ment", 6));
	printf("(\"Clementine\", \"ment\", 5) ==> %s ~ %s\n", strnstr("Clementine", "ment", 5), ft_strnstr("Clementine", "ment", 5));
	printf("(\"Clementine\", \"ment\", 7) ==> %s ~ %s\n", strnstr("Clementine", "ment", 7), ft_strnstr("Clementine", "ment", 7));
	printf("(\"Clementine\", \"ment\", 0) ==> %s ~ %s\n", strnstr("Clementine", "ment", 0), ft_strnstr("Clementine", "ment", 0));
	printf("(\"\", \"test\", 5) ==> %s ~ %s\n", strnstr("", "test", 5), ft_strnstr("", "test", 5));
	printf("(\"\", \"test\", 0) ==> %s ~ %s\n", strnstr("", "test", 0), ft_strnstr("", "test", 0));
	printf("(\"test\", \"\", 5) ==> %s ~ %s\n", strnstr("test", "", 5), ft_strnstr("test", "", 5));
	printf("(\"test\", \"\", 0) ==> %s ~ %s\n", strnstr("test", "", 0), ft_strnstr("test", "", 0));
	printf("(\"\", \"\", 5) ==> %s ~ %s\n", strnstr("", "", 5), ft_strnstr("", "", 5));
	

// === STRCMP ==================================================================

	printf(COLOR_TITLE "\n\n---------- STRCMP ----------\n\n" COLOR_RESET);
	printf("strcmp(\"Tatata\", \"hello\") ==> %d\n", strcmp("Tatata", "hello"));
	printf("ft_strcmp(\"Tatata\", \"hello\") ==> %d\n", ft_strcmp("Tatata", "hello"));
	printf("strcmp(\"hello\", \"Tatata\") ==> %d\n", strcmp("hello", "Tatata"));
	printf("ft_strcmp(\"hello\", \"Tatata\") ==> %d\n", ft_strcmp("hello", "Tatata"));
	printf("strcmp(\"helli\", \"hello\") ==> %d\n", strcmp("helli", "hello"));
	printf("ft_strcmp(\"helli\", \"hello\") ==> %d\n", ft_strcmp("helli", "hello"));
	printf("strcmp(\"hello\", \"hello\") ==> %d\n", strcmp("hello", "hello"));
	printf("ft_strcmp(\"hello\", \"hello\") ==> %d\n", ft_strcmp("hello", "hello"));
	printf("strcmp(\"poulette\", \"poule\") ==> %d\n", strcmp("poulette", "poule"));
	printf("ft_strcmp(\"poulette\", \"poule\") ==> %d\n", ft_strcmp("poulette", "poule"));
	printf("strcmp(\"\", \"hello\") ==> %d\n", strcmp("", "hello"));
	printf("ft_strcmp(\"\", \"hello\") ==> %d\n", ft_strcmp("", "hello"));
	printf("strcmp(\"helli\", \"\") ==> %d\n", strcmp("helli", ""));
	printf("ft_strcmp(\"helli\", \"\") ==> %d\n", ft_strcmp("helli", ""));
	printf("strcmp(\"\", \"\") ==> %d\n", strcmp("", ""));
	printf("ft_strcmp(\"\", \"\") ==> %d\n", ft_strcmp("", ""));


// === STRNCMP =================================================================

	printf(COLOR_TITLE "\n\n---------- STRNCMP ----------\n\n" COLOR_RESET);

	printf("strncmp ~ ft_strncmp\n");
	printf("(\"Clementine\", \"Clementine\", 12) ==> %d ~ %d\n", strncmp("Clementine", "Clementine", 12), ft_strncmp("Clementine", "Clementine", 12));
	printf("(\"Clementine\", \"Clementine\", 10) ==> %d ~ %d\n", strncmp("Clementine", "Clementine", 10), ft_strncmp("Clementine", "Clementine", 10));
	printf("(\"Clementine\", \"Clementine\", 8) ==> %d ~ %d\n", strncmp("Clementine", "Clementine", 8), ft_strncmp("Clementine", "Clementine", 8));
	printf("(\"Clementine\", \"Clemi\", 12) ==> %d ~ %d\n", strncmp("Clementine", "Clemi", 12), ft_strncmp("Clementine", "Clemi", 12));
	printf("(\"Clementine\", \"Clemi\", 10) ==> %d ~ %d\n", strncmp("Clementine", "Clemi", 10), ft_strncmp("Clementine", "Clemi", 10));
	printf("(\"Clementine\", \"TEST\", 10) ==> %d ~ %d\n", strncmp("Clementine", "TEST", 10), ft_strncmp("Clementine", "TEST", 10));
	printf("(\"Clemi\", \"Clementine\", 10) ==> %d ~ %d\n", strncmp("Clemi", "Clementine", 10), ft_strncmp("Clemi", "Clementine", 10));
	printf("(\"Clementine\", \"Clemi\", 5) ==> %d ~ %d\n", strncmp("Clementine", "Clemi", 5), ft_strncmp("Clementine", "Clemi", 5));
	printf("(\"Clementine\", \"Clemi\", 4) ==> %d ~ %d\n", strncmp("Clementine", "Clemi", 4), ft_strncmp("Clementine", "Clemi", 4));
	printf("(\"Clementine\", \"Clemi\", 0) ==> %d ~ %d\n", strncmp("Clementine", "Clemi", 0), ft_strncmp("Clementine", "Clemi", 0));
	printf("(\"test\", \"\", 15) ==> %d ~ %d\n", strncmp("test", "", 15), ft_strncmp("test", "", 15));
	printf("(\"\", \"test\", 15) ==> %d ~ %d\n", strncmp("", "test", 15), ft_strncmp("", "test", 15));
	printf("(\"\", \"\", 15) ==> %d ~ %d\n", strncmp("", "", 15), ft_strncmp("", "", 15));


// === ATOI = ==================================================================

	printf(COLOR_TITLE "\n\n---------- ATOI ----------\n\n" COLOR_RESET);

	printf("atoi ~ ft_atoi\n");
	printf("\"120\" ==> %d ~ %d\n", atoi("120"), ft_atoi("120"));
	printf("\"-121\" ==> %d ~ %d\n", atoi("-121"), ft_atoi("-121"));
	printf("\"+1\" ==> %d ~ %d\n", atoi("+1"), ft_atoi("+1"));
	printf("\"-45sdds5\" ==> %d ~ %d\n", atoi("-45sdds5"), ft_atoi("-45sdds5"));
	printf("\"+45sdds5\" ==> %d ~ %d\n", atoi("+45sdds5"), ft_atoi("+45sdds5"));
	printf("\" sdds5\" ==> %d ~ %d\n", atoi(" sdds5"), ft_atoi(" sdds5"));
	printf("\"   +1\" ==> %d ~ %d\n", atoi("   +1"), ft_atoi("   +1"));
	printf("\"   -200\" ==> %d ~ %d\n", atoi("   -200"), ft_atoi("   -200"));
	printf("\"+  1\" ==> %d ~ %d\n", atoi("+  1"), ft_atoi("+  1"));
	printf("\"-  1\" ==> %d ~ %d\n", atoi("-  1"), ft_atoi("-  1"));


// === ISALPHA =================================================================
	
	printf(COLOR_TITLE "\n\n---------- ISALPHA ----------\n\n" COLOR_RESET);

	int		i;
	int		cpt;

	i = -20;
	cpt = 0;
	//printf("isalpha ~ ft_isalpha\n");
	while (i <= 130)
	{
		//printf("'%c' ==> %d ~ %d\n", i, isalpha(i), ft_isalpha(i));
		if (isalpha(i) == ft_isalpha(i))
			cpt++;
		i++;
	}
	if (cpt == 151)
		printf(COLOR_SUCCES "OK\n" COLOR_RESET);
	else
		printf(COLOR_FAIL "FAIL !!!!\n" COLOR_RESET);

// === ISDIGIT =================================================================
	
	printf(COLOR_TITLE "\n\n---------- ISDIGIT ----------\n\n" COLOR_RESET);

	i = -20;
	cpt = 0;
	//printf("isdigit ~ ft_isdigit\n");
	while (i <= 130)
	{
		//printf("'%c' ==> %d ~ %d\n", i, isdigit(i), ft_isdigit(i));
		if (isdigit(i) == ft_isdigit(i))
			cpt++;
		i++;
	}
	if (cpt == 151)
		printf(COLOR_SUCCES "OK\n" COLOR_RESET);
	else
		printf(COLOR_FAIL "FAIL !!!!\n" COLOR_RESET);


// === ISALNUM =================================================================
	
	printf(COLOR_TITLE "\n\n---------- ISALNUM ----------\n\n" COLOR_RESET);

	i = -20;
	cpt = 0;
	//printf("isalnum ~ ft_isalnum\n");
	while (i <= 130)
	{
		//printf("'%c' ==> %d ~ %d\n", i, isalnum(i), ft_isalnum(i));
		if (isalnum(i) == ft_isalnum(i))
			cpt++;
		i++;
	}
	if (cpt == 151)
		printf(COLOR_SUCCES "OK\n" COLOR_RESET);
	else
		printf(COLOR_FAIL "FAIL !!!!\n" COLOR_RESET);


// === ISASCII =================================================================
	
	printf(COLOR_TITLE "\n\n---------- ISASCII ----------\n\n" COLOR_RESET);

	i = -20;
	cpt = 0;
	//printf("isasciim ~ ft_isascii\n");
	while (i <= 130)
	{
		//printf("'%c' ==> %d ~ %d\n", i, isascii(i), ft_isalnum(i));
		if (isascii(i) == ft_isascii(i))
			cpt++;
		i++;
	}
	if (cpt == 151)
		printf(COLOR_SUCCES "OK\n" COLOR_RESET);
	else
		printf(COLOR_FAIL "FAIL !!!!\n" COLOR_RESET);


// === ISASCII =================================================================
	
	printf(COLOR_TITLE "\n\n---------- ISASCII ----------\n\n" COLOR_RESET);

	i = -20;
	cpt = 0;
	//printf("isasciim ~ ft_isascii\n");
	while (i <= 130)
	{
		//printf("'%c' ==> %d ~ %d\n", i, isascii(i), ft_isalnum(i));
		if (isascii(i) == ft_isascii(i))
			cpt++;
		i++;
	}
	if (cpt == 151)
		printf(COLOR_SUCCES "OK\n" COLOR_RESET);
	else
		printf(COLOR_FAIL "FAIL !!!!\n" COLOR_RESET);


// === ISPRINT =================================================================
	
	printf(COLOR_TITLE "\n\n---------- ISPRINT ----------\n\n" COLOR_RESET);

	i = -20;
	cpt = 0;
	//printf("isprint ~ ft_isprint\n");
	while (i <= 130)
	{
		//printf("'%c' ==> %d ~ %d\n", i, isprint(i), ft_isprint(i));
		if (isprint(i) == ft_isprint(i))
			cpt++;
		i++;
	}
	if (cpt == 151)
		printf(COLOR_SUCCES "OK\n" COLOR_RESET);
	else
		printf(COLOR_FAIL "FAIL !!!!\n" COLOR_RESET);

	
// === TOUPPER =================================================================
	
	printf(COLOR_TITLE "\n\n---------- TOUPPER ----------\n\n" COLOR_RESET);

	i = -20;
	cpt = 0;
	//printf("toupper ~ ft_toupper\n");
	while (i <= 130)
	{
		//printf("'%c' ==> %d ~ %d\n", i, toupper(i), ft_toupper(i));
		if (toupper(i) == ft_toupper(i))
			cpt++;
		i++;
	}
	if (cpt == 151)
		printf(COLOR_SUCCES "OK\n" COLOR_RESET);
	else
		printf(COLOR_FAIL "FAIL !!!!\n" COLOR_RESET);


// === TOLOWER =================================================================
	
	printf(COLOR_TITLE "\n\n---------- TOLOWER ----------\n\n" COLOR_RESET);

	i = -20;
	cpt = 0;
	//printf("tolower ~ ft_tolower\n");
	while (i <= 130)
	{
		//printf("'%c' ==> %d ~ %d\n", i, tolower(i), ft_tolower(i));
		if (tolower(i) == ft_tolower(i))
			cpt++;
		i++;
	}
	if (cpt == 151)
		printf(COLOR_SUCCES "OK\n" COLOR_RESET);
	else
		printf(COLOR_FAIL "FAIL !!!!\n" COLOR_RESET);



	
// *****************************************************************************
// ******************************* PARTIE II ***********************************
// *****************************************************************************

printf(COLOR_BIG_TITLE "\n\n\n*****************************************************************************\n");
printf("******************************* PARTIE II ***********************************\n");
printf("*****************************************************************************\n" COLOR_RESET);

// === MEMALLOC ================================================================
	
	printf(COLOR_TITLE "\n\n---------- MEMALLOC ----------\n\n" COLOR_RESET);
	
	char	*mem;
	int		size;
	int		j;

	size = 5;
	j = -1;
	mem = ft_memalloc(size);
	printf("mem = ft_memalloc(%d)\nLes cases de mem, affichées en int => ", size);
	while (++j < size)
		printf("%d ", mem[j]);
	printf("\n");

// === MEMDEL ==================================================================
	
	printf(COLOR_TITLE "\n\n---------- MEMDEL ----------\n\n" COLOR_RESET);

	char	*mem2;

	mem2 = ft_memalloc(20);
	mem2 = strcpy(mem2, "truc");
	printf("%s\n", mem2);
	ft_memdel((void **)&mem2);
	printf("%s\n", mem2);


// === STRNEW ==================================================================

	printf(COLOR_TITLE "\n\n---------- STRNEW ----------\n\n" COLOR_RESET);

	char	*strnew;

	size = 4;
	strnew = ft_strnew(size);
	j = -1;
	printf("str = ft_strnew(%d)\nLes cases de str, affichées en char => ", size);
	while (++j <= size)
		printf("\"%c\" ", strnew[j]);
	printf("\n");


// === STRDEL ==================================================================

	printf(COLOR_TITLE "\n\n---------- STRDEL ----------\n\n" COLOR_RESET);

	strnew = strcpy(strnew, "trucmuche");
	printf("%s\n", strnew);
	ft_strdel(&strnew);
	printf("%s\n", strnew);


// === STRCLR ==================================================================

	printf(COLOR_TITLE "\n\n---------- STRCLR ----------\n\n" COLOR_RESET);
	printf("a2 = \"%s\"\n", a2);
	printf("vide2 = \"%s\"\n\n", vide2);

	ft_strclr(a2);
	printf("ft_strclr(a2) => \"%s\"\n", a2);
	ft_strclr(vide2);
	printf("ft_strclr(vide2) => \"%s\"\n", vide2);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);


// === STRITER =================================================================
	
	printf(COLOR_TITLE "\n\n---------- STRITER ----------\n\n" COLOR_RESET);
	printf("a2 = \"%s\"\n", a2);

	printf("\nft_striter(a2) avec une fonction qui ajoute 1 puis affiche le char ==> \n");
	ft_striter(a2, &ft_test_striter);
	//printf("%s\n", a2);
	printf("\n");
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);
	

// === STRITERI =================================================================
	
	printf(COLOR_TITLE "\n\n---------- STRITERI ----------\n\n" COLOR_RESET);
	printf("a2 = \"%s\"\n", a2);

	printf("\nft_striteri(a2) avec une fonction qui ajoute 1, affiche le char puis l'index ==> \n");
	ft_striteri(a2, &ft_test_striteri);
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);


// === STRMAP =================================================================
	
	printf(COLOR_TITLE "\n\n---------- STRMAP ----------\n\n" COLOR_RESET);
	printf("a2 = \"%s\"\n", a2);

	printf("\nft_strmap(a2) avec fonction qui ajoute 1 puis retourne le char ==>\n");
	printf("%s\n", ft_strmap(a2, &ft_test_strmap));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);


// === STRMAPI =================================================================
	
	printf(COLOR_TITLE "\n\n---------- STRMAPI ----------\n\n" COLOR_RESET);
	printf("a2 = \"%s\"\n", a2);

	printf("\nft_strmapi(a2) avec fonction qui ajoute 1 au char, affiche l'index, puis retourne le char ==>\nIndex : ");
	printf("\na2 = %s\n", ft_strmapi(a2, &ft_test_strmapi));
	ft_init_str(&a1, &a2, &b1, &b2, &vide1, &vide2);


// === STREQU ==================================================================

	printf(COLOR_TITLE "\n\n---------- STREQU ----------\n\n" COLOR_RESET);
	printf("Resultat attendu ~ ft_strequ\n");
	printf("strequ(\"Tatata\", \"hello\") ==> 0 ~ %d\n", ft_strequ("Tatata", "hello"));
	printf("strequ(\"hello\", \"Tatata\") ==>  0 ~ %d\n", ft_strequ("hello", "Tatata"));
	
	printf("ft_strequ(\"helli\", \"hello\") ==> 0 ~ %d\n", ft_strequ("helli", "hello"));
	printf("ft_strequ(\"hello\", \"hello\") ==> 1 ~ %d\n", ft_strequ("hello", "hello"));
	printf("ft_strequ(\"poulette\", \"poule\") ==> 0 ~ %d\n", ft_strequ("poulette", "poule"));
	printf("ft_strequ(\"\", \"hello\") ==> 0 ~ %d\n", ft_strequ("", "hello"));
	printf("ft_strequ(\"helli\", \"\") ==> 0 ~ %d\n", ft_strequ("helli", ""));
	printf("ft_strequ(\"\", \"\") ==> 1 ~ %d\n", ft_strequ("", ""));


// === STRNEQU =================================================================

	printf(COLOR_TITLE "\n\n---------- STRNEQU ----------\n\n" COLOR_RESET);

	printf("Resultat attendu ~ ft_strnequ\n");
	printf("(\"Clementine\", \"Clemi\", 10) ==> 0 ~ %d\n", ft_strnequ("Clementine", "Clemi", 10));
	printf("(\"Clementine\", \"TEST\", 10) ==> 0 ~ %d\n", ft_strnequ("Clementine", "TEST", 10));
	printf("(\"Clemi\", \"Clementine\", 10) ==> 0 ~ %d\n", ft_strnequ("Clemi", "Clementine", 10));
	printf("(\"Clementine\", \"Clemi\", 5) ==> 0 ~ %d\n", ft_strnequ("Clementine", "Clemi", 5));
	printf("(\"Clementine\", \"Clemi\", 4) ==> 1 ~ %d\n", ft_strnequ("Clementine", "Clemi", 4));
	printf("(\"Clementine\", \"Clemi\", 0) ==> 1 ~ %d\n", ft_strnequ("Clementine", "Clemi", 0));
	printf("(\"Clementine\", \"test\", 0) ==> 1 ~ %d\n", ft_strnequ("Clementine", "test", 0));
	printf("(\"test\", \"\", 15) ==> 0 ~ %d\n", ft_strnequ("test", "", 15));
	printf("(\"\", \"test\", 15) ==> 0 ~ %d\n", ft_strnequ("", "test", 15));
	printf("(\"\", \"test\", 0) ==> 1 ~ %d\n", ft_strnequ("", "test", 0));
	printf("(\"\", \"\", 15) ==> 1 ~ %d\n", ft_strnequ("", "", 15));


// === STRSUB ==================================================================

	printf(COLOR_TITLE "\n\n---------- STRSUB ----------\n\n" COLOR_RESET);
	printf("Resultat attendu ~ ft_strsub\n");
	printf("(\"Trucmuche\", 4, 3) ==> \"muc\" ~ \"%s\"\n", ft_strsub("Trucmuche", 4, 3));
	printf("(\"Trucmuche\", 1, 5) ==> \"rucmu\" ~ \"%s\"\n", ft_strsub("Trucmuche", 1, 5));
	printf("(\"Trucmuche\", 0, 3) ==> \"Tru\" ~ \"%s\"\n", ft_strsub("Trucmuche", 0, 3));
	printf("(\"Trucmuche\", 0, 9) ==> \"Trucmuche\" ~ \"%s\"\n", ft_strsub("Trucmuche", 0, 9));
	printf("(\"Trucmuche\", 0, 10) ==> \"Trucmuche\" ~ \"%s\"\n", ft_strsub("Trucmuche", 0, 10));
	printf("(\"Trucmuche\", 0, 11) ==> \"Trucmuche\" ~ \"%s\"\n", ft_strsub("Trucmuche", 0, 11));
	printf("(\"Trucmuche\", 0, 15) ==> \"Trucmuche\" ~ \"%s\"\n", ft_strsub("Trucmuche", 0, 15));
	printf("(\"Trucmuche\", 4, 15) ==> \"muche\" ~ \"%s\"\n", ft_strsub("Trucmuche", 4, 15));
	printf("(\"Trucmuche\", 4, 50) ==> \"muche\" ~ \"%s\"\n", ft_strsub("Trucmuche", 4, 50));
	printf("(\"Trucmuche\", 13, 5) ==> ? ~ \"%s\"\n", ft_strsub("Trucmuche", 13, 5));
	printf("(\"Trucmuche\", 1, 0) ==> \"\" ~ \"%s\"\n", ft_strsub("Trucmuche", 1, 0));
	printf("(\"Trucmuche\", 0, 0) ==> \"\" ~ \"%s\"\n", ft_strsub("Trucmuche", 0, 0));
	printf("(\"Trucmuche\", 0, 1) ==> \"T\" ~ \"%s\"\n", ft_strsub("Trucmuche", 0, 1));
	printf("(\"\", 0, 4) ==> \"\" ~ \"%s\"\n", ft_strsub("", 0, 4));
	printf("(\"\", 5, 8) ==> ? ~ \"%s\"\n", ft_strsub("", 5, 8));


// === STRJOIN ==================================================================

	printf(COLOR_TITLE "\n\n---------- STRJOIN ----------\n\n" COLOR_RESET);
	printf("Resultat attendu ~ ft_strjoin\n");
	printf("(\"Hello \", \"les poulets !\") ==> \"Hello les poulets !\" ~ \"%s\"\n", ft_strjoin("Hello ", "les poulets !"));
	printf("(\"\", \"les poulets !\") ==> \"les poulets !\" ~ \"%s\"\n", ft_strjoin("", "les poulets !"));
	printf("(\"Hello \", \"\") ==> \"Hello \" ~ \"%s\"\n", ft_strjoin("Hello ", ""));
	printf("(\"\", \"\") ==> \"\" ~ \"%s\"\n", ft_strjoin("", ""));


// === STRTRIM ==================================================================

	printf(COLOR_TITLE "\n\n---------- STRTRIM ----------\n\n" COLOR_RESET);
	printf("Resultat attendu ~ ft_strtrim\n");
	printf("(\"     Hello   \") ==> \"Hello\" ~ \"%s\"\n", ft_strtrim("     Hello   "));
	printf("(\"     Hello   les poulets !  \") ==> \"Hello   les poulets !\" ~ \"%s\"\n", ft_strtrim("     Hello   les poulets !   "));
	printf("(\"Hello   les poulets !  \") ==> \"Hello   les poulets !\" ~ \"%s\"\n", ft_strtrim("Hello   les poulets !   "));
	printf("(\"     Hello   les poulets !\") ==> \"Hello   les poulets\" ~ \"%s\"\n", ft_strtrim("     Hello   les poulets !"));
	printf("(\"    \") ==> \"\" ~ \"%s\"\n", ft_strtrim("    "));

// === STRSPLIT ================================================================

	printf(COLOR_TITLE "\n\n---------- STRSPLIT ----------\n\n" COLOR_RESET);
	
	char	**tabchar1;

	printf("ft_strsplit(\"  Les   cocos   comment ca va ce soir ? !! je ne sais vraiment pas quoi ecrire pour verifier cette fooooooooooooooooooooooooooooooooonction !!! 6452    8204 -2  \", ' ') :\n");
	tabchar1 = ft_strsplit("  Les   cocos   comment ca va ce soir ? !! je ne sais vraiment pas quoi ecrire pour verifier cette fooooooooooooooooooooooooooooooooonction !!! 6452    8204 -2  ", ' ');
	ft_aff_split(tabchar1);
	ft_free_split(tabchar1);
	
	printf("ft_strsplit(\"  Les   cocos   comment ca va ce soir ? !!  \", 'a') :\n");
	tabchar1 = ft_strsplit("  Les   cocos   comment ca va ce soir ? !!  ", 'a');
	ft_aff_split(tabchar1);
	ft_free_split(tabchar1);
	
	printf("ft_strsplit(\"  Les   cocos   comment ca va ce soir ? !!  \", 'y') :\n");
	tabchar1 = ft_strsplit("  Les   cocos   comment ca va ce soir ? !!  ", 'y');
	ft_aff_split(tabchar1);
	ft_free_split(tabchar1);

	printf("ft_strsplit(\"  Les   cocos   comment ca va ce soir ? !!  \", 0) :\n");
	tabchar1 = ft_strsplit("  Les   cocos   comment ca va ce soir ? !!  ", 0);
	ft_aff_split(tabchar1);
	ft_free_split(tabchar1);

	printf("ft_strsplit(\"yyy\", 'y') :\n");
	tabchar1 = ft_strsplit("yyy", 'y');
	ft_aff_split(tabchar1);
	ft_free_split(tabchar1);

	printf("ft_strsplit(\"\", 'y') :\n");
	tabchar1 = ft_strsplit("", 'y');
	ft_aff_split(tabchar1);
	ft_free_split(tabchar1);
	
	printf("ft_strsplit(\"\", 0) :\n");
	tabchar1 = ft_strsplit("", 0);
	ft_aff_split(tabchar1);
	ft_free_split(tabchar1);
	

// === ITOA ====================================================================

	printf(COLOR_TITLE "\n\n---------- ITOA ----------\n\n" COLOR_RESET);

	printf("Resultat attendu ~ ft_itoa\n");
	printf("0 ~ %s\n", ft_itoa(-0));
	printf("0 ~ %s\n", ft_itoa(0));
	printf("-4 ~ %s\n", ft_itoa(-4));
	printf("4 ~ %s\n", ft_itoa(4));
	printf("-200 ~ %s\n", ft_itoa(-200));
	printf("200 ~ %s\n", ft_itoa(200));
	printf("-4545 ~ %s\n", ft_itoa(-4545));
	printf("4545 ~ %s\n", ft_itoa(4545));
	printf("-2147483648 ~ %s\n", ft_itoa(-2147483648));
	printf("2147483647 ~ %s\n", ft_itoa(2147483647));
	printf("97 ~ %s\n", ft_itoa('a'));
	printf("32 ~ %s\n", ft_itoa(' '));


// === PUTSTR ==================================================================

	printf(COLOR_TITLE "\n\n---------- PUTSTR ----------\n" COLOR_RESET);
	printf("\n");
	ft_putstr(a2);
	printf("\n");
	ft_putstr(b2);
	printf("\n");
	ft_putstr(vide2);
	printf("\n");
	ft_putstr("Hello les cocos\n");


// === PUTENDL==================================================================

	printf(COLOR_TITLE "\n\n---------- PUTENDL ----------\n" COLOR_RESET);
	printf("\n");
	ft_putendl(a2);
	ft_putendl(b2);
	ft_putendl(vide2);
	ft_putendl("Hello les cocos");

// === PUTNBR ==================================================================

	printf(COLOR_TITLE "\n\n---------- PUTNBR ----------\n" COLOR_RESET);
	
	printf("\n");
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(-0);
	ft_putchar('\n');
	ft_putnbr(2);
	ft_putchar('\n');
	ft_putnbr(-2);
	ft_putchar('\n');
	ft_putnbr(12);
	ft_putchar('\n');
	ft_putnbr(-12);
	ft_putchar('\n');
	ft_putnbr(1240);
	ft_putchar('\n');
	ft_putnbr(-1240);
	ft_putchar('\n');
	ft_putnbr(124047);
	ft_putchar('\n');
	ft_putnbr(-124047);
	ft_putchar('\n');
	ft_putnbr(2147483647);
	ft_putchar('\n');
	ft_putnbr(-2147483648);
	ft_putchar('\n');


// === PUTNBR_FD ===============================================================

	printf(COLOR_TITLE "\n\n---------- PUTNBR_FD ----------\n" COLOR_RESET);
	
	printf("\nTest sur le sortie standard, fd = 1 : \n\n");
	ft_putnbr_fd(0, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-0, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(2, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-2, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(12, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-12, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(1240, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-1240, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(124047, 1);
	ft_putchar_fd('\n', 1);
	ft_putnbr_fd(-124047, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putstr_fd("\n", 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putstr_fd("\n", 1);





// *****************************************************************************
// ******************************* PARTIE BONUS ********************************
// *****************************************************************************

printf(COLOR_BIG_TITLE "\n\n\n*****************************************************************************\n");
printf("******************************* PARTIE BONUS ********************************\n");
printf("*****************************************************************************\n" COLOR_RESET);


// === LSTNEW ==================================================================

	printf(COLOR_TITLE "\n\n---------- LSTNEW ----------\n\n" COLOR_RESET);

	t_list	*list1;

	list1 = ft_lstnew("TEST", sizeof("TEST"));
	printf("(\"TEST\", sizeof(\"TEST\")) :\n");
	ft_aff_list(list1);
	printf("\n");
	free(list1);

	list1 = ft_lstnew("TEST", 0);
	printf("(\"TEST\", 0) :\n");
	ft_aff_list(list1);
	printf("\n");
	free(list1);
	
	list1 = ft_lstnew("TEST", 3);
	printf("(\"TEST\", 3) :\n");
	ft_aff_list(list1);
	printf("\n");
	free(list1);
	
	list1 = ft_lstnew("", sizeof("TEST"));
	printf("(\"\", sizeof(\"TEST\")) :\n");
	ft_aff_list(list1);
	printf("\n");
	free(list1);

	list1 = ft_lstnew(NULL, sizeof("TEST"));
	printf("(NULL, sizeof(\"TEST\")) :\n");
	ft_aff_list(list1);
	printf("\n");
	free(list1);


// === LSTADD ==================================================================

	printf(COLOR_TITLE "\n\n---------- LSTADD ----------\n\n" COLOR_RESET);

	t_list	*list2;

	list1 = ft_lstnew("TEST", sizeof("TEST"));
	ft_lstadd(&list1, ft_lstnew("TEST0", sizeof("TEST0")));
	ft_lstadd(&list1, ft_lstnew("TEST1", sizeof("TEST1")));
	ft_lstadd(&list1, ft_lstnew("TEST2", sizeof("TEST2")));
	ft_lstadd(&list1, ft_lstnew("TEST3", sizeof("TEST3")));
	ft_aff_list(list1);
	printf("\n");

	list2 = NULL;	
	ft_lstadd(&list2, ft_lstnew("TEST0", sizeof("TEST0")));
	ft_lstadd(NULL, ft_lstnew("TEST", sizeof("TEST"))); //test protection
	ft_lstadd(&list2, ft_lstnew(NULL, sizeof("TEST")));
	ft_lstadd(&list2, ft_lstnew("TEST2", sizeof("TEST2")));
	ft_aff_list(list2);


// === LSTDELONE ===============================================================

	printf(COLOR_TITLE "\n\n---------- LSTDELONE ----------\n\n" COLOR_RESET);
	t_list		*supp;

	supp = list1->next;	
	ft_lstdelone(&supp, &ft_del_lst);
	ft_aff_list(list1);


// === LSTDEL ==================================================================

	printf(COLOR_TITLE "\n\n---------- LSTDEL ----------\n\n" COLOR_RESET);
	
	printf("AVANT :\n");
	ft_aff_list(list2);
	ft_lstdel(&list2, &ft_del_lst);
	
	printf("\nAPRES :\n");
	ft_aff_list(list2);


// === LSTITER =================================================================

	printf(COLOR_TITLE "\n\n---------- LSTITER ----------\n\n" COLOR_RESET);

	t_list		*list3;

	list3 = NULL;
	ft_lstadd(&list3, ft_lstnew("cocos", sizeof("cocos")));
	ft_lstadd(&list3, ft_lstnew("les", sizeof("les")));
	ft_lstadd(&list3, ft_lstnew("hello", sizeof("hello")));

	printf("AVANT :\n");
	ft_aff_list(list3);
	ft_lstiter(list3, &ft_test_lstiter);

	printf("\nAPRES : Met tous les content_size à 42\n");
	ft_aff_list(list3);
	
// === LSTMAP ==================================================================

	printf(COLOR_TITLE "\n\n---------- LSTMAP ----------\n\n" COLOR_RESET);
	
	printf("AVANT :\n");
	ft_aff_list(list3);
	ft_lstmap(list3, &ft_test_lstmap);

	printf("\nAPRES : Met tous les content à \"ecole42\" et retourne la liste\n");
	ft_aff_list(list3);


// *****************************************************************************
// ******************************* FCTs FACULTATIVES ***************************
// *****************************************************************************

printf(COLOR_BIG_TITLE "\n\n\n*****************************************************************************\n");
printf("***************************** FCTs FACULTATIVES *****************************\n");
printf("*****************************************************************************\n" COLOR_RESET);

// === COUNTWORDS ==============================================================

	printf(COLOR_TITLE "\n\n---------- COUNTWORDS ----------\n\n" COLOR_RESET);
	printf("Rslt attendu ~ ft_countwords :\n");
	printf("(\"hello\", ' ' => 1 ~ %d\n", ft_countwords("hello", ' '));
	printf("\"   Hello les   cocos  \", ' ' => 3 ~ %d\n", ft_countwords("   Hello les   cocos  ", ' '));
	printf("\"hello test hello youpppi\", ' ' => 4 ~ %d\n", ft_countwords("hello test hello youpppi", ' '));
	printf("\"hello test hello youpppi\", 'e' => 4 ~ %d\n", ft_countwords("hello test hello youpppi", 'e'));
	printf("\"hello test hello youpppi\", 'y' => 2 ~ %d\n", ft_countwords("hello test hello youpppi", 'y'));
	printf("\"hello test hello youpppi\", '!' => 1 ~ %d\n", ft_countwords("hello test hello youpppi", '!'));
	printf("\"\", ' ' => 0 ~ %d\n", ft_countwords("", ' '));
	printf("NULL, ' ' => 0 ~ %d\n", ft_countwords(NULL, ' '));

	
// === INTLEN ==================================================================

	printf(COLOR_TITLE "\n\n---------- INTLEN ----------\n\n" COLOR_RESET);
	printf("Rslt attendu ~ ft_intlen :\n");
	printf("0 => 1 ~ %d\n", ft_intlen(0));
	printf("-0 => 1 ~ %d\n", ft_intlen(-0));
	printf("3 => 1 ~ %d\n", ft_intlen(3));
	printf("-3 => 2 ~ %d\n", ft_intlen(-3));
	printf("42 => 2 ~ %d\n", ft_intlen(42));
	printf("-42 => 3 ~ %d\n", ft_intlen(-42));
	printf("123 => 3 ~ %d\n", ft_intlen(123));
	printf("-123 => 4 ~ %d\n", ft_intlen(-123));
	printf("84700 => 5 ~ %d\n", ft_intlen(84700));
	printf("-84700 => 6 ~ %d\n", ft_intlen(-84700));
	printf("10084700 => 8 ~ %d\n", ft_intlen(10084700));
	printf("-10084700 => 9 ~ %d\n", ft_intlen(-10084700));
	printf("2147483647 => 10 ~ %d\n", ft_intlen(2147483647));
	printf("-2147483647 => 11 ~ %d\n", ft_intlen(-2147483648));


// === LSTLEN ==================================================================

	printf(COLOR_TITLE "\n\n---------- LSTLEN ----------\n\n" COLOR_RESET);

	t_list		*list4;
	t_list		*list5;

	printf("list3 :\n");
	ft_aff_list(list3);
	printf("longueur = %d\n\n", ft_lstlen(list3));

	list4 = NULL;
	printf("list4 = NULL :\n");
	ft_aff_list(list4);
	printf("longueur = %d\n\n", ft_lstlen(list4));

	list5 = ft_lstnew("Yeah", sizeof("Yeah"));
	printf("list5 :\n");
	ft_aff_list(list5);
	printf("longueur = %d\n\n", ft_lstlen(list5));

// === LSTADD_BACK =============================================================

	printf(COLOR_TITLE "\n\n---------- LSTADD_BACK ----------\n\n" COLOR_RESET);
	
	printf("Ajout sur list4 = NULL :\n");
	ft_lstadd_back(&list4, ft_lstnew("Poulette", sizeof("Poulette")));
	ft_aff_list(list4);
	printf("\n");

	printf("Ajout sur list3\n");
	printf("AVANT :\n");
	ft_aff_list(list3);
	printf("APRES :\n");
	ft_lstadd_back(&list3, ft_lstnew("Poulet", sizeof("Poulet")));
	ft_aff_list(list3);
	
// === LSTLAST =================================================================

	printf(COLOR_TITLE "\n\n---------- LSTALAST ----------\n\n" COLOR_RESET);

	t_list	*last;

	last = NULL;
	printf("Retour du dernier élément de list3\n");
	printf("list3 =\n");
	ft_aff_list(list3);
	last = ft_lstlast(list3);
	printf("Dernier élément :\n");
	printf("content = %s, content_size = %zu\n\n", last->content, last->content_size);

	printf("Retour du dernier élément de list4\n");
	printf("list4 =\n");
	ft_aff_list(list4);
	last = ft_lstlast(list4);
	printf("Dernier élément :\n");
	printf("content = %s, content_size = %zu\n\n", last->content, last->content_size);

	printf("Retour du dernier élément d'une liste NULL\n");
	last = ft_lstlast(NULL);
	printf("Dernier élément :\n");
	if (last)
		printf("content = %s, content_size = %zu\n", last->content, last->content_size);
	
// === LSTAT ===================================================================

	printf(COLOR_TITLE "\n\n---------- LSTAT ----------\n\n" COLOR_RESET);

	t_list	*list6;

	list6 = NULL;
	printf("Retour du 0ème élément de list6 = NULL :\n");
	last = ft_lstat(list6, 0);
	printf("Resultat:\n");
	if (last)
		printf("content = %s, content_size = %zu\n\n", last->content, last->content_size);
	printf("\n");
	
	printf("Retour du 5ème élément de list6 = NULL :\n");
	last = ft_lstat(list6, 5);
	printf("Resultat:\n");
	if (last)
		printf("content = %s, content_size = %zu\n\n", last->content, last->content_size);
	printf("\n");

	ft_lstadd_back(&list6, ft_lstnew("Truc.fin", sizeof("Truc.fin")));
	printf("Retour du premier élément (=0ème) de list6\n");
	printf("list6 = \n");
	ft_aff_list(list6);
	printf("le 0ème élément :\n");
	last = ft_lstat(list6, 0);
	printf("content = %s, content_size = %zu\n\n", last->content, last->content_size);

	printf("Retour d'un élément out de list6\n");
	printf("list6 = \n");
	ft_aff_list(list6);
	printf("le 1er élément :\n");
	last = ft_lstat(list6, 1);
	printf("content = %s, content_size = %zu\n\n", last->content, last->content_size);

	ft_lstadd(&list6, ft_lstnew("Truc.2", sizeof("Truc.2")));
	ft_lstadd(&list6, ft_lstnew("Truc.1", sizeof("Truc.1")));
	ft_lstadd(&list6, ft_lstnew("Truc.0", sizeof("Truc.0")));
	printf("Retour du dernier élément (=3ème) de list6\n");
	printf("list6 = \n");
	ft_aff_list(list6);
	printf("le 3ème élément :\n");
	last = ft_lstat(list6, 3);
	printf("content = %s, content_size = %zu\n\n", last->content, last->content_size);


	printf("Retour du premier élément (=0ème) de list6\n");
	printf("list6 = \n");
	ft_aff_list(list6);
	printf("le 0ème élément :\n");
	last = ft_lstat(list6, 0);
	printf("content = %s, content_size = %zu\n\n", last->content, last->content_size);

	printf("Retour du deuxieme élément (=1er) de list6\n");
	printf("list6 = \n");
	ft_aff_list(list6);
	printf("le 1er élément :\n");
	last = ft_lstat(list6, 1);
	printf("content = %s, content_size = %zu\n\n", last->content, last->content_size);

	printf("Retour d'un élément out de list6\n");
	printf("list6 = \n");
	ft_aff_list(list6);
	printf("le 6ème élément :\n");
	last = ft_lstat(list6, 6);
	printf("content = %s, content_size = %zu\n\n", last->content, last->content_size);
	return (0);
}
