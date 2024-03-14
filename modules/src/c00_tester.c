void    ex00_test(void)
{
    int case_no = 1;
    char ex01_char = 'a';

    printf("case%d: \'a\'\n", caseNo);
    printf("expected output -> ");
    putchar(ex01_char);
    printf("\nyour output -> ");
    ft_putchar(ex01_char);
    ex01_char = '0';
    printf("expected output -> ");
    putchar(ex01_char);
    printf("\nyour output -> ");
    ft_putchar(ex01_char);
    ex01_char = '\n';
    printf("expected output -> ");
    putchar(ex01_char);
    printf("\nyour output -> ");
    ft_putchar(ex01_char);
    ex01_char = '';
    printf("expected output -> ");
    putchar(ex01_char);
    printf("\nyour output -> ");
    ft_putchar(ex01_char);
    ex01_char = '\x04';
    printf("expected output -> ");
    putchar(ex01_char);
    printf("\nyour output -> ");
    ft_putchar(ex01_char);
}

int main()
{
    ex00_test();
    ex01_test();
    ex02_test();
    ex03_test();
    ex04_test();
    ex05_test();
    ex06_test();
    ex07_test();
    ex08_test();
}