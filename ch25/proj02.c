#include <stdio.h>
#include <locale.h>
#include <assert.h>

int digitize(char *str);

int main(int argc, char **argv)
{
struct lconv *loc;

assert(argc == 2);
setlocale(LC_ALL, argv[1]);
loc = localeconv();

printf("decimal_point      = \"%s\"\n", loc->decimal_point);
printf("thousands_sep      = \"%s\"\n", loc->thousands_sep);
printf("grouping           = %d\n",     digitize(loc->grouping));
printf("mon_decimal_point  = \"%s\"\n", loc->mon_decimal_point);
printf("mon_thousands_sep  = \"%s\"\n", loc->mon_thousands_sep);
printf("mon_grouping       = %d\n",     digitize(loc->grouping));
printf("positive_sign      = \"%s\"\n", loc->positive_sign);
printf("negative_sign      = \"%s\"\n", loc->negative_sign);
printf("currency_symbol    = \"%s\"\n", loc->currency_symbol);
printf("frac_digits        = %d\n",     loc->frac_digits);
printf("p_cs_precedes      = %d\n",     loc->p_cs_precedes);
printf("n_cs_precedes      = %d\n",     loc->n_cs_precedes);
printf("p_sep_by_space     = %d\n",     loc->p_sep_by_space);
printf("n_sep_by_space     = %d\n",     loc->n_sep_by_space);
printf("p_sign_posn        = %d\n",     loc->p_sign_posn);
printf("n_sign_posn        = %d\n",     loc->n_sign_posn);
printf("int_curr_symbol    = \"%s\"\n", loc->int_curr_symbol);
printf("int_frac_digits    = %d\n",     loc->int_frac_digits);
printf("int_p_cs_precedes  = %d\n",     loc->int_p_cs_precedes);
printf("int_n_cs_precedes  = %d\n",     loc->int_n_cs_precedes);
printf("int_p_sep_by_space = %d\n",     loc->int_p_sep_by_space);
printf("int_n_sep_by_space = %d\n",     loc->int_n_sep_by_space);
printf("int_p_sign_posn    = %d\n",     loc->int_p_sign_posn);
printf("int_n_sign_posn    = %d\n",     loc->int_n_sign_posn);
}

int digitize (char *str) {
  int result = 0;
  while (*str != '\0' && *str < 10) {
    result += result * 10 + *str;
    str++;
  }
  return result;
}
