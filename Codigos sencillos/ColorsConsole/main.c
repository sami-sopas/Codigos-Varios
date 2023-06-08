#include <stdio.h>
#include <stdlib.h>

/// Todos los colores que hay para cambiar un printf en especifico
#define NEGROBAJITO "\x1b[1;30m"
#define NEGROFUERTE "\x1b[0;30m"
#define NEGROFONDO "\x1b[1;30;40m"

#define ROJOBAJITO "\x1b[1;31m"
#define ROJOFUERTE "\x1b[0;31m"
#define ROJOFONDO "\x1b[1;31;41m"

#define VERDEBAJITO "\x1b[1;32m"
#define VERDEFUERTE "\x1b[0;32m"
#define VERDEFONDO "\x1b[1;32;42m"

#define AMARILLOBAJITO "\x1b[1;33m"
#define AMARILLOFUERTE "\x1b[0;33m"
#define AMARILLOFONDO "\x1b[1;33;43m"

#define AZULREYBAJITO "\x1b[1;34m"
#define AZULREYFUERTE "\x1b[0;34m"
#define AZULREYFONDO "\x1b[1;34;44m"

#define MORADOBAJITO "\x1b[1;35m"
#define MORADOFUERTE "\x1b[0;35m"
#define MORADOFONDO "\x1b[1;35;45m"

#define AQUABAJITO "\x1b[1;36m"
#define AQUAFUERTE "\x1b[0;36m"
#define AQUAFONDO "\x1b[1;36;46m"

#define GRISBAJITO "\x1b[1;37m"
#define GRISFUERTE "\x1b[0;37m"
#define GRISFONDE "\x1b[1;37;47m"


/// Para regresar al color origial
#define REGRESA "\x1b[0m"


/// Los pasos para usarlo son simples
/// 1.- Ubicar el codigo que quieres que coloque en color
/// 2.- Colocar un printf y llamar al define con el color que quieres
/// 3.- Cuando ya no quieras que se imprima asi de ese color
/// usa el REGRESA
/// 4.- Algunas computadoras imprimiran algo raro
/// para eso, usar el system(cls)


int main() {
    system("cls");
    system("Title Los colores en C");
    printf(NEGROBAJITO);
    printf("Hola soy negro bajito\n");
    printf(REGRESA);
    printf(NEGROFUERTE);
    printf("Hola soy negro fuerte\n");
    printf(REGRESA);
    printf(NEGROFONDO);
    printf("Hola soy negro de fondo\n");
    printf(REGRESA);

    printf("\n---------------------------------\n");

    printf(ROJOBAJITO);
    printf("Hola soy rojo bajito\n");
    printf(REGRESA);
    printf(ROJOFUERTE);
    printf("Hola soy soy fuerte\n");
    printf(REGRESA);
    printf(ROJOFONDO);
    printf("Hola soy rojo de fondo\n");
    printf(REGRESA);

    printf("\n---------------------------------\n");

    printf(VERDEBAJITO);
    printf("Hola soy verde bajito\n");
    printf(REGRESA);
    printf(VERDEFUERTE);
    printf("Hola soy verde fuerte\n");
    printf(REGRESA);
    printf(VERDEFONDO);
    printf("Hola soy verde de fondo\n");
    printf(REGRESA);

    printf("\n---------------------------------\n");

    printf(AMARILLOBAJITO);
    printf("Hola soy amarillo bajito\n");
    printf(REGRESA);
    printf(AMARILLOFUERTE);
    printf("Hola soy amarillo fuerte\n");
    printf(REGRESA);
    printf(AMARILLOFONDO);
    printf("Hola soy amarillo de fondo\n");
    printf(REGRESA);

    printf("\n---------------------------------\n");

    printf(AZULREYBAJITO);
    printf("Hola soy azul bajito\n");
    printf(REGRESA);
    printf(AZULREYFUERTE);
    printf("Hola soy azul fuerte\n");
    printf(REGRESA);
    printf(AZULREYFONDO);
    printf("Hola soy azul de fondo\n");
    printf(REGRESA);

    printf("\n---------------------------------\n");

    printf(MORADOBAJITO);
    printf("Hola soy morado bajito\n");
    printf(REGRESA);
    printf(MORADOFUERTE);
    printf("Hola soy  morado fuerte\n");
    printf(REGRESA);
    printf(MORADOFONDO);
    printf("Hola soy morado de fondo\n");
    printf(REGRESA);

    printf("\n---------------------------------\n");

    printf(AQUABAJITO);
    printf("Hola soy aqua bajito\n");
    printf(REGRESA);
    printf(AQUAFUERTE);
    printf("Hola soy aqua fuerte\n");
    printf(REGRESA);
    printf(AQUAFONDO);
    printf("Hola soy aqua de fondo\n");
    printf(REGRESA);

    printf("\n---------------------------------\n");

    printf(GRISBAJITO);
    printf("Hola soy gris bajito\n");
    printf(REGRESA);
    printf(GRISFUERTE);
    printf("Hola soy  gris fuerte\n");
    printf(REGRESA);
    printf(GRISFONDE);
    printf("Hola soy gris de fondo\n");
    printf(REGRESA);

    getch();
    return 0;
}
