/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include "includes.h"
    #include "struct.h"

    void my_putchar (char c);
    int my_put_nbr(int nbr);
    int my_putstr(char const *str);
    char **str_to_w_array(char *str, char c);
    int my_printf(const char *format, ...);
    int my_strlen ( char *str );
    int my_str_cmp ( char *str1, char *str2);
    int printenv ( char **env );
    void terminal ( term_t *term, char **env );
    char *my_strcat(char *dest, char *src);
    char *bin_str_paste (char *str);
    char *my_cut_startstr ( char *strtocut, char *str );
    char **envcpy (char **env);
    char* getpath ( char **env );
    int pathenv(term_t *term, char **tab, char *str);
    char *cutspace (char *str);
    int conditions_input (term_t *term, char **env, char **tab, char *str);
    int cd_function (term_t *term, char **env, const char *str);
    int my_str_cmp ( char *str1, char *str2);
    int my_strn_cmp ( char *str1, char *str2, int n);
    int cd_dash (char **env);
    int cd_tilde (char **env);
    char *get_home_dir (char **env);
    char *get_pastehome_dir (void);
    char *get_home_path ( char **env );
    int compteur ( char **env );
    char *get_old_pwd ( char **env );
    void remove_after_space(char *str);
    int strcmp_custom (const char* str1, const char* str2);
    int pathenv2(char **env, char **tab, char *str);
    int normal_not_found (char *slashfinal);
    int segfault_handling (int status, char *command);
    void init_struct(term_t *term);
    char **set_env(char *setenv_str, char *str, term_t *term);
    int conditions_input2 (term_t *term,char **env, char **tab, char *str);
    int good_args_setenv (char *str);
    void remove_after_space(char *str);
    char **copy_env (char **env);
    int my_tab_strlen(char **tab);
    char *my_strcat_custom (char *dest, char *src1, char *src2);
    char *replace_space_egal (char *str);
    char **add_env(char *envcmd, char **env);
    void if_not_exist (term_t *term, char *envcmd, int exists);
    char **unset_env (char *str, term_t *term);
    int pathenv_handling(char *strnospace, term_t *term, char **tab, char *str);

#endif /* !MY_H_ */
