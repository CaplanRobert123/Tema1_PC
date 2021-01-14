// Tema1_PC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

    unsigned int masca(int nr) { // transforma MSK_2 intr-un numar in baza 10 int x = 0; for(int i=0;i<=31;i++) { if(i<nr) x= x|(1<<(31-i)); else x=x|(0<<(31-i)); } return x; }

        void TASK_0(int IP_1a, int IP_1b, int IP_1c, int IP_1d, int MSK_2) {
            printf("-0 "); printf("%d.%d.%d.%d/%d\n", IP_1a, IP_1b, IP_1c, IP_1d, MSK_2); 
        }

        void TASK_1(int MSK_2) {
            printf("-1 "); 
            unsigned int x = 0; 
            for (int i = 0; i <= 31; i++) { 
                if (i < MSK_2) {
                    x = x | (1 << (31 - i));
                } 
                else {
                    x = x | (0 << (31 - i));
                }
                if ((i + 1) % 8 == 0) {
                    x = x >> ((i + 1) * 3);
                    if (i < 31) {
                        printf("%u.", x);
                    }
                    else {
                        printf("%u\n", x); x = 0;
                    }
                } 
            } 
        }

        void TASK_2(int MSK_1a, int MSK_1b, int MSK_1c, int MSK_1d) {
            printf("-2 "); 
            printf("%o.%o.%o.%o ", MSK_1a, MSK_1b, MSK_1c, MSK_1d); 
            printf("%X.%X.%X.%X\n", MSK_1a, MSK_1b, MSK_1c, MSK_1d); 
        }

        void TASK_3(int ip, int MSK_2) {
            int b; 
            unsigned int z = 0;
            int msc = masca(MSK_2); 
            printf("-3 "); 
            for (int i = 0; i <= 31; i++) {
                b = (ip & (1 << (31 - i))) ? 1 : 0;
                if (i > MSK_2) b = 0; 
                int y = (msc & (1 << (31 - i))) ? 1 : 0;
                b = b & y;
                z = z | (b << (31 - i));
                if ((i + 1) % 8 == 0) {
                    z = z >> ((i + 1) * 3);
                    if (i < 31) {
                        printf("%u.", z);
                    }
                    else {
                        printf("%u\n", z); z = 0;
                    }
                }
            } 
        }

        void TASK_4(int ip, int MSK_2) {
            int b;
            unsigned int z = 0; 
            int msc = masca(MSK_2); // ca la TASK_3 doar ca
            printf("-4 "); 
            for (int i=0;i<=31;i++) { 
                msc = msc^(1<<(31-i)); //fac aici complementul mastii 
                b=(ip&(1<<(31-i))) ? 1 : 0; 
                if (i > MSK_2) {
                    b = 0;
                }
                int y = (msc&(1<<(31-i))) ? 1 : 0;
                b = b | y; 
                z = z | (b << (31 - i)); 
                if ( (i+1) % 8 == 0) {
                    z = z >> ( (i + 1) * 3);
                    if (i < 31) {
                        printf("%u.", z);
                    }
                    else {
                        printf("%u\n", z); 
                        z = 0;
                    }
                }
            }
        }

            void TASK_5(int ip, int ip2, int MSK_2) {
                printf("-5 ");
                int b1, b2;
                unsigned int z1 = 0;
                unsigned int z2 = 0; 
                int k = 0; 
                int msc = masca(MSK_2);
                for (int i = 0; i <= 31; i++) {
                    b1 = (ip & (1 << (31 - i))) ? 1 : 0; 
                    b2 = (ip2 & (1 << (31 - i))) ? 1 : 0;
                    if (i > MSK_2) { 
                        b1 = 0;
                        b2 = 0; 
                    }
                    int y = (msc & (1 << (31 - i))) ? 1 : 0; 
                    b1 = b1 & y;
                    b2 = b2 & y; 
                    z1 = z1 | (b1 << (31 - i));
                    z2 = z2 | (b2 << (31 - i));
                    if ((i + 1) % 8 == 0) {
                        z1 = z1 >> ((i + 1) * 3);
                        z2 = z2 >> ((i + 1) * 3);
                        if (z1 == z2) {
                            k++;
                            z1 = 0; 
                            z2 = 0; 
                        } 
                    } 
                    if (k == 4) 
                        printf("DA\n"); 
                    else printf("NU\n"); 
                }

            void TASK_6(int MSK_1) { printf("-6 "); int i = 0; int k = 0; while ((MSK_1 & (1 << (31 - i))) && i <= 31) i++; for (int j = (i + 1); j <= 31; j++) { if ((MSK_1 & (1 << (31 - j)))) k++; } if (k != 0) printf("NU\n"); else printf("DA\n"); }

            void TASK_7(int MSK_1, int MSK_1a, int MSK_1b, int MSK_1c, int MSK_1d) { printf("-7 "); int i = 0; int k = 0; unsigned int z = 0; while ((MSK_1 & (1 << (31 - i))) && i <= 31) i++; for (int j = (i + 1); j <= 31; j++) { if ((MSK_1 & (1 << (31 - j)))) k++; } if (k != 0) { i = 0; while ((MSK_1 & (1 << (31 - i))) && i <= 31) i++; for (int j = (i + 1); j <= 31; j++) { MSK_1 = MSK_1 & ~(1 << (31 - j)); } for (int i = 0; i <= 31; ++i) { int y = (MSK_1 & (1 << (31 - i))) ? 1 : 0; z = z | (y << (31 - i)); if ((i + 1) % 8 == 0) { z = z >> ((i + 1) * 3); if (i < 31) printf("%u.", z); else printf("%u\n", z); z = 0; } } } else printf("%d.%d.%d.%d\n", MSK_1a, MSK_1b, MSK_1c, MSK_1d); }

            void TASK_8(int IP_1) { printf("-8 "); int i, b; for (i = sizeof(int) * 8 - 1; i >= 0; i--) { b = (IP_1 & (1 << i)) ? 1 : 0; printf("%d", b); if (i % 8 == 0 && i > 0) printf("."); if (i == 0) printf("\n"); } }

            void TASK_9(int IP_2, int N, int adrese_de_retea[][5]) { printf("-9 "); unsigned int adr; for (int i = 0; i < N; i++) { unsigned int masca_adresei = masca(adrese_de_retea[i][4]); adr = (adrese_de_retea[i][0] << 24) + (adrese_de_retea[i][1] << 16) + (adrese_de_retea[i][2] << 8) + adrese_de_retea[i][3]; unsigned int x = IP_2 & masca_adresei; unsigned int y = adr & masca_adresei; if (x == y) printf("%d ", i); } printf("\n"); }

            int main() {
                unsigned int nr_seturi_de_date; unsigned int MSK_1a, MSK_1b, MSK_1c, MSK_1d, MSK_1; unsigned int MSK_2; unsigned int IP_1a, IP_1b, IP_1c, IP_1d, IP_1; unsigned int IP_2a, IP_2b, IP_2c, IP_2d, IP_2; int N; int adrese_de_retea[1000][5]; //int adr1, adr2, adr3, adr4, msk_adr; scanf("%d", &nr_seturi_de_date); for (int i = 0; i < nr_seturi_de_date; i++) { scanf("%d.%d.%d.%d", &MSK_1a, &MSK_1b, &MSK_1c, &MSK_1d); scanf("%d", &MSK_2); scanf("%d.%d.%d.%d", &IP_1a, &IP_1b, &IP_1c, &IP_1d); scanf("%d.%d.%d.%d", &IP_2a, &IP_2b, &IP_2c, &IP_2d); scanf("%d", &N); for(int i=0;i<N;i++) { //scanf("%d.%d.%d.%d/%d", &adr1, &adr2, &adr3, &adr4, &msk_adr); scanf("%d.%d.%d.%d/%d", &adrese_de_retea[i][0], &adrese_de_retea[i][1], &adrese_de_retea[i][2], &adrese_de_retea[i][3], &adrese_de_retea[i][4]); } IP_1 = (IP_1a << 24) + (IP_1b << 16) + (IP_1c << 8) + IP_1d; IP_2 = (IP_2a << 24) + (IP_2b << 16) + (IP_2c << 8) + IP_2d; MSK_1 = (MSK_1a << 24) + (MSK_1b << 16) + (MSK_1c << 8) + MSK_1d; TASK_0(IP_1a, IP_1b, IP_1c, IP_1d, MSK_2); TASK_1(MSK_2); TASK_2(MSK_1a, MSK_1b, MSK_1c, MSK_1d); TASK_3(IP_1, MSK_2); TASK_4(IP_1, MSK_2); TASK_5(IP_1, IP_2, MSK_2); TASK_6(MSK_1); TASK_7(MSK_1, MSK_1a, MSK_1b, MSK_1c, MSK_1d); TASK_8(IP_1); TASK_9(IP_2, N, adrese_de_retea); } return 0; } }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
