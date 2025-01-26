#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "matriz_leds.h"

#define tempo_frame 200

// RGB_cod cor1 = obter_cor_por_parametro_RGB(0,0,0);

void animacao(PIO pio, uint sm){
    Matriz_leds_config matriz = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    imprimir_desenho(matriz, pio, sm);//animacao joaoeman
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz2, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz3, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz4, pio, sm);
    sleep_ms(tempo_frame);
    imprimir_desenho(matriz5, pio, sm);
    sleep_ms(tempo_frame);
}

void animacao_b(PIO pio, uint sm){
    Matriz_leds_config matriz_b = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 0
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 1
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 2
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 3
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 4
    };
    Matriz_leds_config matriz_b2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_b3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_b4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 1.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.5, 0.5, 0.0}, {0.0, 0.0, 1.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 1.0}, {0.5, 0.5, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 1.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_b5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}}, // Linha 0
        {{0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 1.0}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}}, // Linha 1
        {{0.5, 0.5, 0.0}, {0.0, 0.0, 1.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 1.0}, {0.5, 0.5, 0.0}}, // Linha 2
        {{0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 0.0, 1.0}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}}, // Linha 3
        {{0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, {0.5, 0.5, 0.0}, {0.0, 1.0, 0.0}, {0.0, 1.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config *matrizes_b[] = {
        &matriz_b, &matriz_b2, &matriz_b3, &matriz_b4, &matriz_b57
    }; // Colocando as matrizes na array

    int num_matrizes_b = sizeof(matrizes_b) / sizeof(matrizes_b[0]); // Número de matrizes

    for (int i = 0; i < num_matrizes_b; i++) {
        imprimir_desenho(*matrizes_b[i], pio, sm); // Passa cada matriz por referência
        sleep_ms(tempo_frame);
    }
}

void animacao_c(PIO pio, uint sm){
    Matriz_leds_config matriz_c = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 2
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 3
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_c2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 2
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 3
        {{0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_c3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 2
        {{0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 4
    };
    Matriz_leds_config matriz_c4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 3
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 4
    };
    Matriz_leds_config matriz_c5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 2
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 3
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 4
    };
    Matriz_leds_config matriz_c6 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 1
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 2
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 3
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 4
    };
    Matriz_leds_config matriz_c7 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 0
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 1
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 2
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 3
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 4
    };
    Matriz_leds_config matriz_c8 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 0
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 1
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 2
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 3
        {{0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}}, // Linha 4
    };
    Matriz_leds_config matriz_c9 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 0
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 1
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 2
        {{0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}}, // Linha 3
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_c10 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 0
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 1
        {{0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}}, // Linha 2
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 3
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_c11 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}, {0.0, 0.0, 0.5}}, // Linha 0
        {{0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}}, // Linha 1
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 2
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 3
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_c12 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.5}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.0, 0.0, 0.5}}, // Linha 0
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 1
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 2
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 3
        {{0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}, {0.5, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config *matrizes_c[] = {
        &matriz_c, &matriz_c2, &matriz_c3, &matriz_c4, &matriz_c5, &matriz_c6,
        &matriz_c7, &matriz_c8, &matriz_c9, &matriz_c10, &matriz_c11, &matriz_c12
    }; // Colocando as matrizes na array

    int num_matrizes_c = sizeof(matrizes_c) / sizeof(matrizes_c[0]); // Número de matrizes

    for (int i = 0; i < num_matrizes_c; i++) {
        imprimir_desenho(*matrizes_c[i], pio, sm); // Passa cada matriz por referência
        sleep_ms(tempo_frame);
    }
}

void animacao_d(PIO pio, uint sm){
    Matriz_leds_config matriz_d = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_d2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_d3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_d4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}}, // Linha 4
    };
    Matriz_leds_config matriz_d5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.3, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.0, 0.3}}, // Linha 4
    };

    Matriz_leds_config *matrizes_d[] = {
        &matriz_d, &matriz_d2, &matriz_d3, &matriz_d4, &matriz_d5
    }; // Colocando as matrizes na array

    int num_matrizes_d = sizeof(matrizes_d) / sizeof(matrizes_d[0]); // Número de matrizes

    for (int i = 0; i < num_matrizes_d; i++) {
        imprimir_desenho(*matrizes_d[i], pio, sm); // Passa cada matriz por referência
        sleep_ms(tempo_frame);
    }
}

void jogo_da_cobrinha(PIO pio, uint sm)
{
    Matriz_leds_config frame1 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame2 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame3 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame4 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame5 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame6 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame7 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame8 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.3}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame9 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame10 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 4
    };

    Matriz_leds_config frame11 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 4
    };

    Matriz_leds_config frame12 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame13 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 4
    };

    Matriz_leds_config frame14 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 4
    };

    Matriz_leds_config frame15 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 0
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.3}}, // Linha 1
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 2
        {{0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}}, // Linha 3
        {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}, {0.3, 0.3, 0.3}}, // Linha 4
    };

    Matriz_leds_config *frames[] = {&frame1, &frame2, &frame3, &frame4, &frame5, &frame6, &frame7, &frame8, &frame9, &frame10, &frame11, &frame12, &frame13, &frame14, &frame15};
    int num_frames = sizeof(frames) / sizeof(frames[0]);

    for (int i = 0; i < num_frames; i++)
    {
        imprimir_desenho(*frames[i], pio, sm);
        sleep_ms(tempo_frame * 2);
    }
}

void tecla_C(PIO pio, uint sm)
{
    Matriz_leds_config frame1 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}}, // Linha 0
        {{0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}}, // Linha 1
        {{0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}}, // Linha 2
        {{0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}}, // Linha 3
        {{0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}, {0.8, 0.0, 0.0}}, // Linha 4
    };

    imprimir_desenho(frame1, pio, sm);
    sleep_ms(tempo_frame);
}

void tecla_D(PIO pio, uint sm)
{
    Matriz_leds_config frame1 = {
        //   Coluna 0         Coluna 1         Coluna 2         Coluna 3         Coluna 4
        // R    G    B      R    G    B      R    G    B      R    G    B      R    G    B
        {{0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}}, // Linha 0
        {{0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}}, // Linha 1
        {{0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}}, // Linha 2
        {{0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}}, // Linha 3
        {{0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}, {0.0, 0.5, 0.0}}, // Linha 4
    };

    imprimir_desenho(frame1, pio, sm);
    sleep_ms(tempo_frame);
}

int main()
{
    PIO pio = pio0;
    uint sm = configurar_matriz(pio);
    while (true)
    {
        //animacao(pio, sm);//animacao joaoeman

        //animacao_b(pio, sm); //Animação EnzoLisboa
        //animacao_c(pio, sm); //Animação EnzoLisboa2
        //animacao_d(pio, sm); //Animação EnzoLisboa3

        // jogo_da_cobrinha(pio, sm); // Animação Leonardo
        // tecla_C(pio, sm); // Tarefa Leonardo
        // tecla_D(pio, sm); // Tarefa Leonardo
    }
}
