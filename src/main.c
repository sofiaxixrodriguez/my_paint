/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** main
*/

#include "../include/my.h"

void destroy_all(var_t m)
{
    sfRenderWindow_destroy(WDW);
    sfCircleShape_destroy(SHAPE(circle));
    sfRectangleShape_destroy(SHAPE(rect));
    sfRenderTexture_destroy(T_DRAW);
    sfSprite_destroy(S_DRAW);
    sfSprite_destroy(GUI);
    sfFont_destroy(m->gui->font);
    sfText_destroy(m->gui->buttons->save_text);
    sfSprite_destroy(C_BUCKET);

}

int main(int ac, char **av, char **env)
{
    var_t m = malloc(sizeof(my_var_t));

    CHECK_MALLOC(m);
    CHECK_ERROR_MAIN(error_handling(ac, av, env));
    if (ac == 2)
        return SUCCESS;
    CHECK_ERROR_MAIN(init_all(m));
    window_loop(m);
    destroy_all(m);
    my_free_all();
    return 0;
}
