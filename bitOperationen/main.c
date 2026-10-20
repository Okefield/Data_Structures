#include <stdio.h>
#include <stdint.h>

void print_bits(uint16_t val) {
    for (int i = 15; i >= 0; i--) {
        printf("%d", (val >> i) & 1);
        if (i == 8) {
            printf(" ");
        }
    }
}


void print_menu(uint16_t *option) {
    printf(" 1  A eingeben (Hex)\n");
    printf(" 2  B eingeben (Hex)\n");
    printf(" 3  A = A + B\n");
    printf(" 4  A = A UND B\n");
    printf(" 5  A = A ODER B\n");
    printf(" 6  A = A XOR B\n");
    printf(" 7  A = NICHT A\n");
    printf(" 8  A um B Stellen nach links schieben\n");
    printf(" 9  A um B Stellen nach rechts schieben\n");
    printf("10  Ein Bit in A setzen\n");
    printf("11  Ein Bit in A loeschen\n");
    printf("12  Ein Bit in A umschalten\n");
    printf("13  Ein Bit in A pruefen\n");
    printf(" 0  Ende\n");
    printf("Ihre Wahl: ");
    scanf("%d", option);
}

void print_status(uint16_t a, uint16_t b) {
    printf("========================================\n");
    printf("A  Hex:  %04X\n", a);
    printf("   Bits: ");
    print_bits(a);
    printf("\n");

    printf("B  Hex:  %04X\n", b);
    printf("   Bits: ");
    print_bits(b);
    printf("\n");
    printf("========================================\n");
}

int main(void) {
    uint16_t a = 0;
    uint16_t b = 0;
    uint16_t option = 0;
    uint16_t bit_pos = 0;
    uint16_t temp_hex = 0;


    do {
        uint8_t showResult = 0;

        print_status(a, b);
        print_menu(&option);

        switch (option) {
            case 1:
                printf("Wert fuer A (Hex, max. 4 Stellen): ");
                scanf("%hx", &a);

                break;
            case 2:
                printf("Wert fuer B (Hex, max. 4 Stellen): ");
                scanf("%hx", &b);

                break;
            case 3:
                a = (uint16_t)(a + b);
                showResult = 1;
                break;
            case 4:
                a = a & b;
                showResult = 1;
                break;
            case 5:
                a = a | b;
                showResult = 1;
                break;
            case 6:
                a = a ^ b;
                showResult = 1;
                break;
            case 7:
                a = (uint16_t)(~a);
                showResult = 1;
                break;
            case 8:
                a = (uint16_t)(a << b);
                showResult = 1;
                break;
            case 9:
                a = a >> b;
                showResult = 1;
                break;
            case 10:
                printf("Welches Bit in A setzen (0-15)? ");
                scanf("%d", &bit_pos);
                if (bit_pos >= 0 && bit_pos <= 15) {
                    a |= (1U << bit_pos);
                }
                break;
            case 11:
                printf("Welches Bit in A loeschen (0-15)? ");
                scanf("%d", &bit_pos);
                if (bit_pos >= 0 && bit_pos <= 15) {
                    a &= ~(1U << bit_pos);
                }
                break;
            case 12:
                printf("Welches Bit in A umschalten (0-15)? ");
                scanf("%d", &bit_pos);
                if (bit_pos >= 0 && bit_pos <= 15) {
                    a ^= (1U << bit_pos);
                }
                break;
            case 13:
                printf("Welches Bit in A pruefen (0-15)? ");
                scanf("%d", &bit_pos);
                if (bit_pos >= 0 && bit_pos <= 15) {
                    int bit_val = (a >> bit_pos) & 1;
                    printf(">> Bit %d ist %d <<\n", bit_pos, bit_val);
                    printf("Druecken Sie Enter zum Fortfahren...");
                    getchar();
                    getchar();

                }
                break;
            case 0:
                printf("Programm wird beendet...\n");
                break;
            default:
                printf("Ungueltige Option!\n");
                break;

        }
        if (showResult) {
            printf("Ergebnis: %4hx\n", a);
            printf("Druecken Sie Enter zum Fortfahren...");
            getchar();
            getchar();
        }


    } while (option != 0);

    return 0;
}